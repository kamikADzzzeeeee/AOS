Action()
{
    lr_start_transaction("UC11_ContactUsForm");
    
        
    lr_start_transaction("Goto_HomePage");

    web_set_sockets_option("SSL_VERSION", "2&3");
    
    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710367861.46.0.1710367861.0.0.0; DOMAIN={domain}");
    web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN={domain}");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710365959.41.1.1710367801.60.0.0; DOMAIN={domain}");
    web_add_cookie("_gid=GA1.1.1660421263.1710338911; DOMAIN={domain}");
    web_add_cookie("dtCookie=7B7F07685D2498626772A3F9E26BA73C||1; DOMAIN={domain}");
    web_add_header("Upgrade-Insecure-Requests", "1");

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

    /*Получение json'a из ответа*/
    web_set_max_html_param_len("9999999");
    web_reg_save_param("fullresponse", "LB=\r\n\r\n", "RB=", LAST);
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
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
        "Snapshot=t5.inf", 
        "Mode=HTML", 
        LAST);

    //Описание функции в библиотечном файле
    getRandomCategoryAndProduct(lr_eval_string("{fullresponse}"));
    
    /*Проверка, что в ответе есть json, который содержит ключи для товара по спец. предложению на главной странице*/
    web_reg_find("Text=\"promotionHeader\"",LAST);
    web_reg_find("Text=\"promotionSubHeader\"",LAST);
    
    web_url("dealOfTheDay", 
        "URL={protocol}://{host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t6.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_HomePage",LR_AUTO);


    lr_think_time(10);
    

    lr_start_transaction("Entry_DataForContactUsForm");
    
    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710367861.46.1.1710368125.0.0.0; DOMAIN={domain}");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710365959.41.1.1710368125.60.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_reg_find("Text=Thank you for contacting Advantage support.",LAST);
    
    web_custom_request("email", 
        "URL={protocol}://{host}/catalog/api/v1/support/contact_us/email", 
        "Method=POST", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t11.inf", 
        "Mode=HTML", 
        "EncType=application/json;charset=utf-8", 
        "Body={\"categoryId\":{categoryId},\"email\":\"{firstPartEmail}{secondPartEmail}\",\"productId\":{productId},\"text\":\"{textForm}\"}", 
        LAST);

    lr_end_transaction("Entry_DataForContactUsForm",LR_AUTO);

    
    lr_end_transaction("UC11_ContactUsForm",LR_AUTO);
    
    
    return 0;
}
