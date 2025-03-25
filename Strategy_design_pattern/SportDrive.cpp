#include "IDriveStrategy.hpp"

class SportDrive: public IDriveStrategy
{

    public:
        void Drive()
        {
            cout<<"Sport Drive..." << endl;
        }

        ~SportDrive(){}

};