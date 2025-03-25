#include "IDriveStrategy.hpp"

class SpecialDrive : public IDriveStrategy
{
    public:
    
        void Drive()
        {
            cout<<"Special Drive..." <<endl;
        }

        ~SpecialDrive(){}
};