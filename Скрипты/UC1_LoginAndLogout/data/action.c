Action()
{

	lr_start_transaction("UC1_LoginAndLogout");

	lr_start_transaction("Goto_HomePage");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_set_user("denis", 
		lr_unmask("65da362bb097086ff3a5"), 
		"54.157.232.206:80");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708797412.2.1.1708799413.0.0.0; DOMAIN=54.157.232.206");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708799448.1.0.1708799448.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("dtCookie=4E450BE0DA67704EE0B03BBB72CB8D1F||1; DOMAIN=54.157.232.206");

	web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708799449.1.1.1708799470.39.0.0; DOMAIN=54.157.232.206");

	web_url("54.157.232.206", 
		"URL=http://54.157.232.206/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/services.properties", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_custom_request("gts1c3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x10}Y}\\x19\\xA4q\\xB9\\x88\\x10\\x9Bu\\x18\\xAAVH\\xE5", 
		EXTRARES, 
		"Url=http://54.157.232.206/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=54.157.232.206");

	web_url("ALL", 
		"URL=http://54.157.232.206/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_gid=GA1.1.567698320.1708799450; DOMAIN=54.157.232.206");

	web_add_cookie("_gat=1; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708799449.1.0.1708799449.60.0.0; DOMAIN=54.157.232.206");

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
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_think_time(9);

	web_custom_request("gts1c3_2", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\xC3\\x89\\xD8^\\x94\\xB2Ki\t\\xEC*\\xA9le\\x8AZ", 
		LAST);

	web_url("categories", 
		"URL=http://54.157.232.206/catalog/api/v1/categories", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	web_custom_request("gts1c3_3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x10\\x1Bz\\xFEYV\\xC9p\\x9E\n\\xD2r\\xDB\\xF3\\x02M\\xF0", 
		LAST);

	lr_think_time(4);

	web_url("search", 
		"URL=http://54.157.232.206/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_url("popularProducts.json", 
		"URL=http://54.157.232.206/app/tempFiles/popularProducts.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("home-page.html", 
		"URL=http://54.157.232.206/app/views/home-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t23.inf", 
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

	web_custom_request("AccountLoginRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>1234oO</loginPassword><loginUser>denis</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708799449.1.1.1708799496.13.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("userCookieZGVuaXMMTIzNGP="
		"%7B%22name%22%3A%22denis%22%2C%22userPassword%22%3A%221234oO%22%2C%22email%22%3A%22%22%2C%22response%22%3A%7B%22success%22%3Atrue%2C%22userId%22%3A700309255%2C%22reason%22%3A%22Login%20Successful%22%2C%22token%22%3A%22eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ3d3cuYWR2YW50YWdlb25saW5lc2hvcHBpbmcuY29tIiwidXNlcklkIjo3MDAzMDkyNTUsInN1YiI6ImRlbmlzIiwicm9sZSI6IlVTRVIifQ.9_4PE2fOaj5YUx0YENtgKJvbZDlRmZLKQOe7bvdWwJY%22%2C%22sessionId%22%3A%2218ddc6310d8%407E8218121F24%5Ei%25700309255%22%2C%22t_autho"
		"rization%22%3A%22ZGVuaXM6MTIzNG9P%22%2C%22accountType%22%3A20%7D%7D; DOMAIN=54.157.232.206");

	web_add_cookie("lastLogin=userCookieZGVuaXMMTIzNGP; DOMAIN=54.157.232.206");

	web_url("700309255", 
		"URL=http://54.157.232.206/order/api/v1/carts/700309255", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Entry_AuthenticateData",LR_AUTO);

	lr_start_transaction("Logout");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708799448.1.1.1708799515.0.0.0; DOMAIN=54.157.232.206");

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLogoutRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(25);

	web_custom_request("AccountLogoutRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>700309255</loginUser><base64Token>Basic ZGVuaXM6MTIzNG9P</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("UC1_LoginAndLogout",LR_AUTO);

	return 0;
}