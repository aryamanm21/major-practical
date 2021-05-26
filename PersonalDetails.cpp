#include "PersonalDetails.h"

// default constructor
PersonalDetails::PersonalDetails(){};

// constructor
PersonalDetails::PersonalDetails(string personalDetailsArray[10])
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
string PersonalDetails::getFullName()
{
    return Full_name;
};
// username getter method
string PersonalDetails::getUsername()
{
    return Username;
}
// password getter method
string PersonalDetails::getPassword()
{
    return Password;
}
// phone number getter method
string PersonalDetails::getPhoneNumber()
{
    return Phone_number;
}
// email getter method
string PersonalDetails::getEmail()
{
    return Email;
}
// secret question getter method
string PersonalDetails::getSecretQuestion()
{
    return Secret_question;
}
// secret answer getter method
string PersonalDetails::getSecretAnswer()
{
    return Secret_answer;
}
// age getter method
int PersonalDetails::getAge()
{
    return Age;
}
// annual income getter method
int PersonalDetails::getAnnualIncome()
{
    return Annual_income;
}
