Action()
{

    
	readRowFromParameters(lr_eval_string("{randomRowFromFile}"));	
    
    
    lr_start_transaction("UC3_AddProductToShopCart");

    
    
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
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t6.inf", 
        "Mode=HTML", 
        LAST);
    
    lr_output_message(">> Все категории товаров получены из каталога");
    
    //Описание функции в библиотечном файле
    getRandomCategoryAndProduct(lr_eval_string("{fullresponse}"));
    
    lr_output_message(">> Успешный парсинг json'a");
    
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
    
    
    lr_think_time(1);
    

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

    
    

    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Goto_CategoryPage");
    
    /*Проверка перехода на страницу со случайно выбранной категорией товара*/
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);

    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        LAST);
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_CategoryPage",LR_AUTO);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");
    
    web_reg_find("Text=\"productId\":{productId}",LAST);
    web_reg_find("Text=\"categoryId\":{categoryId}",LAST);
    web_reg_find("Text=\"productName\":\"{productName}\"",LAST);
    web_reg_find("Text=\"price\":{productPrice}",LAST);
    
    /*Получение json'a из ответа*/
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonProduct", "LB=\r\n\r\n", "RB=", LAST);
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t16.inf", 
        "Mode=HTML", 
        LAST);
    
    getRandomColorProduct(lr_eval_string("{jsonProduct}"));
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t17.inf", 
        "Mode=HTML", 
        LAST);
    
    web_reg_find("Text=\"productName\":\"{productName}\"",LAST);
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t18.inf", 
        "Mode=HTML", 
        LAST);
    
    web_reg_find("Text=image section",LAST);
    
    web_url("product-page", 
        "URL={protocol}://{host}/app/views/product-page.html", 
        "Resource=0", 
        "RecContentType=text/html", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t19.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_ProductPage",LR_AUTO);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Add_ProductToShopCart");
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", LAST);
    
    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_submit_data("cartsAfter",
        "Action={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId}/color/{randomColorProductInt}?quantity={randomQuantity}",
        "Method=POST",
        "EncType=",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t20.inf",
        "Mode=HTML",
        ITEMDATA,
        "Name=sessionId", "Value={sessionId}", ENDITEM,
        LAST);
    
    productInCartAfterShop(lr_eval_string("{jsonCart}"));
    
    lr_end_transaction("Add_ProductToShopCart",LR_AUTO);
    
    
    
    
    lr_think_time(1);
    
    
    
    
    
    /*---------2*/
    
    
    
    
    
    
	lr_start_transaction("Goto_CategoryPage");
    
    /*Проверка перехода на страницу со случайно выбранной категорией товара*/
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);

    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        LAST);
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_CategoryPage",LR_AUTO);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");
    
    web_reg_find("Text=\"productId\":{productId}",LAST);
    web_reg_find("Text=\"categoryId\":{categoryId}",LAST);
    web_reg_find("Text=\"productName\":\"{productName}\"",LAST);
    web_reg_find("Text=\"price\":{productPrice}",LAST);
    
    /*Получение json'a из ответа*/
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonProduct", "LB=\r\n\r\n", "RB=", LAST);
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t16.inf", 
        "Mode=HTML", 
        LAST);
    
    getRandomColorProduct(lr_eval_string("{jsonProduct}"));
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t17.inf", 
        "Mode=HTML", 
        LAST);
    
    web_reg_find("Text=\"productName\":\"{productName}\"",LAST);
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t18.inf", 
        "Mode=HTML", 
        LAST);
    
    web_reg_find("Text=image section",LAST);
    
    web_url("product-page", 
        "URL={protocol}://{host}/app/views/product-page.html", 
        "Resource=0", 
        "RecContentType=text/html", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t19.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_ProductPage",LR_AUTO);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Add_ProductToShopCart");
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", LAST);
    
    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_submit_data("cartsAfter",
        "Action={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId}/color/{randomColorProductInt}?quantity={randomQuantity}",
        "Method=POST",
        "EncType=",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t20.inf",
        "Mode=HTML",
        ITEMDATA,
        "Name=sessionId", "Value={sessionId}", ENDITEM,
        LAST);
    
    productInCartAfterShop(lr_eval_string("{jsonCart}"));
    
    lr_end_transaction("Add_ProductToShopCart",LR_AUTO);
    
    
    
    
    lr_think_time(1);
    
    
    
    /*----*/
    
    
    
    
    
    
    
    
    
    
	/*---------3*/
    
    
    
    
    
    
	lr_start_transaction("Goto_CategoryPage");
    
    /*Проверка перехода на страницу со случайно выбранной категорией товара*/
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);

    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t13.inf", 
        "Mode=HTML", 
        LAST);
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("attributes", 
        "URL={protocol}://{host}/catalog/api/v1/categories/attributes", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t14.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_CategoryPage",LR_AUTO);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    
    lr_start_transaction("Goto_ProductPage");
    
    web_reg_find("Text=\"productId\":{productId}",LAST);
    web_reg_find("Text=\"categoryId\":{categoryId}",LAST);
    web_reg_find("Text=\"productName\":\"{productName}\"",LAST);
    web_reg_find("Text=\"price\":{productPrice}",LAST);
    
    /*Получение json'a из ответа*/
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonProduct", "LB=\r\n\r\n", "RB=", LAST);
    
    web_url("getProductOnId", 
        "URL={protocol}://{host}/catalog/api/v1/products/{productId}", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t16.inf", 
        "Mode=HTML", 
        LAST);
    
    getRandomColorProduct(lr_eval_string("{jsonProduct}"));
    
    /*Проверка, что в ответе есть все категории электронных устройств*/
    web_reg_find("Text=\"categoryName\":\"LAPTOPS\"", LAST);
    web_reg_find("Text=\"categoryName\":\"HEADPHONES\"",LAST);
    web_reg_find("Text=\"categoryName\":\"TABLETS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"SPEAKERS\"",LAST);
    web_reg_find("Text=\"categoryName\":\"MICE\"",LAST);
    
    web_url("all_data", 
        "URL={protocol}://{host}/catalog/api/v1/categories/all_data", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t17.inf", 
        "Mode=HTML", 
        LAST);
    
    web_reg_find("Text=\"productName\":\"{productName}\"",LAST);
    web_reg_find("Text=\"categoryName\":\"{categoryName}\"",LAST);
    
    web_url("products", 
        "URL={protocol}://{host}/catalog/api/v1/categories/{categoryId}/products", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t18.inf", 
        "Mode=HTML", 
        LAST);
    
    web_reg_find("Text=image section",LAST);
    
    web_url("product-page", 
        "URL={protocol}://{host}/app/views/product-page.html", 
        "Resource=0", 
        "RecContentType=text/html", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t19.inf", 
        "Mode=HTML", 
        LAST);

    lr_end_transaction("Goto_ProductPage",LR_AUTO);
    
    
    
    
    
    lr_think_time(1);
    
    
    
    

    lr_start_transaction("Add_ProductToShopCart");
        
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN={domain}");
    web_add_header("Origin", "{protocol}://{host}");
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCart", "LB=\r\n\r\n", "RB=", LAST);
    
    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_submit_data("cartsAfter",
        "Action={protocol}://{host}/order/api/v1/carts/{userId}/product/{productId}/color/{randomColorProductInt}?quantity={randomQuantity}",
        "Method=POST",
        "EncType=",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t20.inf",
        "Mode=HTML",
        ITEMDATA,
        "Name=sessionId", "Value={sessionId}", ENDITEM,
        LAST);
    
    productInCartAfterShop(lr_eval_string("{jsonCart}"));
    
    lr_end_transaction("Add_ProductToShopCart",LR_AUTO);
    
    
    
    
    lr_think_time(1);
    
    
    
    /*----*/
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

    
    
    lr_end_transaction("UC3_AddProductToShopCart",LR_AUTO);

    return 0;
}