#include "PeronsalDetails.h"
#include "account.h"

#include<iostream>
#include<string>

using namespace std;

account::account() {
    double balance = 0;
    double current_loan = 0;
    int credit_score = 0;
    double interest_rate = 0;
}

void account::deposit(double amount) {
    balance = balance + amount;
    cout << "You have deposited " << amount << " dollars. Your account balance now is " << balance <<".\n";
}

void account::withdraw(double amount) {
    balance = balance - amount;
    cout << "You have withdrawn " << amount << " dollars. Your account balance now is " << balance <<".\n";
}

int account::get_balance() {
    return balance;
}

void account::set_credit_score(int score) {
    credit_score = score;
}

int account::get_credit_score() {
    return credit_score;
}

void account::set_interest_rate(int rate) {
    interest_rate = rate;
}

int account::get_interest_rate() {
    return interest_rate;
}

int account::get_current_loan() {
    return current_loan;
}

void account::pay_loan(double amount) {
    current_loan = current_loan - amount;
    cout << "You have paid " << amount << " dollars loan. Your current loan now is " << current_loan <<".\n";
}

void account::make_loan(double amount) {
    current_loan = current_loan + amount;
    cout << "You have made " << amount << " dollars loan. Your current loan now is " << current_loan <<".\n";
}

account::~account() {

}
