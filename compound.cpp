#include "compound.h"

#include<iostream>
#include<string>

using namespace std;

compound::compound() {

}

int compound::calculate_interest (int month) {
    int money = 0;
    int interest = 1 + interest_rate;
    for (int i=0; i<month-1; i++) {
        interest = interest*interest;
    }
    money = balance*interest;
    return money;
}

compound::~compound() {

}
