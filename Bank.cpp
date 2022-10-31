#include "Bank.h"

Bank::Bank(std::string name, Client* client)
{
	this->_ownerAccount = new Account(client);
	this->_name = name;
	this->_balance = 0;
	this->_procent = 0.3;
	this->_accounts = {};
}

Bank::~Bank()
{}



Account* Bank::getOwnerAccount()
{
	return this->_ownerAccount;
}

Client* Bank::getOwnerClient()
{
	return this->_ownerAccount->getOwnerClient();
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

void Bank::toUpBalance(double balance)
{
	this->_balance += balance;
}


double Bank::getProcent()
{
	return this->_procent;
}


std::vector<ClientAccount*> Bank::getAccounts()
{
	return this->_accounts;
}

void Bank::addClient(Client* client)
{
	if (!this->isBankClient(client))
		this->_accounts.push_back(new ClientAccount(this, client));
}


bool Bank::isBankClient(Client* client)
{
	for (Account* a : this->_accounts)
		if (a->getOwnerClient() == client)
			return true;
	return false;
}
