#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>
#include <string>

#include "account.h"

class simple {
private:
public:
    simple();
    int calculate_monthly_interest (int month);
    int calculate_interest(int month);
    ~simple();
};

#endif
