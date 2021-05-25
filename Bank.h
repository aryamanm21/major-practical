#ifndef BANK_H_

#define BANK_H_

#include "simple.h"
#include "account.h"
#include "PersonalDetails.h"

class Bank

{

private:
        int balance;
        int size;
        int max_size;
        account *members;

public:
        // default constructor
        Bank();

        // Transfer balanace
        void transferBalance(account, int balance);
};
#endif
