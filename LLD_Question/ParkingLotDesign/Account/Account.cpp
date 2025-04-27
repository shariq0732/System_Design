#include "Account.hpp"

Account::Account(){}
Account::Account(string theAccountId, string theUserName, string thePassword, Person thePerson, AccountType theAccountType): 
                    accountId(theAccountId), userName(theUserName), password(thePassword), person(thePerson), accountType(theAccountType) {
                        this->parkinglot = ParkingLot::getInstance();
                    } 

void Account::setAccountId(int theAccountId)
{
    this->accountId = theAccountId;
}
void Account::setUserName(string theUserName)
{
    this->userName = theUserName;
}
void Account::setPassword(string thePassword)
{
    this->password = thePassword;
}
void Account::setPerson(Person thePerson)
{
    this->person = thePerson;
}
void Account::setAccountType(AccountType accountType)
{
    this->accountType = accountType;
}

string Account::getAccountId()
{
    return this->accountId;
}
string Account::getUserName()
{
    return this->userName;
}
string Account::getPassword()
{
    return this->password;
}
Person Account::getPerson()
{
    return this->person;
}

AccountType Account::getAccountType()
{
    return this->accountType;
}