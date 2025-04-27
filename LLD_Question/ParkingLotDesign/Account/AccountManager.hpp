#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include <string>
#include "Account.hpp"
#include <mutex>
using namespace std;

class AccountManager
{
    vector<Account> accounts;
    static AccountManager *accountManager;
    static mutex mt;

    public:

        AccountManager();
        AccountManager(vector<Account> accounts);

        void login(string userName, string password, AccountType accountType);
};

#endif