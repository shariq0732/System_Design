#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
{
    string street;
    string city;
    string state;
    string country;
    string pincode;

    public:
        Address();
        Address(string theStreet, string theCity, string theSate, string theCountry, string thePincode);

        string getStreet();
        string getCity();
        string getState();
        string getCountry();
        string getPincode();

        void setStreet(string theStreet);
        void setCity(string theCity);
        void setState(string theState);
        void setCountry(string theCountry);
        void setPincode(string thePincode);
};

#endif