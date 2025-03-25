#include "IDriveStrategy.hpp"

class NormalDrive: public IDriveStrategy
{

    public:

        void Drive()
        {
            cout<<"Normal Drive..." << endl;
        }

        ~NormalDrive(){}

};