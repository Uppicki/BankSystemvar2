#include "Service.h"

Service::Service()
{
	this->_fisClients = {};
	this->_legClients = {};

	__init__();
}

Service::~Service()
{
	this->_fisClients = {};
	this->_legClients = {};
}

void Service::__init__()
{
	this->addClient(new Client("Client 1", 10000));
	this->addClient(new Client("Client 2"));
	this->addClient(new Client("Client 3"));
	this->addClient(new Client("Client 4", 1000));

}


std::vector<Client*> Service::getFisClients()
{
	return _fisClients;
}
std::vector<Client*> Service::getLegClients()
{
	return _legClients;
}
std::vector<Client*> Service::getAllClients()
{
	std::vector<Client*> result = this->getFisClients();
	std::vector<Client*> result2 = this->getLegClients();

	result.insert(result.end(), result2.begin(), result2.end());

	return result;
}


std::vector<Bank*> Service::getBanks()
{
	return this->_banks;
}



void Service::addClient(Client* client)
{
	if (client->isFis())
		_fisClients.push_back(client);
	else
		_legClients.push_back(client);
}

void Service::addBank(Bank* bank)
{
	_banks.push_back(bank);
}