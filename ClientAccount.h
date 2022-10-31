#pragma once
#include "Account.h"

class Bank;

class ClientAccount :
    public Account
{
private:
    Bank* _ownerBank;
public:
    ClientAccount(Bank* bank, Client* client);
    ~ClientAccount();

    std::string generateId() override;

    Bank* getOwnerBank();
};

