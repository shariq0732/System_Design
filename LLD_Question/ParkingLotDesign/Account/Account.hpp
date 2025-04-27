#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Person.hpp"
#include "../Common/CommonEnum.hpp"
#include "../ParkingLot/ParkingLot.hpp"

class Account
{
    string accountId;
    string userName;
    string password;
    Person person;
    AccountType accountType;
    ParkingLot *parkinglot;
    public: 

        Account();
        Account(string theAccountId, string theUserName, string thePassword, Person thePerson, AccountType theAccountType);
        void setAccountId(int theAccountId);
        void setUserName(string theUserName);
        void setPassword(string thePassword);
        void setPerson(Person thePerson);
        void setAccountType(AccountType accountType);


        string getAccountId();
        string getUserName();
        string getPassword();
        Person getPerson();
        AccountType getAccountType();
        
};

#endif