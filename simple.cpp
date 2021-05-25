#include "simple.h"

#include <iostream>
#include <string>

using namespace std;

simple::simple()
{
}

simple::simple(account user)
{
    currentUser = user;
}

int simple::calculate_monthly_interest(int month)
{
    int monthly = 0;
    monthly = currentUser.get_balance() * currentUser.get_interest_rate();
    return monthly;
}

int simple::calculate_interest(int month)
{
    int money = 0;
    money = currentUser.get_balance() + currentUser.get_balance() * currentUser.get_interest_rate();
    return money;
}

simple::~simple()
{
}
