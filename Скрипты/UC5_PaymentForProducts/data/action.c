Action()
{

	lr_start_transaction("UC5_PaymentForProducts");

	lr_start_transaction("Goto_HomePage");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_set_user("Artyom43062", 
		lr_unmask("65df4739c841e893f3b7"), 
		"54.157.232.206:80");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709130300.8.1.1709131315.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131317.7.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_gid=GA1.1.1202834963.1709130302; DOMAIN=54.157.232.206");

	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=54.157.232.206");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709130300.8.1.1709131379.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("dtCookie=37981F786730A0817CFB7DC7412003D4||1; DOMAIN=54.157.232.206");

	web_url("54.157.232.206", 
		"URL=http://54.157.232.206/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/services.properties", ENDITEM, 
		"Url=/app/tempFiles/popularProducts.json", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=2200", ENDITEM, 
		LAST);

	web_custom_request("gts1c3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x10}Y}\\x19\\xA4q\\xB9\\x88\\x10\\x9Bu\\x18\\xAAVH\\xE5", 
		EXTRARES, 
		"Url=http://54.157.232.206/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	web_url("ALL", 
		"URL=http://54.157.232.206/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_gat=1; DOMAIN=54.157.232.206");

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountConfigurationRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetAccountConfigurationRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountConfigurationRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_custom_request("gts1c3_2", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x10\\x1Bz\\xFEYV\\xC9p\\x9E\n\\xD2r\\xDB\\xF3\\x02M\\xF0", 
		LAST);

	web_custom_request("gts1c3_3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\xC3\\x89\\xD8^\\x94\\xB2Ki\t\\xEC*\\xA9le\\x8AZ", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131380.60.0.0; DOMAIN=54.157.232.206");

	web_url("categories", 
		"URL=http://54.157.232.206/catalog/api/v1/categories", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_url("search", 
		"URL=http://54.157.232.206/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131383.57.0.0; DOMAIN=54.157.232.206");

	web_url("home-page.html", 
		"URL=http://54.157.232.206/app/views/home-page.html", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	lr_end_transaction("Goto_HomePage",LR_AUTO);

	lr_start_transaction("Entry_AuthenticateData");

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(11);

	web_custom_request("AccountLoginRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>1234oO</loginPassword><loginUser>Artyom43062</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131435.5.0.0; DOMAIN=54.157.232.206");

	web_url("720899405", 
		"URL=http://54.157.232.206/order/api/v1/carts/720899405", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_custom_request("720899405_2", 
		"URL=http://54.157.232.206/order/api/v1/carts/720899405", 
		"Method=PUT", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"Body=[{\"hexColor\":\"545195\",\"productId\":5,\"quantity\":1},{\"hexColor\":\"FFFFFF\",\"productId\":22,\"quantity\":1},{\"hexColor\":\"FFFFFF\",\"productId\":19,\"quantity\":10},{\"hexColor\":\"414141\",\"productId\":21,\"quantity\":2},{\"hexColor\":\"414141\",\"productId\":15,\"quantity\":1}]", 
		LAST);

	lr_end_transaction("Entry_AuthenticateData",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("Goto_ShopCartPage");

	web_url("720899405_3", 
		"URL=http://54.157.232.206/order/api/v1/carts/720899405", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	web_url("shoppingCart.html", 
		"URL=http://54.157.232.206/app/views/shoppingCart.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Goto_ShopCartPage",LR_AUTO);

	lr_start_transaction("Goto_ShippingAndPaymentDetailsPage");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131452.60.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdRequest");

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(30);

	web_custom_request("GetAccountByIdRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>720899405</accountId><base64Token>Basic QXJ0eW9tNDMwNjI6MTIzNG9P</base64Token></GetAccountByIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_custom_request("GetAccountByIdNewRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>720899405</accountId><base64Token>Basic QXJ0eW9tNDMwNjI6MTIzNG9P</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_url("720899405_4", 
		"URL=http://54.157.232.206/order/api/v1/carts/720899405", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	web_custom_request("shippingcost", 
		"URL=http://54.157.232.206/order/api/v1/shippingcost/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=utf-8", 
		"Body={\"seaddress\":{\"addressLine1\":\"Novosibirsk_region,Kalinina,46\",\"addressLine2\":\"\",\"city\":\"Moscow\",\"country\":\"br\",\"postalCode\":439619581,\"state\":\"46/88/21\"},\"secustomerName\":\"Artyom Zhuravlev\",\"secustomerPhone\":\"87484741600\",\"senumberOfProducts\":15,\"setransactionType\":\"SHIPPING_COST\",\"sessionId\":\"F881A5F9138AC219B81DACCAAAB1F9F1\"}", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetAccountPaymentPreferencesRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>720899405</accountId><base64Token>Basic QXJ0eW9tNDMwNjI6MTIzNG9P</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");

	web_url("orderPayment-page.html", 
		"URL=http://54.157.232.206/app/order/views/orderPayment-page.html", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131485.27.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetCountriesRequest");

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetCountriesRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Goto_ShippingAndPaymentDetailsPage",LR_AUTO);

	lr_start_transaction("Entry_PaymentData");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAddSafePayMethodRequest");

	web_custom_request("AddSafePayMethodRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AddSafePayMethodRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AddSafePayMethodRequest xmlns=\"com.advantage.online.store.accountservice\"><safePayUsername>artyomSafePay</safePayUsername><accountId>720899405</accountId><safePayPassword>1234oO</safePayPassword><base64Token>Basic QXJ0eW9tNDMwNjI6MTIzNG9P</base64Token></"
		"AddSafePayMethodRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_custom_request("720899405_5", 
		"URL=http://54.157.232.206/order/api/v1/orders/users/720899405", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"843200971\",\"Transaction_Currency\":\"USD\",\"Transaction_CustomerPhone\":\"87484741600\",\"Transaction_MasterCredit_CVVNumber\":\"\",\"Transaction_MasterCredit_CardNumber\":\"4886\",\"Transaction_MasterCredit_CustomerName\":\"\",\"Transaction_MasterCredit_ExpirationDate\":\"122027\",\"Transaction_PaymentMethod\":\"SafePay\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"1234oO\",\""
		"Transaction_SafePay_UserName\":\"artyomSafePay\",\"Transaction_TransactionDate\":\"28022024\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"Novosibirsk_region,Kalinina,46\",\"Shipping_Address_City\":\"Moscow\",\"Shipping_Address_CountryCode\":58,\"Shipping_Address_CustomerName\":\"Artyom Zhuravlev\",\"Shipping_Address_CustomerPhone\":\"87484741600\",\"Shipping_Address_PostalCode\":439619581,\"Shipping_Address_State\":\"46/88/21\",\"Shipping_Cost\""
		":2784.95,\"Shipping_NumberOfProducts\":15,\"Shipping_TrackingNumber\":0},\"purchasedProducts\":[{\"hexColor\":\"545195\",\"productId\":5,\"quantity\":1,\"hasWarranty\":false},{\"hexColor\":\"FFFFFF\",\"productId\":22,\"quantity\":1,\"hasWarranty\":false},{\"hexColor\":\"FFFFFF\",\"productId\":19,\"quantity\":10,\"hasWarranty\":false},{\"hexColor\":\"414141\",\"productId\":21,\"quantity\":2,\"hasWarranty\":false},{\"hexColor\":\"414141\",\"productId\":15,\"quantity\":1,\"hasWarranty\":false}]}", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709130302.7.1.1709131547.60.0.0; DOMAIN=54.157.232.206");

	web_custom_request("720899405_6", 
		"URL=http://54.157.232.206/order/api/v1/carts/720899405", 
		"Method=DELETE", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Entry_PaymentData",LR_AUTO);

	lr_start_transaction("Logout");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709130300.8.1.1709131564.0.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLogoutRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(17);

	web_custom_request("AccountLogoutRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>720899405</loginUser><base64Token>Basic QXJ0eW9tNDMwNjI6MTIzNG9P</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("UC5_PaymentForProducts",LR_AUTO);

	return 0;
}