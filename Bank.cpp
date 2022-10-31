#include "Bank.h"

Bank::Bank(std::string name, Client* client)
{
	this->_ownerClient = client;
	this->_name = name;
	this->_balance = 0;
	this->_procent = 0.3;
	this->_clients = {};
}

Bank::~Bank()
{}



Client* Bank::getOwnerCLient()
{
	return this->_ownerClient;
}


std::string Bank::getName()
{
	return this->_name;
}

void Bank::setName(std::string name)
{
	this->_name = name;
}


double Bank::getBalance()
{
	return this->_balance;
}

void Bank::setBalance(double balance)
{
	this->_balance = balance;
}


double Bank::getProcent()
{
	return this->_procent;
}


std::vector<Client*> Bank::getClients()
{
	return this->_clients;
}

void Bank::addClient(Client* client)
{
	if (!this->isBankClient(client))
		this->_clients.push_back(client);
}


bool Bank::isBankClient(Client* client)
{
	for (Client* c : this->_clients)
		if (client == c)
			return true;
	return false;
}