#include "simple.h"

#include<iostream>
#include<string>

using namespace std;

simple::simple() {

}

int simple::calculate_monthly_interest (int month) {
    int monthly = 0;
    monthly = balance*interest_rate;
    return monthly;
}

int simple::calculate_interest (int month) {
    int money = 0;
    money = balance + balance*interest_rate*month;
    return money;
}

simple::~simple() {

}
