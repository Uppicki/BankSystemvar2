#pragma once
#include "Client.h"
class LegClient :
    public Client
{
public:
    LegClient(std::string name);
    LegClient(std::string name, double balance);


    bool isFis() override;
    std::string getType() override;

    bool transferIntoBanks(ClientAccount* fromAccount, ClientAccount* toAccount, double sum) override;
};

