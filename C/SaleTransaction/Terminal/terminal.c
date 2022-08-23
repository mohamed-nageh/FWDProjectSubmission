#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
	//the following is taking date from PC
	  time_t t = time(NULL);
	  struct tm tm = *localtime(&t);
	  uint8_t d=tm.tm_mday,m=tm.tm_mon + 1;
	  int y=tm.tm_year + 1900;
   	  // fillng sring transactionDate into struct
	  (*termData).transactionDate[2] = '/';
	  (*termData).transactionDate[5] = '/';
	  (*termData).transactionDate[0] = d/10;
	  (*termData).transactionDate[1] = d%10;
	  (*termData).transactionDate[3] = m/10;
	  (*termData).transactionDate[4] = m%10;
	  (*termData).transactionDate[9]= y%10;
	  (*termData).transactionDate[7] = y/10;
	  (*termData).transactionDate[8] =(*termData).transactionDate[7]%10;
	  (*termData).transactionDate[6]= (*termData).transactionDate[7]/10;
	  (*termData).transactionDate[7]= (*termData).transactionDate[6]%10;
	  (*termData).transactionDate[6]= (*termData).transactionDate[6]/10;
     
   
	if((*termData).transactionDate[2] =='/' && (*termData).transactionDate[5] =='/') // check slashes
	{
			
			if(d>=1 && d<=31 && m <=12 && m>=1 && y>=2022 )
				return OK_TERMINAL;
			else
				return WRONG_DATE;
	}		
		else
			return WRONG_DATE;
	
	
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	//must provide exp date and run transdate to get test
	
	if(strToINT(cardData.cardExpirationDate,3,4) > striToINT(termData.transactionDate,8,9) ) //expYear > transYear
		return OK;
	
	else if(strToINT(cardData.cardExpirationDate,3,4) == striToINT(termData.transactionDate,8,9))
	{
		
		if( strToINT(cardData.cardExpirationDate,0,1) >= striToINT(termData.transactionDate,3,4)  )//expMon >= transMonth
			return OK;
		else
			return EXPIRED_CARD;
	}
	else
		return EXPIRED_CARD;
		
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
	printf("Enter Tansaction amount : ");
	scanf("%f",&(*termData).transAmount);
	if( (*termData).transAmount <=0 )
		return INVALID_AMOUNT;
	else
		return OK_TERMINAL;
	
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
	printf("Enter Transaction Maximum Amount: ");
	scanf("%f",&(*termData).maxTransAmount);
	if( (*termData).maxTransAmount <=0 )
		return INVALID_MAX_AMOUNT ;
	else
		return OK_TERMINAL;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
	//must run setMaxAmount, then run getTransactionAmount
	
	if(  (*termData).transAmount > (*termData).maxTransAmount )
		return EXCEED_MAX_AMOUNT;
	else
		return OK_TERMINAL;
	
}


EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)
{
	
}

void main()
{
	ST_terminalData_t testTerminal;
	ST_cardData_t testCard;
	while(1){
	//strcpy(testCard.cardExpirationDate,"09/20");
	//getTransactionDate(&testTerminal);
    //printf("%d",getTransactionDate(&testTerminal));
	//printf("%d",isCardExpired(testCard , testTerminal));
	//printf("%d",getTransactionAmount(&testTerminal));
	printf("%d",setMaxAmount(&testTerminal));
	printf("%d",getTransactionAmount(&testTerminal));
	printf("%d",isBelowMaxAmount(&testTerminal));
	
	
	
	}
}