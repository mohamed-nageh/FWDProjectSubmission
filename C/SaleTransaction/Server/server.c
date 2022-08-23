#include "server.h"
//server-side accounts
ST_accountsDB_t accountDB[255] =

			{	{5000   ,"abcd1234xyzw1234"},
				{8000   ,"abcd1234xyzw1235"},
				{7000   ,"abcd1234xyzw1236"},
				{6000   ,"abcd1234xyzw1237"},
				{9000   ,"abcd1234xyzw1238"},
				{10000  ,"abcd1234xyzw1239"},
				{125000 ,"abcd1234xyzw1240"},
			};
			
ST_transaction transactionDB[255] ; // initialized with zeros

typedef struct ST_transaction_t
{
ST_cardData_t cardHolderData;
ST_terminalData_t terminalData;
EN_transState_t transState;
uint32_t transactionSequenceNumber;
}ST_transaction;

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	
	
	//create flags
	bool accountFound = false , amountAvailable = false;
	for(uint8 i = 0 ; i<255 ; i++ )
	{
		//look for account in account DB
		if(strcmp( (*transData).cardHolderData.primaryAccountNumber,accountDB[i].primaryAccountNumber) == 0 )
			accountFound = true;
	}
}

/*

EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
	
}
EN_serverError_t isAmountAvailable(ST_trminalData_t *termData)
{
	
}
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	
}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
{
	
}*/
void main(){
	//printf("%f",accountDB[5].balance); // test database of accounts
	printf("%f",transactionDB[5].transactionSequenceNumber);
}
