Action()
{
     
    lr_start_transaction("UC12_ChatWebsocket");
    
    
    lr_start_transaction("Goto_HomePage");
    
    web_set_sockets_option("SSL_VERSION", "2&3");
    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709704703.33.1.1709709359.0.0.0; DOMAIN={domain}");
    web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN={domain}");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709704704.31.1.1709708811.56.0.0; DOMAIN={domain}");
    web_add_cookie("_gid=GA1.1.2024659853.1709640738; DOMAIN={domain}");
    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={domain}");
    web_add_cookie("dtCookie=6AB675624C78926DBC1A1553A90F7FD8||1; DOMAIN={domain}");
    web_add_header("Upgrade-Insecure-Requests", "1");

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

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709728780.32.0.1709728780.60.0.0; DOMAIN={domain}");

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
    
    lr_end_transaction("Goto_HomePage",LR_AUTO);
    

    lr_think_time(5);
    
    
    lr_start_transaction("Connect_Chat");

    web_add_header("Upgrade-Insecure-Requests", "1");

    web_set_max_html_param_len("9999999");
    web_reg_save_param("allpage", "LB=", "RB=\r\n\r\n", LAST);
    
    web_websocket_connect("ID={uniqNumber}", 
        "URI=ws://{host}/catalog/websocketserverendpoint", 
        "Origin={protocol}://{host}", 
        "OnOpenCB=OnOpenCB0", 
        "OnMessageCB=OnMessageCB0", 
        "OnErrorCB=OnErrorCB0", 
        "OnCloseCB=OnCloseCB0", 
        LAST);

    if(strstr(lr_eval_string("{allpage}"),"HTTP/1.1 101") == NULL) {
        lr_error_message("Ответ от сервера при подключении вебсокета отличается от 101");
        lr_abort();
    }
    
    lr_end_transaction("Connect_Chat",LR_AUTO);
    
    
    
    lr_think_time(5);
    
    //ReciveFromServer - находится в подключенном файле
    
    lr_start_transaction("Entry_DataForChat");
        
    web_websocket_send("ID={uniqNumber}", "Buffer=Hello", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"Hello, what's your name?") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    
    web_websocket_send("ID={uniqNumber}", "Buffer={userName}", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"Is that really your name?") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    
    web_websocket_send("ID={uniqNumber}", "Buffer=Yes", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"are you interested in a specific category of products?") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }

    
    web_websocket_send("ID={uniqNumber}", "Buffer=Yes", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"Good, which category?") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    
    web_websocket_send("ID={uniqNumber}", "Buffer={randomCategory}", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"are you interested in a specific product from") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    
    web_websocket_send("ID={uniqNumber}", "Buffer=Yes", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"Great, which product are you interested in?") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    
    web_websocket_send("ID={uniqNumber}", "Buffer=Any product", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"leave me you phone number or e-mail and a specialized support person will contact you") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    
    web_websocket_send("ID={uniqNumber}", "Buffer={randomPhoneNumber}", "IsBinary=0", LAST);
    lr_think_time(3);
    if(strstr(lr_eval_string("{ReciveFromServer}"),"Thank you for contacting Advantage support") == NULL) {
        lr_error_message("Подстрока не найдена в ответе от сервера");
        //lr_abort();
    }
    
    lr_end_transaction("Entry_DataForChat",LR_AUTO);
    
    
    lr_think_time(5);
    
    
    
    lr_start_transaction("Close_Chat");
    
    web_websocket_close("ID={uniqNumber}", "Code=1000", "Reason=OK", LAST);
    
    lr_end_transaction("Close_Chat",LR_AUTO);
    
    
    lr_end_transaction("UC12_ChatWebsocket",LR_AUTO);
    
    return 0;
}
