Action()
{
	//описание в файле user_lib.h
	readRowFromParameters(lr_eval_string("{RandomRowUserdata}"));

    lr_start_transaction("UC1_LoginAndLogout");

    
    
    lr_start_transaction("Goto_HomePage");
    
	    web_set_sockets_option("SSL_VERSION", "2&3");
	    web_set_user("{login}", "{password}", "{host}:80");
	    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={host}");
	    
		web_reg_find("Text=\"parameters\"",LAST);
		web_reg_find("Text=\"parameterName\"",LAST);
		
	    web_url("ALL", 
	        "URL={protocol}://{host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
	        "Resource=0", 
	        "RecContentType=application/json", 
	        "Referer={protocol}://{host}/", 
	        "Snapshot=t16.inf", 
	        "Mode=HTML", 
	        LAST);
	
	    web_add_cookie("_gid=GA1.1.567698320.1708799450; DOMAIN={host}");
	    web_add_cookie("_gat=1; DOMAIN={host}");
	    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708799449.1.0.1708799449.60.0.0; DOMAIN={host}");
	    web_add_header("Origin", "{protocol}://{host}");
	    web_add_header("SOAPAction","com.advantage.online.store.accountserviceGetAccountConfigurationRequest");
	    web_add_header("X-Requested-With", "XMLHttpRequest");
	    
	    
	    web_reg_find("Text=numberOfFailedLoginAttemptsBeforeBlocking",LAST);

	    web_custom_request("GetAccountConfigurationRequest", 
	        "URL={protocol}://{host}/accountservice/ws/GetAccountConfigurationRequest", 
	        "Method=POST", 
	        "Resource=0", 
	        "RecContentType=text/xml", 
	        "Referer={protocol}://{host}/", 
	        "Snapshot=t17.inf", 
	        "Mode=HTML", 
	        "EncType=text/xml; charset=UTF-8", 
	        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
	        LAST);

	    /*Проверка, что в ответе есть все категории электронных устройств*/
	    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
		web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
		web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
		web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
		web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);

	    web_url("categories", 
	        "URL={protocol}://{host}/catalog/api/v1/categories", 
	        "Resource=0", 
	        "RecContentType=application/json", 
	        "Referer={protocol}://{host}/", 
	        "Snapshot=t19.inf", 
	        "Mode=HTML", 
	        LAST);

		/*Проверка, что в ответе есть json, который содержит ключи для товара по спец. предложению на главной странице*/
		web_reg_find("Text=\"promotionHeader\"",LAST);
		web_reg_find("Text=\"promotionSubHeader\"",LAST);
	
	    web_url("dealOfTheDay", 
	        "URL={protocol}://{host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
	        "Resource=0", 
	        "RecContentType=application/json", 
	        "Referer={protocol}://{host}/", 
	        "Snapshot=t21.inf", 
	        "Mode=HTML", 
	        LAST);
		
		/*Проверка, что в ответе есть json, который содержит ключи популярных товаров на главной странице*/
		web_reg_find("Text=\"productName\"",LAST);
		web_reg_find("Text=\"description\"",LAST);
	
	    web_url("popularProducts", 
	        "URL={protocol}://{host}/app/tempFiles/popularProducts.json", 
	        "Resource=0", 
	        "RecContentType=application/json", 
	        "Referer={protocol}://{host}/", 
	        "Snapshot=t22.inf", 
	        "Mode=HTML", 
	        LAST);

    lr_end_transaction("Goto_HomePage",LR_AUTO);
    
    
    lr_think_time(3);

    
    lr_start_transaction("Entry_AuthenticateData");

	    web_add_header("Origin", "{protocol}://{host}");
	    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLoginRequest");
	    web_add_header("X-Requested-With", "XMLHttpRequest");
	
		/*
		Корреляция JWT токена
		Судя по тому из чего состоит токен, в нем нет метки времени (когда токен был создан),
		поэтому данный токен должен быть бессрочным (и не должен меняться), но на всякий случай была проведена его корреляция
		Original value='eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ3d3cuYWR2YW50YWdlb25saW5lc2hvcHBpbmcuY29tIiwidXNlcklkIjo3MDAzMDkyNTUsInN1YiI6ImRlbmlzIiwicm9sZSI6IlVTRVIifQ.9_4PE2fOaj5YUx0YENtgKJvbZDlRmZLKQOe7bvdWwJY' 
		Name ='AuthToken' Type ='Manual'*/
	    web_reg_save_param_xpath("ParamName=AuthToken","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:token[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
	    /*
	    Корреляция лоигна и пароля в кодировке base64
		Original value='ZGVuaXM6MTIzNG9P' 
		Name ='loginPasswordBase64' Type ='Manual'*/
		web_reg_save_param_xpath("ParamName=loginPasswordBase64","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:t_authorization[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
		/*
		Корреляция id пользователя
		Original value='700309255' 
		Name ='userId' Type ='Manual'*/
		web_reg_save_param_xpath("ParamName=userId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:userId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
		
		/*Проверка на успешную аутентификацию пользователя*/
		web_reg_find("Text=Login Successful",LAST);
		
		web_custom_request("AccountLoginRequest", 
		        "URL={protocol}://{host}/accountservice/ws/AccountLoginRequest", 
		        "Method=POST", 
		        "Resource=0", 
		        "RecContentType=text/xml", 
		        "Referer={protocol}://{host}/", 
		        "Snapshot=t24.inf", 
		        "Mode=HTML", 
		        "EncType=text/xml; charset=UTF-8", 
		        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		        LAST);
		
		web_set_sockets_option("INITIAL_AUTH", "BASIC");
		web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708799449.1.1.1708799496.13.0.0; DOMAIN={host}");
		web_add_cookie("userCookieZGVuaXMMTIzNGP=%7B%22name%22%3A%22{loginUser}%22%2C%22userPassword%22%3A%22{loginPassword}%22%2C%22email%22%3A%22%22%2C%22response%22%3A%7B%22success%22%3Atrue%2C%22userId%22%3A{userId}%2C%22reason%22%3A%22Login%20Successful%22%2C%22token%22%3A%22{AuthToken}%22%2C%22sessionId%22%3A%2218ddc6310d8%407E8218121F24%5Ei%25{userId}%22%2C%22t_authorization%22%3A%22{loginPasswordBase64}%22%2C%22accountType%22%3A20%7D%7D; DOMAIN={host}");
		web_add_cookie("lastLogin=userCookie{loginPasswordBase64}; DOMAIN={host}");
		
		/*Проверка, что в ответе в json'e есть ключ-значение для userId*/
		web_reg_find("Text=\"userId\":{userId}",LAST);
		
		web_url("carts", 
		    "URL={protocol}://{host}/order/api/v1/carts/{userId}", 
		    "Resource=0", 
		    "RecContentType=application/json", 
		    "Referer={protocol}://{host}/", 
		    "Snapshot=t25.inf", 
		    "Mode=HTML", 
		     LAST);

    lr_end_transaction("Entry_AuthenticateData",LR_AUTO);


	    
    lr_think_time(3);

    
    lr_start_transaction("Logout");

	    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708799448.1.1.1708799515.0.0.0; DOMAIN={host}");
	    web_add_header("Origin", "{protocol}://{host}");
	    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLogoutRequest");
	    web_add_header("X-Requested-With", "XMLHttpRequest");
	
	    /*"Проверка на успешный выход из системы"*/
		web_reg_find("Text=Logout Successful",LAST);
	    
	    web_custom_request("AccountLogoutRequest", 
	        "URL={protocol}://{host}/accountservice/ws/AccountLogoutRequest", 
	        "Method=POST", 
	        "Resource=0", 
	        "RecContentType=text/xml", 
	        "Referer={protocol}://{host}/", 
	        "Snapshot=t26.inf", 
	        "Mode=HTML", 
	        "EncType=text/xml; charset=UTF-8", 
	        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {loginPasswordBase64}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
	        LAST);

    lr_end_transaction("Logout",LR_AUTO);
    
    
    
    lr_end_transaction("UC1_LoginAndLogout",LR_AUTO);

    return 0;
}