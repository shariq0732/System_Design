#include "AccountManager.hpp"

AccountManager* AccountManager::accountManager = nullptr;
mutex AccountManager::mt;


AccountManager::AccountManager() {}
AccountManager::AccountManager(vector<Account> theAccounts): accounts(theAccounts) {}

void AccountManager::login(string userName, string password, AccountType accountType)
{
}