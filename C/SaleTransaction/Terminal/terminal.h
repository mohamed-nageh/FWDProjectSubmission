
//#include "../Card/card.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#define strToINT(str,char1,char2) ( (str[char1]-48)*10 + str[char2]-48 )
#define striToINT(str,char1,char2) ( (str[char1])*10 + str[char2] )

#define strToYear(str,char1,char2,char3,char4) ( (str[char1]-48)*1000 + (str[char2]-48)*100  + (str[char3]-48)*10 + (str[char4]-48))

//typedef unsigned char uint8_t;
//#ifndef
typedef unsigned char uint8_t;

typedef struct ST_terminalData_t
{
float transAmount;
float maxTransAmount;
uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
OK_TERMINAL, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;
//#endif

/////from card.h

typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;




EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);