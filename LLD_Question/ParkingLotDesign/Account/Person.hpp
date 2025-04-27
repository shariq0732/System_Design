#ifndef PERSON_H    
#define PERSON_H

#include <string>
#include "Address.hpp"
using namespace std;

class Person
{
    string firstName;
    string lastName;
    Address address;

    public:
        Person();
        Person(string theFirstName, string theLastName, Address theAddress);

        string getFirstName();
        string getLastName();
        Address getAddress();

        void setFirstName(string theFirstName);
        void setLastName(string theLastName);
        void setAddress(Address theAddress);
};

#endif