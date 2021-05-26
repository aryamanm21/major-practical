#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

#include "PersonalDetails.h"

class account
{
private:
    double balance;
    double current_loan;
    int credit_score;
    double interest_rate;
    PersonalDetails currentUser;
    double loan_limit;

public:
    account();
    account(PersonalDetails user);
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance();
    void set_credit_score();
    int get_credit_score();
    void set_interest_rate();
    int get_interest_rate();
    double get_current_loan();
    void pay_loan(double amount);
    void make_loan(double amount);
    double get_loan_limit();
    ~account();
};

#endif
