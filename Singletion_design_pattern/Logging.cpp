#include "Logging.hpp"

mutex Logging::mt;
int Logging::cnt = 0;
Logging* Logging::logging_ptr = nullptr;


Logging::Logging()
{
    cnt++;
    cout<<"Created the instance of the class: " << cnt <<endl;
}

Logging* Logging::getInstance()
{
    if(nullptr == logging_ptr)
    {
        mt.lock();
        if(nullptr == logging_ptr)
        {
            logging_ptr = new Logging();
        }
       mt.unlock();
    }
    return logging_ptr;
}

void Logging::Trace(string log)
{
    cout<<"Trace message: " <<log <<endl;
}
void Logging::Debug(string log)
{
    cout<<"Debug message: " <<log <<endl;
}