#include "Bank.h"
#include "account.h"
#include <iostream>

#include <string>

using namespace std;

// Empty bank with no user accounts
Bank::Bank()
{
}

// Creating an empty number of user accounts
Bank::Bank(int size) : max_size(size), curr_size(0)

{
       // memory allocation with objects on the heap
       members = new UserAccount[size];
}
// Returns no. of user accounts in the banking system
int Bank::get_current_number_of_accounts()

{

       return curr_size;
}
// Returns the no of members 
UserAccounts *Bank::get_members()

{

       return members;
}

// Adding a new account to the bank system
bool add_Account(UserAccount new_UserAccount);
{
  if(size < max_size)
  {
    members[size] = new_account;
    size++;
    return true;
    }
    return false;
}
// transferring balance function 
void transferBalance(taccount, int tamount);

{
       // if the balance is more than the transfer amouunt
  if (balance > tamount)
  {
     {
            // Subtract the transfer amount from the balance of the transferring account 
	        balance -= tamount;
            // Addding the transferred amount to the recieving account 
	        t.balance += tamount;
     }
         // if the transfer amounnt is more than the balance, the transfer balance would not be allowed 
      else
      {
             cout<<endl;
             cout <<"Sorry! Transfer failed! Reason: Insufficient Balance."<<endl;
      }
	    return t.balance;
  }

  
}
