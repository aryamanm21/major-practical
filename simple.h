#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>
#include <string>

#include "account.h"

class simple
{
private:
    account currentUser;

public:
    simple();
    simple(account user);
    int calculate_monthly_interest(int month);
    int calculate_interest(int month);
    ~simple();
};

#endif
