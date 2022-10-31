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
	this->addClient(new FizClient("Client", "Fizic 1", 1000));
	this->addClient(new FizClient("Client", "Fizic 2", 1000));
	this->addClient(new FizClient("Client", "Fizic 3", 1000));
	this->addClient(new LegClient("LegClient 1", 10000));
	this->addClient(new LegClient("LegClient 2", 10000));
	this->addClient(new LegClient("LegClient 3", 10000));

	this->addBank("Bank 1", this->_legClients[0]);
	this->addBank("Bank 2", this->_legClients[0]);

	this->addClientInBank(this->_banks[0], this->_legClients[2]);
	this->addClientInBank(this->_banks[0], this->_legClients[2]);
	this->addClientInBank(this->_banks[1], this->_legClients[2]);
	this->addClientInBank(this->_banks[0], this->_fisClients[2]);
	this->addClientInBank(this->_banks[1], this->_fisClients[2]);
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

bool Service::addBank(std::string name, Client* client)
{
	if (client->isFis())
		return false;
	else
		this->_banks.push_back(new Bank(name, client));
	return true;
}



bool Service::addClientInBank(Bank* bank, Client* client)
{
	if (bank->isBankClient(client))
		return false;
	bank->addClient(client);
}