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
	this->addBank("Bank 2", this->_legClients[1]);

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

std::vector<Client*> Service::getClientsWithAccount()
{
	std::vector<Client*> result = {};

	for (Client* c : this->getAllClients())
		if (c->getAccounts().size() != 0)
			result.push_back(c);

	return result;
}

void Service::deleteClient(Client* client) {
	this->popClient(client, this->getClientInd(client));
	delete client;
}

void Service::deleteBank(Bank* bank)
{
	this->popBank(bank, this->getBankInd(bank));
	delete bank;
}

std::vector<Bank*> Service::getFreeBanks(Client* client)
{
	std::vector<Bank*> r = {};
	for (Bank* b : _banks)
		if (!b->isBankClient(client))
			r.push_back(b);
	return r;
}

int Service::getClientInd(Client* client)
{
	std::vector<Client*> r;
	if (client->isFis())
		r = _fisClients;
	else
		r = _legClients;

	for (int i = 0; i < r.size(); i++)
		if (client == r[i])
			return i;
}
void Service::popClient(Client* client, int ind)
{
	if (client->isFis())
		_fisClients.erase(_fisClients.begin()+ ind);
	else
		_legClients.erase(_legClients.begin() + ind);
}
int Service::getBankInd(Bank* bank)
{
	for (int i = 0; i < _banks.size(); i++)
		if (bank == _banks[i])
			return i;
}
void Service::popBank(Bank* bank, int ind)
{
	_banks.erase(_banks.begin() + ind);
}