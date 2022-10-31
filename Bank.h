#pragma once
#include "Client.h"


class Bank
{
private:
	Client* _ownerClient;
	std::string _name;
	double _balance;
	double _procent;
	std::vector<Client*> _clients;

public:
	Bank(std::string name, Client* client);
	~Bank();

	Client* getOwnerCLient();

	std::string getName();
	void setName(std::string name);

	double getBalance();
	void setBalance(double balance);

	double getProcent();

	std::vector<Client*> getClients();
	void addClient(Client* client);

	bool isBankClient(Client* client);
};

