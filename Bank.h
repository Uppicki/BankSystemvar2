#pragma once
#include "ClientAccount.h"


class Bank
{
private:
	Account* _ownerAccount;
	std::string _name;
	double _balance;
	double _procent;
	std::vector<ClientAccount*> _accounts;

public:
	Bank(std::string name, Client* client);
	~Bank();

	Account* getOwnerAccount();
	Client* getOwnerClient();

	std::string getName();
	void setName(std::string name);

	double getBalance();
	void toUpBalance(double balance);

	double getProcent();

	std::vector<ClientAccount*> getAccounts();
	void addClient(Client* client);

	bool isBankClient(Client* client);
};

