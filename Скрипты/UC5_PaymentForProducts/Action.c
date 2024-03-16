Action()
{
    int i;
    int count;
    int countOrder;
    char countOrderStr[10];
    char countStr[5];
    double price;
    double priceShip = 0;
    double priceOrder = 0;
    char priceStr[30];
    int quantityInCart=0;
    
    readRowFromParameters(lr_eval_string("{randomRowFromFile}"));
    
    lr_start_transaction("UC5_PaymentForProducts");
    
    
    lr_start_transaction("Goto_HomePage");

    web_set_sockets_option("SSL_VERSION", "2&3");
    web_set_user("{login}", "{password}", "{domain}:80");
    web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN={domain}");

    web_reg_find("Text=\"parameters\"",LAST);
    web_reg_find("Text=\"parameterName\"",LAST);
    
    /*Correlation comment - Do not change!  Original value='112987298763' Name ='accountNumber' Type ='Manual'*/
    web_reg_save_param_ex("ParamName=accountNumber","LB=\\\"MCRecevingCard.AccountNumber\\\": ","RB=,",SEARCH_FILTERS,"Scope=Body",LAST);

    web_url("ALL", 
        "URL={protocol}://{host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
        "Resource=0", 
        "RecContentType=application/json", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t28.inf", 
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
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t29.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
        LAST);

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131380.60.0.0; DOMAIN={domain}");

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
        "Snapshot=t32.inf", 
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
        "Snapshot=t33.inf", 
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

        
    lr_think_time(2);
        
    
    lr_start_transaction("Entry_AuthenticateData");

    web_add_header("Origin", "{protocol}://{host}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLoginRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");
    
    /*Correlation comment - Do not change!  Original value='720899405' Name ='userId' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=userId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:userId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
    /*Correlation comment - Do not change!  Original value='QXJ0eW9tNDMwNjI6MTIzNG9P' Name ='loginPasswordBase64' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=loginPasswordBase64","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:t_authorization[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
    /*Correlation comment - Do not change!  Original value='18df02c0aec@7E821CE2B36^i%720899405' Name ='sessionId' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=sessionId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:sessionId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);

    /*Проверка на успешную аутентификацию пользователя*/
    web_reg_find("Text=Login Successful",LAST);
    
    web_custom_request("AccountLoginRequest", 
        "URL={protocol}://{host}/accountservice/ws/AccountLoginRequest", 
        "Method=POST", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t35.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
        LAST);

    web_set_sockets_option("INITIAL_AUTH", "BASIC");
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131435.5.0.0; DOMAIN={domain}");

    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    /*Correlation comment - Do not change!  Original value='F881A5F9138AC219B81DACCAAAB1F9F1' Name ='sessionId_1' Type ='Manual'*/
    web_reg_save_param_json("ParamName=sessionId_1","QueryString=$.sessionId",SEARCH_FILTERS,"Scope=Body",LAST);

    web_url("getCarts",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t36.inf",
        "Mode=HTML",
        LAST);
    
    lr_end_transaction("Entry_AuthenticateData",LR_AUTO);
    
    
    lr_think_time(2);
    
    
    
    lr_start_transaction("Goto_ShopCartPage");
    
    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonCartForDelete", "LB=\r\n\r\n", "RB=", LAST);
    
    web_url("cartsPage",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t38.inf",
        "Mode=HTML",
        LAST);
    
    
    //Получение кол-ва товаров в корзине
    count = 0;
    count = getQuantityProductInCart(lr_eval_string("{jsonCartForDelete}"));
    
    
    if (count>0) {
        itoa(count, countOrderStr, 10);
        lr_save_string(countOrderStr,"colProductInCart_ForOrder");
        
        
        getRandomProductInCartForDelete(lr_eval_string("{jsonCartForDelete}"));
        //получить стоимость всех товаров в корзине
        price = getAllPriceProductInCart(lr_eval_string("{jsonCartForDelete}"));
        //параметр - jsonForOrder
        getJsonForOrder(lr_eval_string("{jsonCartForDelete}"));
    }
    
    lr_end_transaction("Goto_ShopCartPage",LR_AUTO);
    
    
    
    lr_think_time(2);
    
    
    
    lr_start_transaction("Goto_ShippingAndPaymentDetailsPage");
    if (count>0) {
    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131452.60.0.0; DOMAIN={domain}");
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetAccountByIdRequest");
    web_add_auto_header("Origin", "{protocol}://{host}");
    web_add_auto_header("X-Requested-With", "XMLHttpRequest");

    /*Correlation comment - Do not change!  Original value='18df02c0aec@7E821CE2B36^i%720899405' Name ='sessionId' Type ='Manual'*/
    web_reg_save_param_xpath("ParamName=countryId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:GetAccountByIdResponse[1]/ns2:AccountResponse[1]/ns2:countryId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
    
    web_reg_find("Text=\<ns2:id\>{userId}\<\/ns2:id\>",LAST);
        
    web_custom_request("GetAccountByIdRequest",
        "URL={protocol}://{host}/accountservice/ws/GetAccountByIdRequest",
        "Method=POST",
        "Resource=0",
        "RecContentType=text/xml",
        "Referer={protocol}://{host}/",
        "Snapshot=t40.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {loginPasswordBase64}</base64Token></GetAccountByIdRequest></soap:Body></soap:Envelope>",
        LAST);

    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

    web_reg_find("Text=\<ns2:id\>{userId}\<\/ns2:id\>",LAST);
    
    web_custom_request("GetAccountByIdNewRequest",
        "URL={protocol}://{host}/accountservice/ws/GetAccountByIdNewRequest",
        "Method=POST",
        "Resource=0",
        "RecContentType=text/xml",
        "Referer={protocol}://{host}/",
        "Snapshot=t41.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {loginPasswordBase64}</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>",
        LAST);

    web_revert_auto_header("Origin");
    web_revert_auto_header("X-Requested-With");

    /*Проверка, что в ответе в json'e есть ключ-значение для userId*/
    web_reg_find("Text=\"userId\":{userId}",LAST);
    
    web_url("cartsInOrder",
        "URL={protocol}://{host}/order/api/v1/carts/{userId}",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t42.inf",
        "Mode=HTML",
        LAST);

    web_add_auto_header("Origin", "{protocol}://{host}");
    
    /*Получение json'a из ответа*/
    web_set_max_html_param_len("9999999");
    web_reg_save_param("jsonShipping", "LB=\r\n\r\n", "RB=", LAST);
    
    web_reg_find("Text=\"code\":\"Ok\"",LAST);
    
    web_custom_request("shippingcost",
        "URL={protocol}://{host}/order/api/v1/shippingcost/",
        "Method=POST",
        "Resource=0",
        "RecContentType=application/json",
        "Referer={protocol}://{host}/",
        "Snapshot=t43.inf",
        "Mode=HTML",
        "EncType=application/json;charset=utf-8",
        "Body={\"seaddress\":{\"addressLine1\":\"{adress}\",\"addressLine2\":\"\",\"city\":\"{city}\",\"country\":\"{shortCountry}\",\"postalCode\":{postalCode},\"state\":\"{stateProvinceRegion}\"},\"secustomerName\":\"{firstName} {lastName}\",\"secustomerPhone\":\"{phoneNumber}\",\"senumberOfProducts\":{colProductInCart_ForOrder},\"setransactionType\":\"SHIPPING_COST\",\"sessionId\":\"{sessionId_1}\"}",
        LAST);
        
    lr_eval_json ("Buffer={jsonShipping}", "JsonObject=jsonShipping");
    lr_json_get_values("JsonObject=jsonShipping","ValueParam=currency_Ship","QueryString=$.currency",LAST);
    lr_json_get_values("JsonObject=jsonShipping","ValueParam=amount_Ship","QueryString=$.amount",LAST);
    lr_json_get_values("JsonObject=jsonShipping","ValueParam=transactionDate_Ship","QueryString=$.transactionDate",LAST);
    
    //стоимость доставки
    priceShip = atof(lr_eval_string("{amount_Ship}"));
    //полная стоимость заказа
    priceOrder = priceShip + price;
    sprintf(priceStr, "%.2f", priceOrder); 
    
    for (i=0; i<strlen(priceStr); i++){
        if (priceStr[i]==',') {
            priceStr[i]='.';
        }
    }
    lr_save_string(priceStr, "price_ForOrder");
    
    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");
    web_add_header("X-Requested-With", "XMLHttpRequest");
    
    web_reg_find("Text=PaymentPreferences",LAST);

    web_custom_request("GetAccountPaymentPreferencesRequest",
        "URL={protocol}://{host}/accountservice/ws/GetAccountPaymentPreferencesRequest",
        "Method=POST",
        "Resource=0",
        "RecContentType=text/xml",
        "Referer={protocol}://{host}/",
        "Snapshot=t44.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {loginPasswordBase64}</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>",
        LAST);

    web_revert_auto_header("Origin");

    
    web_reg_find("Text=ORDER_PAYMENT",LAST);
        
    web_url("orderPayment-page.html", 
        "URL={protocol}://{host}/app/order/views/orderPayment-page.html", 
        "Resource=0", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t45.inf", 
        "Mode=HTML", 
        LAST);

    web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131485.27.0.0; DOMAIN={domain}");

    web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetCountriesRequest");
    web_add_auto_header("Origin", "{protocol}://{host}");
    web_add_auto_header("X-Requested-With", "XMLHttpRequest");
    
    web_reg_find("Text=\<\/ns2:Country\>",LAST);

    web_custom_request("GetCountriesRequest", 
        "URL={protocol}://{host}/accountservice/ws/GetCountriesRequest", 
        "Method=POST", 
        "Resource=0", 
        "RecContentType=text/xml", 
        "Referer={protocol}://{host}/", 
        "Snapshot=t46.inf", 
        "Mode=HTML", 
        "EncType=text/xml; charset=UTF-8", 
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
        LAST);
    }

    lr_end_transaction("Goto_ShippingAndPaymentDetailsPage",LR_AUTO);

    
    
    
    lr_think_time(2);
    
    
    
    /*    transaction Entry_PaymentData
     *    выбор между оплатой чеерз master credit или
     *    safepay 
     **/
    if (atoi(lr_eval_string("{randomPayment}")) == 1) {
    	/*master credit*/
        lr_start_transaction("Entry_PaymentData");
        if (count > 0) {
            web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAddMasterCreditMethodRequest");
        
            web_reg_find("Text=\<ns2:success\>true\<\/ns2:success\>",LAST);
            
            web_custom_request("AddMasterCreditMethodRequest", 
                "URL={protocol}://{host}/accountservice/ws/AddMasterCreditMethodRequest", 
                "Method=POST", 
                "Resource=0", 
                "RecContentType=text/xml", 
                "Referer={protocol}://{host}/", 
                "Snapshot=t22.inf", 
                "Mode=HTML", 
                "EncType=text/xml; charset=UTF-8", 
                "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AddMasterCreditMethodRequest xmlns=\"com.advantage.online.store.accountservice\"><cardNumber>4886{random1FourNumber_MC}{random2FourNumber_MC}{random3FourNumber_MC}</cardNumber><expirationDate>{randomMonth_MC}{randomYers_MC}</expirationDate><cvvNumber>{randomCVV_MC}</cvvNumber><customerName>{firstName}</customerName><accountId>{userId}</accountId><base64Token"
                ">Basic {loginPasswordBase64}=</base64Token></AddMasterCreditMethodRequest></soap:Body></soap:Envelope>", 
                LAST);
        
            web_revert_auto_header("X-Requested-With");
        
            web_reg_find("Text=order completed successfully",LAST);
            
            web_custom_request("488599908_5", 
                "URL={protocol}://{host}/order/api/v1/orders/users/{userId}", 
                "Method=POST", 
                "Resource=0", 
                "RecContentType=application/json", 
                "Referer={protocol}://{host}/", 
                "Snapshot=t23.inf", 
                "Mode=HTML", 
                "EncType=application/json", 
                "Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"{accountNumber}\",\"Transaction_Currency\":\"{currency_Ship}\",\"Transaction_CustomerPhone\":\"{phoneNumber}\",\"Transaction_MasterCredit_CVVNumber\":\"{randomCVV_MC}\",\"Transaction_MasterCredit_CardNumber\":\"4886{random1FourNumber_MC}{random2FourNumber_MC}{random3FourNumber_MC}\",\"Transaction_MasterCredit_CustomerName\":\"{firstName}\",\"Transaction_MasterCredit_ExpirationDate\":\"{randomMonth_MC}{randomYers_MC}\",\"Transaction_PaymentMethod\":\"MasterCredit\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"\",\""
                "Transaction_SafePay_UserName\":\"\",\"Transaction_TransactionDate\":\"{transactionDate_Ship}\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"{adress}\",\"Shipping_Address_City\":\"{city}\",\"Shipping_Address_CountryCode\":{countryId},\"Shipping_Address_CustomerName\":\"{firstName} {lastName}\",\"Shipping_Address_CustomerPhone\":\"{phoneNumber}\",\"Shipping_Address_PostalCode\":{postalCode},\"Shipping_Address_State\":\"{stateProvinceRegion}\",\"Shipping_Cost\":{price_ForOrder},\""
                "Shipping_NumberOfProducts\":{colProductInCart_ForOrder},\"Shipping_TrackingNumber\":0},\"purchasedProducts\":{jsonForOrder}}", 
                LAST);
        
            web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709144060.8.1.1709144680.60.0.0; DOMAIN={domain}");
        
            web_reg_find("Text=\"productsInCart\":[]",LAST);
            
            web_custom_request("488599908_6", 
                "URL={protocol}://{host}/order/api/v1/carts/{userId}", 
                "Method=DELETE", 
                "Resource=0", 
                "RecContentType=application/json", 
                "Referer={protocol}://{host}/", 
                "Snapshot=t24.inf", 
                "Mode=HTML", 
                LAST);
        
            
        }
    	lr_end_transaction("Entry_PaymentData",LR_AUTO);
    } else {
        lr_start_transaction("Entry_PaymentData");
        if (count > 0) {
            /*SafePay*/
            web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAddSafePayMethodRequest");
        
            web_reg_find("Text=\<ns2:success\>true\<\/ns2:success\>",LAST);
            
            web_custom_request("AddSafePayMethodRequest",
                "URL={protocol}://{host}/accountservice/ws/AddSafePayMethodRequest",
                "Method=POST",
                "Resource=0",
                "RecContentType=text/xml",
                "Referer={protocol}://{host}/",
                "Snapshot=t47.inf",
                "Mode=HTML",
                "EncType=text/xml; charset=UTF-8",
                "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AddSafePayMethodRequest xmlns=\"com.advantage.online.store.accountservice\"><safePayUsername>{firstName}_SP</safePayUsername><accountId>{userId}</accountId><safePayPassword>{password}</safePayPassword><base64Token>Basic {loginPasswordBase64}</base64Token></AddSafePayMethodRequest></soap:Body></soap:Envelope>",
                LAST);
            
            web_revert_auto_header("X-Requested-With");
        
            web_reg_find("Text=order completed successfully",LAST);
            
            web_custom_request("720899405_5",
                "URL={protocol}://{host}/order/api/v1/orders/users/{userId}",
                "Method=POST",
                "Resource=0",
                "RecContentType=application/json",
                "Referer={protocol}://{host}/",
                "Snapshot=t48.inf",
                "Mode=HTML",
                "EncType=application/json",
                "Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"{userId}\",\"Transaction_Currency\":\"{currency_Ship}\",\"Transaction_CustomerPhone\":\"{phoneNumber}\",\"Transaction_MasterCredit_CVVNumber\":\"\",\"Transaction_MasterCredit_CardNumber\":\"4886\",\"Transaction_MasterCredit_CustomerName\":\"\",\"Transaction_MasterCredit_ExpirationDate\":\"122027\",\"Transaction_PaymentMethod\":\"SafePay\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"{password}\",\"Transaction_SafePay_UserName\":\"{firstName}_SP\",\"Transaction_TransactionDate\":\"{transactionDate_Ship}\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"{adress}\",\"Shipping_Address_City\":\"{city}\",\"Shipping_Address_CountryCode\":{countryId},\"Shipping_Address_CustomerName\":\"{firstName} {lastName}\",\"Shipping_Address_CustomerPhone\":\"{phoneNumber}\",\"Shipping_Address_PostalCode\":{postalCode},\"Shipping_Address_State\":\"{stateProvinceRegion}\",\"Shipping_Cost\":{price_ForOrder},\"Shipping_NumberOfProducts\":{colProductInCart_ForOrder},\"Ship"
                "ping_TrackingNumber\":0},\"purchasedProducts\":{jsonForOrder}}",
                LAST);
        
            web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131547.60.0.0; DOMAIN={domain}");
        
            web_reg_find("Text=\"productsInCart\":[]",LAST);
            
            web_custom_request("720899405_6",
                "URL={protocol}://{host}/order/api/v1/carts/{userId}",
                "Method=DELETE",
                "Resource=0",
                "RecContentType=application/json",
                "Referer={protocol}://{host}/",
                "Snapshot=t49.inf",
                "Mode=HTML",
                LAST);
        }
        lr_end_transaction("Entry_PaymentData",LR_AUTO);
    }
    
    
    
    lr_think_time(2);
    
    
    
    
    lr_start_transaction("Logout");

    web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709130300.8.1.1709131564.0.0.0; DOMAIN={domain}");
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
        "Snapshot=t50.inf",
        "Mode=HTML",
        "EncType=text/xml; charset=UTF-8",
        "Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {loginPasswordBase64}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>",
        LAST);

    lr_end_transaction("Logout",LR_AUTO);

    
    
    
    
    
    
    lr_end_transaction("UC5_PaymentForProducts",LR_AUTO);

    return 0;
}
