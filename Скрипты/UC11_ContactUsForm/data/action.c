Action()
{

	lr_start_transaction("Goto_HomePage");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710367861.46.0.1710367861.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710365959.41.1.1710367801.60.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_gid=GA1.1.1660421263.1710338911; DOMAIN=54.157.232.206");

	web_add_cookie("dtCookie=7B7F07685D2498626772A3F9E26BA73C||1; DOMAIN=54.157.232.206");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("54.157.232.206", 
		"URL=http://54.157.232.206/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/vendor/requirejs/require.js", ENDITEM, 
		"Url=/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=/main.min.js", ENDITEM, 
		"Url=/services.properties", ENDITEM, 
		"Url=/app/tempFiles/popularProducts.json", ENDITEM, 
		LAST);

	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=54.157.232.206");

	web_custom_request("gts1c3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\xA2\\x99\\x17\\x88G$-\\xA6\\x12\\xA6u3a\\x076\\x84", 
		EXTRARES, 
		"Url=http://54.157.232.206/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	web_url("ALL", 
		"URL=http://54.157.232.206/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t3.inf", 
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
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t4.inf", 
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
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("search", 
		"URL=http://54.157.232.206/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("home-page.html", 
		"URL=http://54.157.232.206/app/views/home-page.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	lr_end_transaction("Goto_HomePage",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("Entry_DataForContactUsForm");

	web_url("products", 
		"URL=http://54.157.232.206/catalog/api/v1/categories/1/products", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("gts1c3_2", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t9.inf", 
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
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\x91w\\x88J\\xAC\\x0E\\x9A\\x04\t\\xE7Ku\\x18\\x06\\xCB(", 
		LAST);

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1710367861.46.1.1710368125.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1710365959.41.1.1710368125.60.0.0; DOMAIN=54.157.232.206");

	web_add_header("Origin", 
		"http://54.157.232.206");

	lr_think_time(16);

	web_custom_request("email", 
		"URL=http://54.157.232.206/catalog/api/v1/support/contact_us/email", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=utf-8", 
		"Body={\"categoryId\":1,\"email\":\"test@test.ru\",\"productId\":3,\"text\":\"hello it is test\"}", 
		LAST);

	lr_end_transaction("Entry_DataForContactUsForm",LR_AUTO);

	return 0;
}