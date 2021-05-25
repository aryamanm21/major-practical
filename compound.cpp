#include "compound.h"
#include "account.h"

#include <iostream>
#include <string>

using namespace std;

compound::compound(account user)
{
    currentUser = user;
}

int compound::calculate_interest(int month)
{
    int money = 0;
    int interest = 1 + currentUser.get_interest_rate();
    for (int i = 0; i < month - 1; i++)
    {
        interest = interest * interest;
    }
    money = currentUser.get_balance() * interest;
    return money;
}

compound::~compound()
{
}
