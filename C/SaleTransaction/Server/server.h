//#ifndef

//#endif
#include <stdio.h>
#include<string.h>


typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
//from terminal.h
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


/////from card.h

typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirationDate[6];
}ST_cardData_t;

//////////////////////////////
typedef enum EN_cardError_t
{
OK_CARD, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;


typedef enum EN_transState_t
{
APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
ST_cardData_t cardHolderData;
ST_terminalData_t terminalData;
EN_transState_t transState;
uint32_t transactionSequenceNumber;
}ST_transaction;


typedef enum EN_serverError_t
{
OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t ;

typedef struct ST_accountsDB_t
{
float balance;
uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction *transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
EN_serverError_t saveTransaction(ST_transaction *transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction *transData);
