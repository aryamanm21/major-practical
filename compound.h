#ifndef COMPOUND_H
#define COMPOUND_H

#include <iostream>
#include <string>

#include "account.h"
#include "PersonalDetails.h"

class compound
{
private:
    account currentUser;

public:
    compound();
    compound(account user);
    int calculate_interest(int month);
    ~compound();
};

#endif
