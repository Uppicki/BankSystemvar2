#pragma once
#include "Client.h"
class Service
{
private:
	std::vector<Client*> _fisClients;
	std::vector<Client*> _legClients;

	void __init__();
public:
	Service();
	~Service();

	std::vector<Client*> getFisClients();
	std::vector<Client*> getLegClients();

	void addClient(Client* client);
};

