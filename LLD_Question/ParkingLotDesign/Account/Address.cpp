#include "Address.hpp"

Address::Address() {}
Address::Address(string theStreet, string theCity, string theSate, string theCountry, string thePincode):
                street(theStreet), city(theCity), state(theSate), country(theCountry), pincode(thePincode) { }

string Address::getStreet()
{
    return this->street;
}

string Address::getCity()
{
    return this->city;
}

string Address::getState()
{
    return this->state;
}

string Address::getCountry()
{
    return this->country;
}

string Address::getPincode()
{
    return this->pincode;
}

void Address::setStreet(string theStreet)
{
    this->street = theStreet;
}

void Address::setCity(string theCity)
{
    this->city = theCity;
}

void Address::setState(string theState)
{
    this->state = theState;
}

void Address::setCountry(string theCountry)
{
    this->country = theCountry;
}

void Address::setPincode(string thePincode)
{
    this->pincode = thePincode;
}