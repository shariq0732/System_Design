#include "Logging.hpp"
#include <thread>


void function1()
{
    Logging *log = Logging::getInstance();
    log->Trace("Printed message from the function1");
}

void function2()
{
    Logging* log = Logging::getInstance();
    log->Debug("Printed message from function2");
}

int main()
{
    thread t1(function1);
    thread t2(function2);

    t1.join();
    t2.join();

    return 0;
}