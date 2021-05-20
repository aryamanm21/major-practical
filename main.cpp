#include "PersonalDetails.h"
#include "Bank.h"
#include "UserAccounts.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// FUNCTION DEFINITIONS
// vector array to store everyone's personal details
vector<PersonalDetails> personalDetailsVector;

// vector array to store everyone's user accounts
// vector<UserAccounts> userAccountsVector;

// vector array to store bank information
// vector<Bank> bankVector;

// main UI when user first logs into bank system
void mainscreen();

// create user functionality. see function for details.
void createUser();

// MAIN FUNCTION
int main()
{
    // initial log in UI function called.
    mainscreen();

    // print out users for debugging purposes. it works.
    // for (int i = 0; i < personalDetailsVector.size(); i++)
    // {
    //     cout << personalDetailsVector[i].getFullName() << endl;
    // }
    return 0;
}

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
        cout << "2.) Exit" << endl;
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
            exit = true;
            cout << "Bye!" << endl;
            break;

        // // case for user accounts or bank. commented out until their
        // // functionality is added to their class files
        // case 3:
        //     option = 3;
        //     exit = true;
        //     break;

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
