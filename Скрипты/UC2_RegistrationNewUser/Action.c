Action()
{
	getFirstAndLastNameUser();
	getEmailUser();
	getAdressUser();
	getUsername();
	getStateProvinceRegion();	
	getPromotions();
	

	lr_start_transaction("UC2_RegistrationNewUser");

	
	
	lr_start_transaction("Goto_HomePage");
	
		web_set_sockets_option("SSL_VERSION", "2&3");
		
		web_set_user("{loginUsername}", "{standartPassword}", "{domain}:80");
	
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
	
	lr_think_time(5);
	
	lr_start_transaction("Goto_CreateAccountPage");
	
		web_reg_find("Text=\<h3 translate\=\"ACCOUNT_DETAILS\"\>\<\/h3\>",LAST);
		web_reg_find("Text=\<h3 translate\=\"PERSONAL_DETAILS\"\>\<\/h3\>",LAST);
	
		web_url("register-page", 
			"URL={protocol}://{host}/app/user/views/register-page.html", 
			"Resource=0", 
			"Referer={protocol}://{host}/", 
			"Snapshot=t10.inf", 
			"Mode=HTML", 
			LAST);
	
		web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708870410.3.1.1708871964.39.0.0; DOMAIN={domain}");
		web_add_header("SOAPAction", "com.advantage.online.store.accountserviceGetCountriesRequest");
		web_add_auto_header("Origin", "{protocol}://{host}");
		web_add_auto_header("X-Requested-With", "XMLHttpRequest");
	
		web_reg_save_param_regexp("ParamName=сountryId","RegExp=\<ns2:id\>(.*?)\<\/ns2:id\>","Ordinal={randomOrdionalCountry}",SEARCH_FILTERS,LAST);
		web_reg_save_param_regexp("ParamName=nameShortCountry","RegExp=\<ns2:isoName\>(.*?)\<\/ns2:isoName\>","Ordinal={randomOrdionalCountry}",SEARCH_FILTERS,LAST);
		
		web_reg_find("Text=GetCountriesResponse",LAST);
		web_reg_find("Text=Afganistan",LAST);
			
		web_custom_request("GetCountriesRequest", 
			"URL={protocol}://{host}/accountservice/ws/GetCountriesRequest", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/xml", 
			"Referer={protocol}://{host}/", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			"EncType=text/xml; charset=UTF-8", 
			"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
			LAST);

	lr_end_transaction("Goto_CreateAccountPage",LR_AUTO);
	
	
	lr_think_time(5);
	
	
	lr_start_transaction("Entry_RegistrationData");

		web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountCreateRequest");
		
		web_reg_find("Text=New user created successfully.",LAST);
		
		web_custom_request("AccountCreateRequest", 
			"URL={protocol}://{host}/accountservice/ws/AccountCreateRequest", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/xml", 
			"Referer={protocol}://{host}/", 
			"Snapshot=t12.inf", 
			"Mode=HTML", 
			"EncType=text/xml; charset=UTF-8", 
			"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountCreateRequest xmlns=\"com.advantage.online.store.accountservice\"><accountType>USER</accountType><address>{adress}</address><allowOffersPromotion>{promotions}</allowOffersPromotion><cityName>{city}</cityName><countryId>{nameCountry},{nameShortCountry}</countryId><email>{email}</email"
			"><firstName>{firstName}</firstName><lastName>{lastName}</lastName><loginName>{loginUsername}</loginName><password>{standartPassword}</password><phoneNumber>{randomPhoneNumber}</phoneNumber><stateProvince>{stateProvinceRegion}</stateProvince><zipcode>{randomPostalCode}</zipcode></AccountCreateRequest></soap:Body></soap:Envelope>", 
			LAST);
	
		web_add_cookie("_ga_56EMNRF2S2=GS1.1.1708870410.3.1.1708872068.60.0.0; DOMAIN={domain}");
		web_add_header("SOAPAction", "com.advantage.online.store.accountserviceAccountLoginRequest");
		
		/*Корреляция JWT токена
		Судя по тому из чего состоит токен, в нем нет метки времени (когда токен был создан),
		поэтому данный токен должен быть бессрочным (и не должен меняться), но на всякий случай была проведена его корреляция*/
		web_reg_save_param_xpath("ParamName=AuthToken","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:token[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
		
		/*Корреляция лоигна и пароля в кодировке base64*/
		web_reg_save_param_xpath("ParamName=loginPasswordBase64","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:t_authorization[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
		
		/*Корреляция id пользователя*/
		web_reg_save_param_xpath("ParamName=userId","QueryString=/SOAP-ENV:Envelope[1]/SOAP-ENV:Body[1]/ns2:AccountLoginResponse[1]/ns2:StatusMessage[1]/ns2:userId[1]/text()[1]","ReturnXml=No",SEARCH_FILTERS,"Scope=Body",LAST);
			
		web_reg_find("Text=Login Successful",LAST);
			
		web_custom_request("AccountLoginRequest", 
			"URL={protocol}://{host}/accountservice/ws/AccountLoginRequest", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/xml", 
			"Referer={protocol}://{host}/", 
			"Snapshot=t13.inf", 
			"Mode=HTML", 
			"EncType=text/xml; charset=UTF-8", 
			"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email>{email}</email><loginPassword>{standartPassword}</loginPassword><loginUser>{loginUsername}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
			LAST);
	
		web_set_sockets_option("INITIAL_AUTH", "BASIC");
		web_revert_auto_header("Origin");
		web_revert_auto_header("X-Requested-With");
	
		/*Проверка, что в ответе в json'e есть ключ-значение для userId*/
		web_reg_find("Text=\"userId\":{userId}",LAST);
			
		web_url("carts", 
			"URL={protocol}://{host}/order/api/v1/carts/{userId}", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={protocol}://{host}/", 
			"Snapshot=t14.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("Entry_RegistrationData",LR_AUTO);

	
	lr_think_time(5);
	
	
	lr_start_transaction("Logout");

		web_add_cookie("_ga_TBPYED8WSW=GS1.1.1708871854.4.1.1708872089.0.0.0; DOMAIN={domain}");
		web_add_header("Origin", "{protocol}://{host}");
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
			"Snapshot=t15.inf", 
			"Mode=HTML", 
			"EncType=text/xml; charset=UTF-8", 
			"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {loginPasswordBase64}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
			LAST);

	lr_end_transaction("Logout",LR_AUTO);
	
	
	

	lr_end_transaction("UC2_RegistrationNewUser",LR_AUTO);
	
	writeIntoFile();
	return 0;
}


//Генерация Имени и Фамилии для мужчин и женщин
void getFirstAndLastNameUser(){
	int random = atoi(lr_eval_string("{randomNumberForUserGender}"));
	char firstName[20];
	char lastName[20];
	
	char maleFirstName[20];
	char femaleFirstName[20];
	char fmlastName[20];
	char lastName_a[2];
	
	strcpy(femaleFirstName, lr_eval_string("{firstNameFemale}"));
	strcpy(maleFirstName,lr_eval_string("{firstNameMale}"));
	strcpy(fmlastName,lr_eval_string("{ffmmlastName}"));
	
	if(random!=0) {
		strcpy(firstName, femaleFirstName);
		strcpy(lastName_a, "a");
		strcpy(lastName, strcat(fmlastName, lastName_a));
	} else{
		strcpy(firstName, maleFirstName);
		strcpy(lastName, fmlastName);
	}
	
	lr_save_string(firstName, "firstName");
	lr_save_string(lastName, "lastName");
}

void getEmailUser(){
	char email[60];
	strcpy(email, lr_eval_string("{firstName}{lastName}{domainEmail}"));
	lr_save_string(email, "email");
}

void getAdressUser(){
	char adress[50];
	strcpy(adress, lr_eval_string("{state},{street},{randomHouseNumber}"));
	lr_save_string(adress, "adress");
}


void getUsername(){
	char loginUsername[20];
	strcpy(loginUsername, lr_eval_string("{firstName}{randomNumberForUsername}"));
	lr_save_string(loginUsername, "loginUsername");
}


void getStateProvinceRegion(){
	char stateProvinceRegion[15];
	strcpy(stateProvinceRegion, lr_eval_string("{randomHouseNumber}/{randomHouseNumber}/{randomHouseNumber}"));
	lr_save_string(stateProvinceRegion, "stateProvinceRegion");
}

void getPromotions(){
	int random = atoi(lr_eval_string("{randomPromotions}"));
	int procentTrue = atoi(lr_eval_string("{procentTruePromotions}"));
	int tfPromotions;
	char promotionsStr[8];
			
	if(random>(100-procentTrue)) {
		strcpy(promotionsStr, "true");
	} else{
		strcpy(promotionsStr, "false");
	}
	lr_save_string(promotionsStr, "promotions");
}


//Запись в файл зарегистрированных пользователей
void writeIntoFile(){
	FILE *fp = fopen("..\\Outputfile\\userdata.dat", "a");

	char result[600]="";
 	
	strcpy(result, lr_eval_string("{loginUsername}	{email}	{standartPassword}	{firstName}	{lastName}	{randomPhoneNumber}	{city}	{adress}	{stateProvinceRegion}	{randomPostalCode}	{userId}	{loginPasswordBase64}	{AuthToken}	{nameShortCountry}	{сountryId}\n"));
	lr_save_string(result, "result");
		
    if (fp != NULL){      
		fprintf (fp,result);
    	//fputs(result, fp);
        fclose(fp);
    } else{
        lr_error_message("Failed to open file for writing");
    }
    return;
}