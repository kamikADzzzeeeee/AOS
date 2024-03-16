#include <stdio.h>
#include <string.h>
#include <math.h>

void readRowFromParameters(char userdata[800]){
	//инициализация переменных
    char login[20];
    char email[40];
    char password[20];
    char firstName[20];
	char lastName[20]; 
	char phoneNumber[15];
	char city[20];
	char adress[50];
	char stateProvinceRegion[15];
	char postalCode[15];
	char userId[20];
	char plBase64[30];
	char authToken[300];
	char shortCountry[10];
	char countryId[5];
    char row[800] = "";
    //копируем в переменную row случайную строку из файла с данными пользователей
    
    strcpy(row, userdata);
    
    //парсим строку и заносим данные в переменные (разделитель - TAB)
    sscanf(row,"%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s	%s"
          	,login
          	,&(email)
    	    ,&(password)
    	    ,&(firstName)
    	    ,&(lastName)
    	    ,&(phoneNumber)
    	    ,&(city)
    	    ,&(adress)
    	    ,&(stateProvinceRegion)
    	    ,&(postalCode)
    	    ,&(userId)
    	    ,&(plBase64)
    	    ,&(authToken)
    	    ,&(shortCountry)
    	    ,&(countryId));
    
    //инициализируем переменные в параметрах скрипта
	lr_save_string(login, "login");
	lr_save_string(email, "email");
	lr_save_string(password, "password");
	lr_save_string(firstName, "firstName");
	lr_save_string(lastName, "lastName");
	lr_save_string(phoneNumber, "phoneNumber");
	lr_save_string(city, "city");
	lr_save_string(adress, "adress");
	lr_save_string(stateProvinceRegion, "stateProvinceRegion");
	lr_save_string(postalCode, "postalCode");
	lr_save_string(userId, "userId");
	lr_save_string(plBase64, "plBase64");
	lr_save_string(authToken, "authToken");
	lr_save_string(shortCountry, "shortCountry");
	lr_save_string(countryId, "countryId");
}


void getRandomCategoryAndProduct(char json[30000]){
	
	char colCategoriesStr[5];
	char colProductsOfCategoryStr[5];
	char randomCategoryStr[5];
	char randomProductStr[5];
	char categoryId[5];
	char categoryName[10];
	int colCategories;
	int colProductsOfCategory;
	char str1[15]="Active";
	char str2[15];
	
	lr_save_string(json, "json");
	
	/*Парсинг jsona со всеми товарами и выбор случайного товара и категории*/
	lr_eval_json ("Buffer={json}", "JsonObject=JSON_Param");
	
	colCategories = lr_json_find("JsonObject=JSON_Param","Value=.*","QueryString=$.[*].categoryId","SelectAll=Yes","UseRegExp=Yes",LAST);
	itoa(colCategories, colCategoriesStr, 10);
	lr_save_string(colCategoriesStr, "colCategories");
		
	while(strcmp (str1, str2)!=0){
		strcpy(str2, "");
		
		itoa(rand()%colCategories, randomCategoryStr, 10);
		lr_save_string(randomCategoryStr, "randomCategoryIdInJson");
		
		colProductsOfCategory = lr_json_find("JsonObject=JSON_Param","Value=.*","QueryString=$.[{randomCategoryIdInJson}].products[*].id","SelectAll=Yes","UseRegExp=Yes",LAST);
		itoa(colProductsOfCategory, colProductsOfCategoryStr, 10);
		lr_save_string(colProductsOfCategoryStr, "colProductsOfCategory");
		
		itoa(rand()%colProductsOfCategory, randomProductStr, 10);
		lr_save_string(randomProductStr, "randomProductIdInJson");

		lr_json_get_values("JsonObject=JSON_Param","ValueParam=categoryId","QueryString=$.[{randomCategoryIdInJson}].categoryId",LAST);
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=categoryName","QueryString=$.[{randomCategoryIdInJson}].categoryName",LAST);
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productId","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].id",LAST);
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productName","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].productName",LAST);
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productPrice","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].price",LAST);
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productDescription","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].description",LAST);
		lr_json_get_values("JsonObject=JSON_Param","ValueParam=productStatus","QueryString=$.[{randomCategoryIdInJson}].products[{randomProductIdInJson}].productStatus",LAST);	
		
		strcpy(str2, lr_eval_string("{productStatus}"));
	}
	/*----------------------------------------------------------*/
}

void productInCartAfterShop(char json[30000]) {
	int i;
    char iStr[5];
    int colProductInCart = 0;
    int result = 0;
	
	//Делаем json из ответа
    lr_eval_json ("Buffer={jsonCart}", "JsonObject=jsonCart");
    //получаем кол-во продуктов в корзине
    colProductInCart = lr_json_find("JsonObject=jsonCart","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes",LAST);
	//цикл по всем продуктам
    for (i = 0; i < colProductInCart; i++) {
		itoa(i, iStr, 10);
		lr_save_string(iStr, "productIdInCart");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=productId_after","QueryString=$.productsInCart[{productIdInCart}].productId",LAST);
		lr_json_get_values("JsonObject=jsonCart","ValueParam=productName_after","QueryString=$.productsInCart[{productIdInCart}].productName",LAST);
		lr_json_get_values("JsonObject=jsonCart","ValueParam=price_after","QueryString=$.productsInCart[{productIdInCart}].price",LAST);
		lr_json_get_values("JsonObject=jsonCart","ValueParam=colorInt_after","QueryString=$.productsInCart[{productIdInCart}].color.code",LAST);
		//сравниваем все продукты в корзине с товаром, который мы покупали
		if ((strcmp(lr_eval_string("{productId}"), lr_eval_string("{productId_after}"))==0)&&
		    (strcmp(lr_eval_string("{productName}"), lr_eval_string("{productName_after}"))==0)&&
		    (strcmp(lr_eval_string("{productPrice}"), lr_eval_string("{price_after}"))==0)&&
		    (strcmp(lr_eval_string("{randomColorProductInt}"), lr_eval_string("{colorInt_after}"))==0)) {
			result = 1;
			break;
		}
	}
	//если совпадений не было выдаем ошибку
	if (result == 0) {
    lr_error_message("Продукт не был добавлен в корзину");
    lr_abort();
    }
	
}



int getQuantityProductInCart(char json[30000]){
	int i;
	char iStr[5];
	int colProductInCart = 0;
	int quantity;
	char quantityStr[6];
	
	lr_save_string(json, "jsonCart");
	
	lr_eval_json ("Buffer={jsonCart}", "JsonObject=jsonCart");
	
	colProductInCart = lr_json_find("JsonObject=jsonCart","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes",LAST);
	quantity = 0;
	for (i = 0; i < colProductInCart; i++) {
		itoa(i, iStr, 10);
		lr_save_string(iStr, "productIdInCart");
		lr_json_get_values("JsonObject=jsonCart","ValueParam=quantity","QueryString=$.productsInCart[{productIdInCart}].quantity",LAST);
		quantity = atoi(lr_eval_string("{quantity}")) + quantity;
	}
	return quantity;
}


int getColProductInOrdersList(char json[30000]){
	int colProduct;
	char colProductStr[5];
	
	lr_save_string(json, "json");
	
	lr_eval_json("Buffer={json}", "JsonObject=JSON_AllOrders");
	
	colProduct = lr_json_find("JsonObject=JSON_AllOrders","Value=.*","QueryString=$.OrderLines[*].Quantity", "NotFound=Continue", "SelectAll=Yes","UseRegExp=Yes",LAST);
	itoa(colProduct, colProductStr, 10);
	lr_save_string(colProductStr, "colProduct");
	return colProduct;
}


void getRandomOrderNumber(char json[30000], int colProduct){
	char randomOrderNumberStr[5];
	
	lr_save_string(json, "json");
	lr_eval_json("Buffer={json}", "JsonObject=JSON_AllOrders");
	
	itoa(rand()%colProduct, randomOrderNumberStr, 10);
	lr_save_string(randomOrderNumberStr, "randomOrderId");
	lr_json_get_values("JsonObject=JSON_AllOrders","ValueParam=randomOrderNumber","QueryString=$.OrderLines[{randomOrderId}].OrderNumber",LAST);
}


double getAllPriceProductInCart(char json[30000]){
	int i;
	char iStr[5];
	int colProductInCart = 0;
	double price;
	char priceStr[6];
	
	lr_save_string(json, "jsonCartAllPrice");
	
	lr_eval_json ("Buffer={jsonCartAllPrice}", "JsonObject=jsonCartAllPrice");
	
	colProductInCart = lr_json_find("JsonObject=jsonCartAllPrice","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes",LAST);
	price = 0;
	for (i = 0; i < colProductInCart; i++) {
		itoa(i, iStr, 10);
		lr_save_string(iStr, "productIdInCart");
		lr_json_get_values("JsonObject=jsonCartAllPrice","ValueParam=price","QueryString=$.productsInCart[{productIdInCart}].price",LAST);
		lr_output_message("price preopr: %f", atof(lr_eval_string("{price}")));
		price = atof(lr_eval_string("{price}")) + price;
	}
	lr_output_message("price: %f", price);
	return price;
}


void getRandomColorProduct(char json[30000]){
	int colProductColors;
	char randomColorProductStr[10];	
	
	lr_save_string(json, "jsonProduct");
	
	lr_eval_json ("Buffer={jsonProduct}", "JsonObject=jsonProduct");
	colProductColors = lr_json_find("JsonObject=jsonProduct","Value=.*","QueryString=$.colors[*].code","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes",LAST);
	
	itoa(rand()%colProductColors, randomColorProductStr, 10);
	lr_save_string(randomColorProductStr, "randomColorProduct");
	lr_json_get_values("JsonObject=jsonProduct","ValueParam=randomColorProductInt","QueryString=$.colors[{randomColorProduct}].code",LAST);
	lr_json_get_values("JsonObject=jsonProduct","ValueParam=randomColorProduct","QueryString=$.colors[{randomColorProduct}].name",LAST);
}


void getRandomProductInCartForDelete(char json[30000]){
	
	int colProductInCart;
	char colProductInCartStr[5];
	
	lr_save_string(json, "jsonCartForDelete");
	lr_eval_json ("Buffer={jsonCartForDelete}", "JsonObject=jsonCartForDelete");
	colProductInCart = lr_json_find("JsonObject=jsonCartForDelete","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes",LAST);
	
	itoa(rand()%colProductInCart, colProductInCartStr, 10);
	lr_save_string(colProductInCartStr, "randomProductIdInJson");
	
	lr_json_get_values("JsonObject=jsonCartForDelete","ValueParam=productId_Delete","QueryString=$.productsInCart[{randomProductIdInJson}].productId",LAST);
	lr_json_get_values("JsonObject=jsonCartForDelete","ValueParam=productQuantity_Delete","QueryString=$.productsInCart[{randomProductIdInJson}].quantity",LAST);
	lr_json_get_values("JsonObject=jsonCartForDelete","ValueParam=productColorInt_Delete","QueryString=$.productsInCart[{randomProductIdInJson}].color.code",LAST);
	
}


//получилось
void rewriteColProductIntoFile(char username[30], char colQuantity[5]){
	FILE *fp; 
	FILE *fp1;
	char row[800];
    char login[30];
    char result[800];
	
	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==NULL) {
		
	}
	
	while ((fp1 = fopen("..\\Outputfile\\userdata1.dat", "a"))==NULL) {
		
	}

	lr_save_string(colQuantity, "quantityIn");

    while (fgets(row, 800, fp) != NULL) {
		sscanf(row,"%s	",login);

		if (strcmp (username, login)==0) {
			strcpy(result,"");
			strcpy(result, lr_eval_string("{login}	{email}	{password}	{firstName}	{lastName}	{phoneNumber}	{city}	{adress}	{stateProvinceRegion}	{postalCode}	{userId}	{plBase64}	{authToken}	{quantityIn}	{countOrder}	{inUse}	{shortCountry}	{country}\n"));
			fprintf(fp1,result);
		} else {
			fprintf(fp1,row); // запись в новый
		}
    	
    }
	
    fclose(fp);
    fclose(fp1);
	while (-1 == remove("..\\Outputfile\\userdata.dat"));
	while (-1 == rename("..\\Outputfile\\userdata1.dat", "..\\Outputfile\\userdata.dat"));
	
}

//получилось
void rewriteColProductAndOrderIntoFile(char username[30], char colOrder[10], char colQuantity[10]){
	FILE *fp; 
	FILE *fp1;
	char row[800];
    char login[30];
    char result[800];

	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==NULL) {
		
	}
	
	while ((fp1 = fopen("..\\Outputfile\\userdata1.dat", "a"))==NULL) {
		
	}

	lr_save_string(colOrder, "colOrderInOrder");
	lr_save_string(colQuantity, "quantityInOrder");
	
    while (fgets(row, 800, fp) != NULL) {
		sscanf(row,"%s	",login);

		if (strcmp (username, login)==0) {
			strcpy(result,"");
			strcpy(result, lr_eval_string("{login}	{email}	{password}	{firstName}	{lastName}	{phoneNumber}	{city}	{adress}	{stateProvinceRegion}	{postalCode}	{userId}	{plBase64}	{authToken}	{quantityInOrder}	{colOrderInOrder}	{inUse}	{shortCountry}	{country}\n"));
			fprintf(fp1,result);
		} else {
			fprintf(fp1,row); // запись в новый
		}
    	
    }
	
    fclose(fp);
    fclose(fp1);
	while (-1 == remove("..\\Outputfile\\userdata.dat"));
	while (-1 == rename("..\\Outputfile\\userdata1.dat", "..\\Outputfile\\userdata.dat"));
	
}



//получилось
void rewriteInUseOn(char username[30]){
	FILE *fp; 
	FILE *fp1;
	char row[800];
    char login[30];
    char result[800];

	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==NULL) {
		
	}
	
	while ((fp1 = fopen("..\\Outputfile\\userdata1.dat", "a"))==NULL) {
		
	}
	
	lr_save_string("1", "inUseOn");
	
    while (fgets(row, 800, fp) != NULL) {
		sscanf(row,"%s	",login);


		if (strcmp (username, login)==0) {
			strcpy(result,"");
			strcpy(result, lr_eval_string("{login}	{email}	{password}	{firstName}	{lastName}	{phoneNumber}	{city}	{adress}	{stateProvinceRegion}	{postalCode}	{userId}	{plBase64}	{authToken}	{quantityInCart}	{countOrder}	{inUseOn}	{shortCountry}	{country}\n"));
			fprintf(fp1,result);
		} else {
			fprintf(fp1,row); // запись в новый
		}
    	
    }
	
    fclose(fp);
    fclose(fp1);
	
	while (-1 == remove("..\\Outputfile\\userdata.dat"));
	while (-1 == rename("..\\Outputfile\\userdata1.dat", "..\\Outputfile\\userdata.dat"));
	
}









void getRowFromFileOnLogin(char username[30]) {
	FILE *fp; 
	char row[800];
    char login[30];
    char result[800];

	while ((fp = fopen("..\\Outputfile\\userdata.dat", "r"))==NULL) {}
	
    while (fgets(row, 800, fp) != NULL) {
		sscanf(row,"%s	",login);

		if (strcmp (username, login)==0) {
			break;
		}
    	
    }
	
    fclose(fp);
	lr_save_string(row, "RandomRowFromFile");
		
}


void getJsonForOrder(char json[10000]){
   int colProductInCart;
   char productIdStr[5];
   int productId = 0;
   char jsonForOrder[10000] = "";

	lr_save_string(json, "jsonCartForOrder");
    lr_eval_json("Buffer={jsonCartForOrder}", "JsonObject=jsonCartForOrder");
    colProductInCart = lr_json_find("JsonObject=jsonCartForOrder","Value=.*","QueryString=$.productsInCart[*].productId","NotFound=Continue","SelectAll=Yes","UseRegExp=Yes",LAST);
    
    strcat(jsonForOrder,"[");
    for (productId=0; productId < colProductInCart; productId++) {
    	itoa(productId, productIdStr, 10);
		lr_save_string(productIdStr, "productIdInJsonForOrder");
		
		lr_json_get_values("JsonObject=jsonCartForOrder","ValueParam=productId_Put","QueryString=$.productsInCart[{productIdInJsonForOrder}].productId",LAST);
		lr_json_get_values("JsonObject=jsonCartForOrder","ValueParam=productQuantity_Put","QueryString=$.productsInCart[{productIdInJsonForOrder}].quantity",LAST);
		lr_json_get_values("JsonObject=jsonCartForOrder","ValueParam=hexColor_Put","QueryString=$.productsInCart[{productIdInJsonForOrder}].color.code",LAST);
		
		strcat(jsonForOrder,"{\"hexColor\":");
		strcat(jsonForOrder,lr_eval_string("\"{hexColor_Put}\","));
		
		strcat(jsonForOrder,"\"productId\":");
		strcat(jsonForOrder,lr_eval_string("{productId_Put},"));
		
		strcat(jsonForOrder,"\"quantity\":");
		strcat(jsonForOrder,lr_eval_string("{productQuantity_Put}}"));
		
		if (productId != (colProductInCart - 1)) {
    		strcat(jsonForOrder,",");
    	}
    	//
    }
    strcat(jsonForOrder,"]");
    lr_save_string(jsonForOrder, "jsonForOrder");


}