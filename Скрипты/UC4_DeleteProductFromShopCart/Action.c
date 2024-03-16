Action()
{
    int count;
    char countStr[6];
    int quantityInCart=0;
    
    readRowFromParameters(lr_eval_string("{randomRowFromFile}"));
    
    lr_start_transaction("UC4_DeleteProductFromShopCart");

    
    
    lr_start_transaction("Goto_HomePage");

    web_set_sockets_option("SSL_VERSION", "2&3");
    web_set_user("{login}", "{password}", "{domain}:80");
    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={domain}");
    
    web_reg_find("Text=\"parameters\"",LAST);
    web_reg_find("Text=\"parameterName\"",LAST);
    
    web_url("ALL", 
        "URL={protocol}://{host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t3.inf", 
        "Mode=HTML", 
        LAST);
    
    lr_output_message(">> Все настройки системы получены");
    
    web_add_cookie("_gat=1; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetAccountConfigurationRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");

    web_reg_find("Text=numberOfFailedLoginAttemptsBeforeBlocking",LAST);
    
    web_custom_request("GetAccountConfigurationRequest", 
        "URL={protocol}://{host}/accountservice/ws/GetAccountConfigurationRequest", 
        "Method=POST", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t4.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
        LAST);
    
    lr_output_message(">> Установленная конфигурация системы получена");

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.0.1708954185.60.0.0; DOMAIN={domain}");
    
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
        "Snapshot=t6.inf", 
        "Mode=HTML", 
        LAST);
    
    lr_output_message(">> Все категории товаров получены из каталога");
    
    /*Проверка, что в ответе есть json, который содержит ключи для товара по спец. предложению на главной странице*/
    web_reg_find("Text=\"promotionHeader\"",LAST);
    web_reg_find("Text=\"promotionSubHeader\"",LAST);
    
    web_url("dealOfTheDay", 
        "URL={protocol}://{host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t8.inf", 
        "Mode=HTML", 
        LAST);

    lr_output_message(">> Получен товар по спец. предложению на главной странице");
    
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
        
    lr_output_message(">> Получены популярные товары на главной странице");

    lr_end_transaction("Goto_HomePage",LR_AUTO);
    
    
    lr_think_time(5);
    

    lr_start_transaction("Entry_AuthenticateData");

    web_add_auto_header("Origin", "{protocol}://{host}");
    web_add_auto_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLoginRequest");
    web_add_auto_header("X-Requested-With", "XMLHttpRequest");
    
    /*Корреляция sessionId!  Original value='18de59c7b27@7E821AD1E36^i%322391106' Name ='sessionId' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=sessionId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:sessionId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
    /*Корреляция userId!  Original value='322391106' Name ='userId' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=userId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:userId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
    /*Корреляция base64!  Original value='QW5hc3Rhc2lhOTk0Nzc6MTIzNG9P' Name ='loginPasswordBase64' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=loginPasswordBase64","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:t_authorization[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
    
    /*Проверка на успешную аутентификацию пользователя*/
    web_reg_find("Text=Login Successful",LAST);
    
    web_custom_request("AccountLoginRequest", 
        "URL={protocol}://{host}/accountservice/ws/AccountLoginRequest", 
        "Method=POST", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t11.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
        LAST);
    
    lr_output_message(">> Вход в систему успешно выполнен");
    
    web_set_sockets_option("INITIAL_AUTH", "BASIC");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954254.60.0.0; DOMAIN={domain}");
    web_revert_auto_header("Origin");
    web_revert_auto_header("SOAPAction");
    web_revert_auto_header("X-Requested-With");
    
    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_url("cartsBefore",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t12.inf",
        "Mode=HTML",
        LAST);
    
    lr_output_message(">> Товары из корзины пользователя получены");

    lr_end_transaction("Entry_AuthenticateData",LR_AUTO);
    
    
    
    lr_think_time(5);
    
    
    
    lr_start_transaction("Goto_ShopCartPage");
    
    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCartForDelete", "LB=\r\n\r\n", "RB=", LAST);
    
    web_url("shopCart",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t21.inf",
        "Mode=HTML",
        LAST);
    
    //Получение кол-ва товаров в корзине
    count = 0;
    count = getQuantityProductInCart(lr_eval_string("{jsonCartForDelete}"));

    if (count>0) {
    	getRandomProductInCartForDelete(lr_eval_string("{jsonCartForDelete}"));
    }
    
    lr_end_transaction("Goto_ShopCartPage",LR_AUTO);

    
    
    lr_think_time(5);
    
    
    lr_start_transaction("Delete_ProductFromShopCart");

    if (count>0) {
    web_add_auto_header("Origin", "{protocol}://{host}");

    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", LAST);

    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    /*Проверка, что в json'e нет удаленного товара*/
    //web_reg_find("Text=\"productId\":{productId_Delete}", "Fail=Found",LAST);

    web_custom_request("deleteFromCart", 
        "URL={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId_Delete}/color/{productColorInt_Delete}", 
        "Method=DELETE", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t23.inf", 
        "Mode=HTML", 
        LAST);
    }

    lr_end_transaction("Delete_ProductFromShopCart",LR_AUTO);
    
    
    lr_think_time(5);

    
    lr_start_transaction("Logout");

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708954120.7.1.1708954391.0.0.0; DOMAIN={domain}");
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
        "Snapshot=t24.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {loginPasswordBase64}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>",
        LAST);

    lr_end_transaction("Logout",LR_AUTO);

    
    
    lr_end_transaction("UC4_DeleteProductFromShopCart",LR_AUTO);

    return 0;
}
