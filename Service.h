#pragma once
#include "Bank.h"
class Service
{
private:
	std::vector<Client*> _fisClients;
	std::vector<Client*> _legClients;

	std::vector<Bank*> _banks;

	void __init__();
public:
	Service();
	~Service();

	std::vector<Client*> getFisClients();
	std::vector<Client*> getLegClients();
	std::vector<Client*> getAllClients();

	std::vector<Bank*> getBanks();

	void addClient(Client* client);

	bool addBank(std::string name, Client* client);

	bool addClientInBank(Bank* bank, Client* client);
};

