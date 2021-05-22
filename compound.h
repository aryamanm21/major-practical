#ifndef COMPOUND_H
#define COMPOUND_H

#include <iostream>
#include <string>

#include "account.h"

class compound {
private:

public:
    compound();
    int calculate_interest (int month);
    ~compound();
};

#endif
