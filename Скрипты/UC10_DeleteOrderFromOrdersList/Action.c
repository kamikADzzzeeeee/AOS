Action()
{
    int colProduct;

    readRowFromParameters(lr_eval_string("{randomRowFromFile}"));
    
    
    lr_start_transaction("UC10_DeleteOrderFromOrdersList");

    
    
    lr_start_transaction("Goto_HomePage");

    web_set_sockets_option("SSL_VERSION", "2&3");

    web_set_user("{login}", "{password}", "{domain}:80");
    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710338910.42.1.1710339580.0.0.0; DOMAIN={domain}");
    web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN={domain}");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710338911.38.1.1710338928.43.0.0; DOMAIN={domain}");
    web_add_cookie("_gid=GA1.1.1660421263.1710338911; DOMAIN={domain}");
    web_add_header("Upgrade-Insecure-Requests", "1");
    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710338910.42.1.1710339621.0.0.0; DOMAIN={domain}");
    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={domain}");

    web_reg_find("Text=\"parameters\"",LAST);
    web_reg_find("Text=\"parameterName\"",LAST);
    
    web_url("ALL", 
        "URL={protocol}://{host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t3.inf", 
        "Mode=HTML", 
        LAST);

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710338911.38.1.1710339634.60.0.0; DOMAIN={domain}");
    web_add_cookie("_gat=1; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetAccountConfigurationRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");

    web_reg_find("Text=numberOfFailedLoginAttemptsBeforeBlocking",LAST);
    
    web_custom_request("GetAccountConfigurationRequest", 
        "URL={protocol}://{host}/accountservice/ws/GetAccountConfigurationRequest", 
        "Method=POST", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t4.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
        LAST);

    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("categories", 
        "URL={protocol}://{host}/catalog/api/v1/categories", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t7.inf", 
        "Mode=HTML", 
        LAST);

    /*Проверка, что в ответе есть json, который содержит ключи для товара по спец. предложению на главной странице*/
    web_reg_find("Text=\"promotionHeader\"",LAST);
    web_reg_find("Text=\"promotionSubHeader\"",LAST);
    
    web_url("dealOfTheDay", 
        "URL={protocol}://{host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t8.inf", 
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

    
    lr_think_time(5);
    
    
    lr_start_transaction("Entry_AuthenticateData");

    web_add_header("Origin", "{protocol}://{host}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLoginRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");

    /*Проверка на успешную аутентификацию пользователя*/
    web_reg_find("Text=Login Successful",LAST);
    
    /*Correlation comment - Do not change!  Original value='700309255' Name ='userId' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=userId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:userId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);

    /*Correlation comment - Do not change!  Original value='ZGVuaXM6MTIzNG9P' Name ='lpBase64' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=lpBase64","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:t_authorization[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);

    web_custom_request("AccountLoginRequest", 
        "URL={protocol}://{host}/accountservice/ws/AccountLoginRequest", 
        "Method=POST", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t10.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
        LAST);

    web_set_sockets_option("INITIAL_AUTH", "BASIC");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710338911.38.1.1710339681.13.0.0; DOMAIN={domain}");

    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);

    web_url("carts",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "TargetFrame=",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t11.inf",
        "Mode=HTML",
        LAST);

    lr_end_transaction("Entry_AuthenticateData",LR_AUTO);
    
    
    lr_think_time(5);
    

    lr_start_transaction("Goto_OrderPage");

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710338910.42.1.1710339698.0.0.0; DOMAIN={domain}");
    
    /*Проверка, что в ответе в есть ключ UserId*/
    web_reg_find("Text=UserId",LAST);
    
    /*Получение json'a из ответа*/
    web_set_max_html_param_len("9999999");
    web_reg_save_param("allOrders", "LB=\r\n\r\n", "RB=", LAST);
    
    web_url("700309255_3",
        "URL={protocol}://{host}/order/api/v1/orders/history/lines/users/{userId}",
        "TargetFrame=",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t13.inf",
        "Mode=HTML",
        LAST);

    colProduct = getColProductInOrdersList(lr_eval_string("{allOrders}"));
    
    lr_end_transaction("Goto_OrderPage",LR_AUTO);
    
    

    lr_think_time(5);
    
    

    lr_start_transaction("Delete_OrderFromOrdersList");

    if (colProduct>0) {
        
    getRandomOrderNumber(lr_eval_string("{allOrders}"), colProduct);
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710338911.38.1.1710339700.60.0.0; DOMAIN={domain}");
    web_add_auto_header("Origin", "{protocol}://{host}");
    
    /*Проверка что в ответе отсутствует удаленный заказ*/
    web_reg_find("Text=\"OrderNumber\":{randomOrderNumber}", "Fail=Found", LAST);
    
    web_custom_request("deleteRandomOrder",
        "URL={protocol}://{host}/order/api/v1/orders/history/users/{userId}/{randomOrderNumber}",
        "Method=DELETE",
        "TargetFrame=",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t15.inf",
        "Mode=HTML",
        LAST);
    
    }

    lr_end_transaction("Delete_OrderFromOrdersList",LR_AUTO);

    
    lr_think_time(5);
    
    
    lr_start_transaction("Logout");

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710338910.42.1.1710339750.0.0.0; DOMAIN={domain}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLogoutRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");

    /*"Проверка на успешный выход из системы"*/
    web_reg_find("Text=Logout Successful",LAST);
    
    web_custom_request("AccountLogoutRequest",
        "URL={protocol}://{host}/accountservice/ws/AccountLogoutRequest",
        "Method=POST",
        "TargetFrame=",
        "Resource=0",
        "RecContentType=text/xml",
        "Referer={protocol}://{host}/",
        "Snapshot=t16.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {lpBase64}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>",
        LAST);

    lr_end_transaction("Logout",LR_AUTO);
    
    

    lr_end_transaction("UC10_DeleteOrderFromOrdersList",LR_AUTO);

    return 0;
}
