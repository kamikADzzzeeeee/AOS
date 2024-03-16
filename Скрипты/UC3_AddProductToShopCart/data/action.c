Action()
{

	lr_start_transaction("UC3_AddProductToShopCart");

	lr_start_transaction("Goto_HomePage");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_set_user("Anastasia99477", 
		lr_unmask("65dc932a5d9f928c9f9a"), 
		"54.157.232.206:80");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708954120.7.0.1708954120.0.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga=GA1.1.1055678014.1708799449; DOMAIN=54.157.232.206");

	web_add_cookie("_gid=GA1.1.567698320.1708799450; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708936304.5.1.1708936751.19.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=54.157.232.206");

	web_add_cookie("dtCookie=56D337289CF335124242F60D5E732874||1; DOMAIN=54.157.232.206");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954281.33.0.0; DOMAIN=54.157.232.206");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954353.60.0.0; DOMAIN=54.157.232.206");

	web_url("54.157.232.206", 
		"URL=http://54.157.232.206/", 
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
		"Url=/catalog/fetchImage?image_id=4200", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4700", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4600", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4300", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4400", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4500", ENDITEM, 
		"Url=/css/images/category_banner_4.png", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4100", ENDITEM, 
		"Url=/css/images/Master_credit.png", ENDITEM, 
		LAST);

	web_custom_request("gts1c3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x10}Y}\\x19\\xA4q\\xB9\\x88\\x10\\x9Bu\\x18\\xAAVH\\xE5", 
		EXTRARES, 
		"Url=http://54.157.232.206/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=http://54.157.232.206/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708954120.7.1.1708954184.0.0.0; DOMAIN=54.157.232.206");

	web_url("ALL", 
		"URL=http://54.157.232.206/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
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
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t4.inf", 
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
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x10\\x1Bz\\xFEYV\\xC9p\\x9E\n\\xD2r\\xDB\\xF3\\x02M\\xF0", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.0.1708954185.60.0.0; DOMAIN=54.157.232.206");

	web_url("categories", 
		"URL=http://54.157.232.206/catalog/api/v1/categories", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("gts1c3_3", 
		"URL=http://ocsp.pki.goog/gts1c3", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0R0P0N0L0J0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\xC7.y\\x8A\\xDD\\xFFa4\\xB3\\xBA\\xEDGB\\xB8\\xBB\\xC6\\xC0$\\x07c\\x04\\x14\\x8At\\x7F\\xAF\\x85\\xCD\\xEE\\x95\\xCD=\\x9C\\xD0\\xE2F\\x14\\xF3q5\\x1D'\\x02\\x11\\x00\\xC3\\x89\\xD8^\\x94\\xB2Ki\t\\xEC*\\xA9le\\x8AZ", 
		LAST);

	web_url("search", 
		"URL=http://54.157.232.206/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954187.58.0.0; DOMAIN=54.157.232.206");

	web_url("home-page.html", 
		"URL=http://54.157.232.206/app/views/home-page.html", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.woff", "Referer=http://54.157.232.206/css/main.min.css", ENDITEM, 
		LAST);

	lr_end_transaction("Goto_HomePage",LR_AUTO);

	lr_start_transaction("Entry_AuthenticateData");

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	web_add_auto_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(22);

	web_custom_request("AccountLoginRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>1234Oo</loginPassword><loginUser>Anastasia99477</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_think_time(7);

	web_custom_request("AccountLoginRequest_2", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>1234oO</loginPassword><loginUser>Anastasia99477</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954254.60.0.0; DOMAIN=54.157.232.206");

	web_revert_auto_header("Origin");

	web_revert_auto_header("SOAPAction");

	web_revert_auto_header("X-Requested-With");

	web_url("322391106", 
		"URL=http://54.157.232.206/order/api/v1/carts/322391106", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Entry_AuthenticateData",LR_AUTO);

	lr_think_time(8);

	lr_start_transaction("Goto_CategoryPage");

	web_url("products", 
		"URL=http://54.157.232.206/catalog/api/v1/categories/4/products", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("attributes", 
		"URL=http://54.157.232.206/catalog/api/v1/categories/attributes", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("category-page.html", 
		"URL=http://54.157.232.206/app/views/category-page.html", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Goto_CategoryPage",LR_AUTO);

	lr_start_transaction("Goto_ProductPage");

	web_url("20", 
		"URL=http://54.157.232.206/catalog/api/v1/products/20", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("all_data", 
		"URL=http://54.157.232.206/catalog/api/v1/categories/all_data", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("products_2", 
		"URL=http://54.157.232.206/catalog/api/v1/categories/4/products", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("product-page.html", 
		"URL=http://54.157.232.206/app/views/product-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Goto_ProductPage",LR_AUTO);

	lr_start_transaction("Add_ProductToShopCart");

	web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708954185.6.1.1708954305.9.0.0; DOMAIN=54.157.232.206");

	web_add_header("Origin", 
		"http://54.157.232.206");

	web_submit_data("414141", 
		"Action=http://54.157.232.206/order/api/v1/carts/322391106/product/20/color/414141?quantity=1", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=sessionId", "Value=A7CEA2BBF2A7F6FF61A8E36ABD90191A", ENDITEM, 
		LAST);

	lr_end_transaction("Add_ProductToShopCart",LR_AUTO);

	lr_start_transaction("Goto_ShopCartPage");

	web_url("322391106_2", 
		"URL=http://54.157.232.206/order/api/v1/carts/322391106", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_url("shoppingCart.html", 
		"URL=http://54.157.232.206/app/views/shoppingCart.html", 
		"Resource=0", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Goto_ShopCartPage",LR_AUTO);

	lr_start_transaction("Delete_ProductFromShopCart");

	web_add_auto_header("Origin", 
		"http://54.157.232.206");

	lr_think_time(5);

	web_custom_request("414141_2", 
		"URL=http://54.157.232.206/order/api/v1/carts/322391106/product/20/color/414141", 
		"Method=DELETE", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Delete_ProductFromShopCart",LR_AUTO);

	lr_start_transaction("Logout");

	web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708954120.7.1.1708954391.0.0.0; DOMAIN=54.157.232.206");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLogoutRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(19);

	web_custom_request("AccountLogoutRequest", 
		"URL=http://54.157.232.206/accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://54.157.232.206/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>322391106</loginUser><base64Token>Basic QW5hc3Rhc2lhOTk0Nzc6MTIzNG9P</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("UC3_AddProductToShopCart",LR_AUTO);

	return 0;
}