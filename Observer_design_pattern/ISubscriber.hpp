#ifndef SUBSCRIBER
#define SUBSCRIBER

#include <iostream>
#include <string>
using namespace std;

class ISubscriber
{
    public:

        virtual void notify(string message) = 0;

        virtual ~ISubscriber(){}
};

#endif