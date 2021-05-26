#include <iostream>
#include <string>
#include "account.h"

using namespace std;

account::account()
{
    double balance = 0;
    double current_loan = 0;
    int credit_score = 0;
    double interest_rate = 0;
    double loan_limit = 0;
}

// when a user has an account, it will be passed to this constructor so that we can associate their account
account::account(PersonalDetails user)
{
    // currentUser = user;
    double loan_limit = currentUser.getAnnualIncome() * 1.2;
}

void account::deposit(double amount)
{
    balance = balance + amount;
    cout << "You have deposited " << amount << " dollars. Your account balance now is " << balance << ".\n";
}

void account::withdraw(double amount)
{
    balance = balance - amount;
    cout << "You have withdrawn " << amount << " dollars. Your account balance now is " << balance << ".\n";
}

double account::get_balance()
{
    return balance;
}

void account::set_credit_score()
{
    int annual_income = currentUser.getAnnualIncome();
    if (annual_income <= 40000 && annual_income > 0)
    {
        credit_score = 1;
    }
    else if (annual_income > 40000 && annual_income <= 80000)
    {
        credit_score = 2;
    }
    else if (annual_income > 80000)
    {
        credit_score = 3;
    }
    else
    {
        credit_score = 0;
    }
}

int account::get_credit_score()
{
    return credit_score;
}

void account::set_interest_rate()
{
    switch (credit_score)
    {
    case 3:
        interest_rate = 0.1;
        break;
    case 2:
        interest_rate = 0.05;
        break;
    case 1:
        interest_rate = 0.02;
        break;
    case 0:
        interest_rate = 0;
        break;
    default:
        interest_rate = 0;
        break;
    }
}

int account::get_interest_rate()
{
    return interest_rate;
}

double account::get_current_loan()
{
    return current_loan;
}

void account::pay_loan(double amount)
{
    current_loan = current_loan - amount;
    cout << "You have paid " << amount << " dollars loan. Your current loan now is " << current_loan << ".\n";
}

void account::make_loan(double amount)
{
    current_loan = current_loan + amount;
    balance += amount;
    cout << "You have made " << amount << " dollars loan. Your current loan now is " << current_loan << ".\n";
}

double account::get_loan_limit()
{
    return loan_limit;
}

account::~account()
{
}
