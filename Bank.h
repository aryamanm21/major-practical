#ifndef BANK_H_

#define BANK_H_

#include "simple.h"
#include "account.h"
#include "PersonalDetails.h"

class Bank

{

private:
        int balance;
        int tamount;
        int size;
        int max_size;
        account *members;

public:
        // default constructor
        Bank();

        //adding a bank account, we have to add this to the main function
        bool add_Account(UserAccount new_UserAccount);
        // Transfer balanace
        void transferBalance(taccount, int tamount);
};
#endif
