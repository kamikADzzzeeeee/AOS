Action()
{

    
    
    lr_start_transaction("UC13_Play_Video");
    
    
    
    
    lr_start_transaction("Goto_HomePage");
    
    web_set_sockets_option("SSL_VERSION", "2&3");

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710384628.49.1.1710384932.0.0.0; DOMAIN={domain}");
    web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN={domain}");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710384628.44.1.1710384666.22.0.0; DOMAIN={domain}");
    web_add_cookie("_gid=GA1.1.1660421263.1710338911; DOMAIN={domain}");
    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={domain}");
    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710384628.49.1.1710384944.0.0.0; DOMAIN={domain}");
    web_add_cookie("dtCookie=6E15C7D49950E33A126B6888D2115A81||1; DOMAIN={domain}");
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
        EXTRARES, 
        "Url=/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer={protocol}://{host}/css/main.min.css", ENDITEM, 
        LAST);

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710384628.49.1.1710384945.0.0.0; DOMAIN={domain}");
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

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710384628.44.1.1710384946.60.0.0; DOMAIN={domain}");

    
    /*ѕроверка, что в ответе есть все категории электронных устройств*/
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

    /*ѕроверка, что в ответе есть json, который содержит ключи дл€ товара по спец. предложению на главной странице*/
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
    
    
    
    lr_think_time(2);
    
    

    lr_start_transaction("Goto_CategoryPage");

    /*ѕроверка перехода на страницу со случайно выбранной категорией товара*/
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t10.inf", 
        "Mode=HTML", 
        LAST);

    /*ѕроверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t11.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_CategoryPage",LR_AUTO);

    
    
    
    lr_think_time(2);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710384628.44.1.1710385004.2.0.0; DOMAIN={domain}");

    web_reg_find("Text=\"productId\":{productId}",LAST);
    web_reg_find("Text=\"categoryId\":{categoryId}",LAST);
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        LAST);

    /*ѕроверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        LAST);

    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "TargetFrame=", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t15.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_ProductPage",LR_AUTO);

    
    
    lr_think_time(2);
    
    

    
    lr_start_transaction("Play_Video");
    
    web_stream_open("ID={uniqNumber}", "URL={protocol}://{host}/css/videos/13543361_299823923688824_1410005144_n.mp4", "Protocol=HTTP", LAST);
    
    web_stream_play("ID={uniqNumber}", "PlayingDuration=15", LAST);
        
    web_stream_pause("ID={uniqNumber}","PausingDuration=3",LAST);
        
    web_stream_stop("ID={uniqNumber}",LAST);
    
    web_stream_close("ID={uniqNumber}", LAST);

    lr_end_transaction("Play_Video",LR_AUTO);

    
    
    
    lr_end_transaction("UC13_Play_Video",LR_AUTO);
    
    
    
    return 0;
}
