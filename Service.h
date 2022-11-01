#pragma once
#include "Bank.h"
class Service
{
private:
	std::vector<Client*> _fisClients;
	std::vector<Client*> _legClients;

	std::vector<Bank*> _banks;

	void __init__();

	int getClientInd(Client* client);
	void popClient(Client* client, int ind);
	int getBankInd(Bank* bank);
	void popBank(Bank* bank, int ind);
public:
	Service();
	~Service();

	std::vector<Client*> getFisClients();
	std::vector<Client*> getLegClients();
	std::vector<Client*> getAllClients();

	std::vector<Bank*> getBanks();

	void addClient(Client* client);

	void deleteClient(Client* client);

	bool addBank(std::string name, Client* client);

	void deleteBank(Bank* bank);

	bool addClientInBank(Bank* bank, Client* client);

	std::vector<Client*> getClientsWithAccount();
	std::vector<Bank*> getFreeBanks(Client* client);
};

