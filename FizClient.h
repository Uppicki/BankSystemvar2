#pragma once
#include "Client.h"
class FizClient :
    public Client
{
private:
    std::string _surname;
public:
    FizClient(std::string name, std::string surname);
    FizClient(std::string name, std::string surname, double balance);


    std::string getName() override;

    bool isFis() override;
    std::string getType() override;

    bool transferIntoBanks(ClientAccount* fromAccount, ClientAccount* toAccount, double sum) override;
};

