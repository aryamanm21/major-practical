#include "PersonalDetails.h"
// #include "Bank.h"
#include "account.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// FUNCTION DEFINITIONS
// vector array to store everyone's personal details
// memory allocation for object vector from stack
vector<PersonalDetails> personalDetailsVector;

// vector array to store everyone's user accounts
vector<account> userAccountsVector;

// vector array to store bank information
// is a bank vector necessary? because we are storing user accounts in the vector userAccounts vector
// vector<Bank> bankVector;

// main UI when user first logs into bank system
void mainscreen();

// create user functionality. see function for details.
void createUser();

void Login();

void resetPassword();

void viewAccount(int account_index);

// MAIN FUNCTION
int main()
{
    // initial log in UI function called.
    mainscreen();

    // print out users for debugging purposes. it works.
    for (int i = 0; i < personalDetailsVector.size(); i++)
    {
        cout << personalDetailsVector[i].getFullName() << endl;
    }
    return 0;
}

// mainscreen function
void mainscreen()
{
    // exit is false so that the main screen loop runs at least once.
    bool exit = false;

    // while loop for logic. The loop will exit when the user performs some
    // action like creating an user.
    while (exit == false)
    {
        // new variable option to allow user to performance an action
        int option;
        cout << "Hello there! What would you like to do?\nEnter the option:" << endl;
        cout << "1.) Create User" << endl;
        cout << "2.) Login" << endl;
        cout << "3.) Reset Password" << endl;
        cout << "4.) Exit" << endl;
        cin >> option;

        // a switch statement for the menu logic
        switch (option)
        {
        // case to allow user to enter their personal details
        case 1:
            createUser();
            exit = true;
            break;

        // case which allows for user to exit
        case 2:
            Login();
            exit = true;
            break;

        // reset password functionality
        case 3:
            resetPassword();
            exit = true;
            break;

        // exit the bank program
        case 4:
            exit = true;
            cout << "Bye!" << endl;
            break;

        // case where input is invalid.
        default:
            cout << "Invalid try again!" << endl;
            break;
        }
    }
};

// function to create a user
void createUser()
{
    // this is the list of questions that he user must be asked.
    string questionaire[11] = {
        "Your full name:",
        "Your phone number:",
        "Your email:",
        "Your secret question (this will be used to reset your password):",
        "Your secret answer:",
        "Your age:",
        "Your annual income (this will determine if you can take out loans or not):",
        "Your username:",
        "Your password:",
        "Confirm password:",
        "Made a mistake?(y/n):",
    };

    // this will store the questionaire answer and pass them to the newUser
    // variable to create a new user.
    string questionaire_answers[11] = {};
    // this will repeat the user details loop
    questionaire_answers[10] = "n";

    // this loop will ask the user their details. will loop until user
    // the user doesn't make a mistake in their details. using a do-while
    // loop so that the loop runs at least once.
    do
    {
        for (int i = 0; i < 11; i++)
        {
            // # IF WE GET MORE TIME: add input sanitation
            // # TODO: check if username is taken
            // I think the way we are reading the string is
            // causing issues with the testing text file
            cout << questionaire[i] << endl;
            cin.ignore(1);
            getline(cin, questionaire_answers[i]);
        }
    } while (questionaire_answers[10] == "y");

    // if password and confirm password don't match, ask the user to enter
    // to enter them again.
    while (questionaire_answers[8] != questionaire_answers[9])
    {
        cout << "Your passwords don't match. Please enter them again: " << endl;
        cin.ignore(1, '\n');
        getline(cin, questionaire_answers[8]);
        cout << "Confirm password: " << endl;
        cin.ignore(1, '\n');
        getline(cin, questionaire_answers[9]);
    }

    // A message to the user saying user is saved.
    cout << "User details saved!" << endl;

    // temporary variable to store new user information.
    PersonalDetails newUser(questionaire_answers);
    // adding the newUser to the vector array
    personalDetailsVector.push_back(newUser);

    // return to the main screen
    mainscreen();
};

// function to view the person's account
void viewAccount(int account_index)
{
    bool exit = false;

    while (exit == false)
    {
        int option;
        account currentUser(personalDetailsVector[account_index]);

        cout << "Your Balance:" << currentUser.get_balance() << endl;
        cout << "Your credit score:" << currentUser.get_credit_score() << endl;
        cout << "Your interest rate on your loan:" << currentUser.get_interest_rate() << endl;
        cout << "Your loan balance:" << currentUser.get_current_loan() << endl;
        cout << "Your loan limit: " << currentUser.get_loan_limit();

        cout << "What would you like to do?" << endl;
        cout << "1.) Deposit " << endl;
        cout << "2.) Withdraw " << endl;
        cout << "3.) Pay installment " << endl;
        cout << "4.) New loan " << endl;
        cout << "5.) Transfer to another account " << endl;
        cout << "6.) Exit " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            double deposit;
            cout << "Please enter deposit amount: " << endl;
            cin >> deposit;
            currentUser.deposit(deposit);
            break;
        case 2:
            double withdraw;
            cout << "Please enter withdrawal amount: " << endl;
            cin >> withdraw;
            currentUser.withdraw(withdraw);
        case 3:
            double pay;
            cout << "Please enter how much you are paying off: " << endl;
            cin >> pay;
            currentUser.pay_loan(pay);
        case 4:
            double loan;
            cout << "Please enter how much you would like to loan: " << endl;
            while (loan + currentUser.get_current_loan() > personalDetailsVector[account_index].getAnnualIncome())
            {
                cout << "Sorry that exceeds your loan limit!\nPlease enter how much you would like to loan: " << endl;
            }
        }
    }
}

// function to reset user password
void resetPassword()
{
    bool exit = false;
    string email;

    while (exit == false)
    {
        cout << "Please enter your email:" << endl;
        cin >> email;

        for (int i = 0; i < personalDetailsVector.size(); i++)
        {
            if (email == personalDetailsVector[i].getEmail())
            {
                string answer;
                cout << personalDetailsVector[i].getSecretQuestion() << endl;
                cin >> answer;
                if (answer == personalDetailsVector[i].getSecretAnswer())
                {
                    string new_password, confirm_password;
                    cout << "Answered correctly! Please enter your new password:" << endl;
                    while (new_password != confirm_password)
                    {
                        cout << "Please enter your new password:" << endl;
                        cin >> new_password;
                        cout << "Confirm password: " << endl;
                        cin >> confirm_password;
                        if (new_password != confirm_password)
                        {
                            cout << "Please try again!" << endl;
                        }
                    }
                    cout << "Successfully set your new password: " << endl;
                    mainscreen();
                    exit = true;
                }
            }
            else
            {
                cout << "Email does not exist! Try again!" << endl;
            }
        }
    }
}

// function to login into account
void Login()
{
    bool exit = false;
    string email;
    string password;

    while (exit == false)
    {
        cout << "Please enter your email:" << endl;
        cin >> email;
        cout << "Please enter your password:" << endl;
        cin >> password;

        for (int i = 0; i < personalDetailsVector.size(); i++)
        {
            if (email == personalDetailsVector[i].getEmail() && password == personalDetailsVector[i].getPassword())
            {
                cout << "Sign in successful!" << endl;
                viewAccount(i);
                exit = true;
            }
            else
            {
                cout << "Email or password is incorrect!" << endl;
            }
        }
    }
}