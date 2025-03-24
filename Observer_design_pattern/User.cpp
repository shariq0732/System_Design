#include "ISubscriber.hpp"

class User : public ISubscriber
{
    int userId;
    
    public:

        User(){}
        User(int aUserId)
        {
            userId = aUserId;
        }

        void notify(string message)
        {
            cout<<"User " << userId << ": message: "<< message <<endl;
        }

        ~User(){

        }

};