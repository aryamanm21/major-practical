#include <iostream>
#include <string>
using namespace std;

#ifndef PERSONAL_DETAILS_
#define PERSONAL_DETAILS_

class PersonalDetails
{
private:
    // check practical design
    string Full_name;
    string Username;
    string Password;
    string Phone_number;
    string Email;
    string Secret_question;
    string Secret_answer;
    int Age;
    int Annual_income;

public:
    // default constructor
    PersonalDetails();
    // overidding default constructor that requires all details to create a profile of a person
    PersonalDetails(string personalDetailsArray[10])
    {
        Full_name = personalDetailsArray[0];
        Phone_number = personalDetailsArray[1];
        Email = personalDetailsArray[2];
        Secret_question = personalDetailsArray[3];
        Secret_answer = personalDetailsArray[4];
        Age = stoi(personalDetailsArray[5]);
        Annual_income = stoi(personalDetailsArray[6]);
        Username = personalDetailsArray[7];
        Password = personalDetailsArray[8];
    };
    // full name getter method
    string getFullName();
    // username getter method
    string getUsername();
    // password getter method
    string getPassword();
    // phone number getter method
    string getPhoneNumber();
    // email getter method
    string getEmail();
    // secret question getter method
    string getSecretQuestion();
    // secret answer getter method
    string getSecretAnswer();
    // age getter method
    int getAge();
    // annual income getter method
    int getAnnualIncome();
};

#endif