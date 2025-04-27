#include "Person.hpp"

Person::Person() {}
Person::Person(string theFirstName, string theLastName, Address theAddress): firstName(theFirstName), lastName(theLastName), address(theAddress) {}

string Person::getFirstName()
{
    return this->firstName;
}
string Person::getLastName()
{
    return this->lastName;
}
Address Person::getAddress()
{
    return this->address;
}

void Person::setFirstName(string theFirstName)
{
    this->firstName = theFirstName;
}
void Person::setLastName(string theLastName)
{
    this->lastName = theLastName;
}
void Person::setAddress(Address theAddress)
{
    this->address = theAddress;
}