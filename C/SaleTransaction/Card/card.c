#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	printf("Enter CardHolderName : ");
    gets((*cardData).cardHolderName);
   
   //length of string 
    uint8_t cardHolderNameSize;
    for(uint8_t i = 0 ; i < sizeof((*cardData).cardHolderName); i++)
		if((*cardData).cardHolderName[i] =='\0') 
		{
			cardHolderNameSize = i;
			break;
		}

    if(cardHolderNameSize == 0 || cardHolderNameSize < 20 || cardHolderNameSize > 24) //NULL, <20 , >24
        return WRONG_NAME;
    else
        return OK;
}
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
	printf("Enter Card Expiry Date : ");
	gets((*cardData).cardExpirationDate);
	//check size
	uint8_t cardExpirySize;
	
	for(uint8_t i = 0 ; i< sizeof( (*cardData).cardExpirationDate ) ; i++ )
	{if((*cardData).cardExpirationDate[i] =='\0') 
		{
			cardExpirySize = i;
			break;
		}
	}
	
	if(cardExpirySize == 5) //write size
		// check if slash in prober location , month between 1 & 12 , year greater than 22 assumin this works from current year and will compare to real time in future
		if((*cardData).cardExpirationDate[2] == '/' && strToINT((*cardData).cardExpirationDate,0,1) <= 12 && strToINT((*cardData).cardExpirationDate,0,1) >= 1 && strToINT((*cardData).cardExpirationDate,3,4) >= 22)
			return OK;
		else return WRONG_EXP_DATE;
		
	else
		return WRONG_EXP_DATE;
	
}
EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
	printf("Enter Primary Account Number : ");
	gets((*cardData).primaryAccountNumber);
	uint8_t PANsize;
	//cheack alphanumeric against ascii value 0-9 48-57 a-z 97-122 A-Z 65-90
	for(uint8_t i = 0 ; (*cardData).primaryAccountNumber[i] != '\0' ; i++)
	{
		if( (*cardData).primaryAccountNumber[i] >= 48 && (*cardData).primaryAccountNumber[i] <= 57  || (*cardData).primaryAccountNumber[i] >=97 && (*cardData).primaryAccountNumber[i] <= 122 || (*cardData).primaryAccountNumber[i] >= 65 && (*cardData).primaryAccountNumber[i] <= 90)
			;
		else
			return WRONG_PAN;
		PANsize = i;
	}
	
	if(PANsize >= 15 && PANsize <= 18)
		return OK;
	else
		return WRONG_PAN;
	
}


void main()
{
	//testing CardHolderName 
    ST_cardData_t test;
    //printf("%d",getCardHolderName(&test));
    //printf("%d",getCardExpiryDate(&test));
	//printf("%d",getCardPAN(&test));
}