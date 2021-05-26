#ifndef BANK_H_

#define BANK_H_

#include "simple.h"
#include "account.h"
#include "PersonalDetails.h"

class Bank

{

private:
        double balance;
        double tamount;
        int size;
        int max_size;
        account *members;
        int curr_size;

public:
        // default constructor
        Bank();
        Bank(int size);
        //adding a bank account, we have to add this to the main function
        bool add_Account(account new_UserAccount);
        // Transfer balanace
        void transferBalance(account from_account, account taccount, int tamount);
        // get number of accounts
        int get_current_number_of_accounts();
        // get members of bank
        account get_members();
        // add new account
};
#endif
