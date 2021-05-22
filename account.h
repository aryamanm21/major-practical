#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

#include "PersonalDetails.h"

class account {
private:
    double balance;
    double current_loan;
    int credit_score;
    double interest_rate;
public:
    account();
    void deposit(double amount);
    void withdraw(double amount);
    int get_balance();
    void set_credit_score(int score);
    int get_credit_score();
    void set_interest_rate(int rate);
    int get_interest_rate();
    int get_current_loan();
    void pay_loan(double amount);
    void make_loan(double amount);
    ~account();
};

#endif
