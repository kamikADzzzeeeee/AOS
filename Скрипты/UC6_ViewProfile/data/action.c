Action()
{

	lr_start_transaction("UC6_ViewProfile");

	lr_start_transaction("Goto_HomePage");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_set_user("denis", 
		lr_unmask("65e712840be725e9827a"), 
		"54.157.232.206:80");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709640737.31.1.1709642171.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709641429.60.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_gid=GA1.1.2024659853.1709640738; DOMAIN=54.157.232.206");

	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=54.157.232.206");

	web_add_cookie("_gat=1; DOMAIN=54.157.232.206");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709640737.31.1.1709642211.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("dtCookie=AD1355583ACC90F8D902BB3BC6F4DCC7||1; DOMAIN=54.157.232.206");

	web_url("54.157.232.206", 
		"URL=http://54.157.232.206/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/services.properties", ENDITEM, 
		"Url=/app/tempFiles/popularProducts.json", ENDITEM, 
		LAST);

	web_custom_request("gts1c3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\xA2\\x99\\x17\\x88G$-\\xA6\\x12\\xA6u3a\\x076\\x84", 
		EXTRARES, 
		"Url=http://54.157.232.206/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	web_url("ALL", 
		"URL=http://54.157.232.206/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountConfigurationRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetAccountConfigurationRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountConfigurationRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_url("categories", 
		"URL=http://54.157.232.206/catalog/api/v1/categories", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("gts1c3_2", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\xCF\\xC5\\x1A+\\x86\\xD1\\xF3:\\x12\\x80aT\\x19\\xD1\\xAE\\x0E", 
		LAST);

	web_custom_request("gts1c3_3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\x91w\\x88J\\xAC\\x0E\\x9A\\x04\t\\xE7Ku\\x18\\x06\\xCB(", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642213.60.0.0; DOMAIN=54.157.232.206");

	web_url("search", 
		"URL=http://54.157.232.206/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642216.57.0.0; DOMAIN=54.157.232.206");

	web_url("home-page.html", 
		"URL=http://54.157.232.206/app/views/home-page.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t10.inf", 
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

	lr_think_time(16);

	web_custom_request("AccountLoginRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>1234oO</loginPassword><loginUser>denis</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642232.41.0.0; DOMAIN=54.157.232.206");

	web_url("700309255", 
		"URL=http://54.157.232.206/order/api/v1/carts/700309255", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	web_custom_request("700309255_2", 
		"URL=http://54.157.232.206/order/api/v1/carts/700309255", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"Body=[{\"hexColor\":\"55CDD5\",\"productId\":25,\"quantity\":1}]", 
		LAST);

	lr_end_transaction("Entry_AuthenticateData",LR_AUTO);

	lr_start_transaction("Goto_AccountPage");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709640737.31.1.1709642247.0.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(14);

	web_custom_request("GetAccountByIdNewRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709640737.31.1.1709642248.0.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAddressesByAccountIdRequest");

	web_custom_request("GetAddressesByAccountIdRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAddressesByAccountIdRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAddressesByAccountIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAddressesByAccountIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");

	web_custom_request("GetAccountPaymentPreferencesRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_url("myAccount-page.html", 
		"URL=http://54.157.232.206/app/account/views/myAccount-page.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Goto_AccountPage",LR_AUTO);

	lr_start_transaction("Goto_AccountDetailsPage");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642249.24.0.0; DOMAIN=54.157.232.206");

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(6);

	web_custom_request("GetAccountByIdNewRequest_2", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_url("accountDetails-page.html", 
		"URL=http://54.157.232.206/app/account/views/accountDetails-page.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642262.11.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetCountriesRequest");

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetCountriesRequest", 
		"URL=http://54.157.232.206/accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Goto_AccountDetailsPage",LR_AUTO);

	lr_start_transaction("Entry_AccountDetailsData");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountUpdateRequest");

	lr_think_time(20);

	web_custom_request("AccountUpdateRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountUpdateRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountUpdateRequest xmlns=\"com.advantage.online.store.accountservice\"><lastName>Yamshikov</lastName><firstName>Denis</firstName><accountId>700309255</accountId><countryId>Russia,ru</countryId><stateProvince>Bsh/Gr/fdd</stateProvince><cityName>Ufa</cityName><address"
		">Komsomolskay</address><zipcode>321</zipcode><phoneNumber>778545455</phoneNumber><email>test@test.ru</email><accountType>10</accountType><allowOffersPromotion>true</allowOffersPromotion><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></AccountUpdateRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_custom_request("GetAccountByIdNewRequest_3", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAddressesByAccountIdRequest");

	web_custom_request("GetAddressesByAccountIdRequest_2", 
		"URL=http://54.157.232.206/accountservice/ws/GetAddressesByAccountIdRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAddressesByAccountIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAddressesByAccountIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");

	web_custom_request("GetAccountPaymentPreferencesRequest_2", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Entry_AccountDetailsData",LR_AUTO);

	lr_start_transaction("Goto_AccountDetailsPage");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642294.60.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	lr_think_time(15);

	web_custom_request("GetAccountByIdNewRequest_4", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Goto_AccountDetailsPage",LR_AUTO);

	lr_start_transaction("Entry_NewPassword");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642310.44.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceChangePasswordRequest");

	lr_think_time(34);

	web_custom_request("ChangePasswordRequest", 
		"URL=http://54.157.232.206/accountservice/ws/ChangePasswordRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><ChangePasswordRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><newPassword>1234oO</newPassword><oldPassword>1234oO</oldPassword><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></ChangePasswordRequest></soap:Body></soap"
		":Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountUpdateRequest");

	web_custom_request("AccountUpdateRequest_2", 
		"URL=http://54.157.232.206/accountservice/ws/AccountUpdateRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountUpdateRequest xmlns=\"com.advantage.online.store.accountservice\"><lastName>Yamshikov</lastName><firstName>Denis</firstName><accountId>700309255</accountId><countryId>Russia,ru</countryId><stateProvince>Bsh/Gr/fdd</stateProvince><cityName>Ufa</cityName><address"
		">Komsomolskay</address><zipcode>321</zipcode><phoneNumber>778545455</phoneNumber><email>test@test.ru</email><accountType>10</accountType><allowOffersPromotion>true</allowOffersPromotion><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></AccountUpdateRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_custom_request("GetAccountByIdNewRequest_5", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAddressesByAccountIdRequest");

	web_custom_request("GetAddressesByAccountIdRequest_3", 
		"URL=http://54.157.232.206/accountservice/ws/GetAddressesByAccountIdRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAddressesByAccountIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAddressesByAccountIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");

	web_custom_request("GetAccountPaymentPreferencesRequest_3", 
		"URL=http://54.157.232.206/accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>700309255</accountId><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Entry_NewPassword",LR_AUTO);

	lr_start_transaction("Logout");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1709640737.31.1.1709642359.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1709640738.29.1.1709642346.8.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLogoutRequest");

	lr_think_time(5);

	web_custom_request("AccountLogoutRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>700309255</loginUser><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("UC6_ViewProfile",LR_AUTO);

	return 0;
}