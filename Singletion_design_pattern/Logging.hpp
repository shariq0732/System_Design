#pragma

#ifndef LOGGING
#define LOGGING

#include <iostream>
#include <string>
#include <mutex>
using namespace std;



class Logging
{
    static mutex mt;
    static int cnt;
    static Logging *logging_ptr;
    
    Logging();
    Logging(const Logging & logging) = delete;
    Logging& operator=(const Logging& logging) = delete;
    Logging(Logging&& logging) = delete;
    Logging& operator=(Logging&& logging) = delete;

    public:
        static Logging* getInstance();

        void Trace(string log);
        void Debug(string log);

};


#endif