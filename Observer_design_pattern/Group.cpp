#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "ISubscriber.hpp"
using namespace std;

class Group
{
    set<ISubscriber*> joinees;
    public:

        void Subscribe(ISubscriber *subscriber)
        {
            joinees.insert(subscriber);
        }

        void UnSubscribe(ISubscriber* subscriber)
        {
            joinees.erase(subscriber);
        }

        void notify(string message)
        {
            for(auto subscriber : joinees)
            {
                subscriber->notify(message);
            }
        }
};