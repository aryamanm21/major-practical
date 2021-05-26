#include "Bank.h"
#include "account.h"
#include <iostream>

#include <string>

using namespace std;

// Empty bank with no user accounts
Bank::Bank(){};

// Creating an empty number of user accounts
Bank::Bank(int size)
{
       // memory allocation with objects on the heap
       members = new account[size];
};
// Returns no. of user accounts in the banking system
int Bank::get_current_number_of_accounts()
{
       return curr_size;
};
// Returns the no of members
account Bank::get_members()
{
       return *members;
};

// Adding a new account to the bank system
bool Bank::add_Account(account new_UserAccount)
{
       if (size < max_size)
       {
              members[size] = new_UserAccount;
              size++;
              return true;
       }
       return false;
};
// transferring balance function
void Bank::transferBalance(account from_account, account taccount, int tamount)
{
       // if the balance is more than the transfer amouunt
       if (from_account.get_balance() > tamount)
       {
              {
                     // Subtract the transfer amount from the balance of the transferring account
                     from_account.withdraw(tamount);
                     // Addding the transferred amount to the recieving account
                     taccount.deposit(tamount);
                     // tell user the transfer was successful
                     cout << "Transfer successful! Your current balance: " << from_account.get_balance() << endl;
              }
       } // if the transfer amounnt is more than the balance, the transfer balance would not be allowed
       else
       {
              cout << endl;
              cout << "Sorry! Transfer failed! Reason: Insufficient Balance." << endl;
       }
};
