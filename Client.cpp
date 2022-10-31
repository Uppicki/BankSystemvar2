#include "Client.h"
#include "ClientAccount.h"

Client::Client(std::string name)
{
	this->_name = name;
	this->_balance = 0;
	this->_clientAccouts = {};
}

Client::Client(std::string name, double balance)
{
	this->_name = name;
	this->_balance = balance;
	this->_clientAccouts = {};
}


Client::~Client()
{}


std::string Client::getName()
{
	return _name;
}


double Client::getBalance()
{
	return _balance;
}
void Client::setBalance(double balance)
{
	this->_balance = balance;
}

void Client::addAccount(ClientAccount* account)
{
	_clientAccouts.push_back(account);
}

std::vector<ClientAccount*> Client::getAccounts()
{
	return _clientAccouts;
}


bool Client::toUpBalanceAccount(ClientAccount* account, double sum)
{
	if (this->_balance < sum)
		return false;
	this->_balance = this->_balance - sum;
	account->toUpBalance(sum);
	return true;
}

bool Client::withdrawBalanceAccount(ClientAccount* account, double sum)
{
	if (account->withdrawBalance(sum))
	{
		this->_balance = this->_balance + sum;
		return true;
	}
	return false;
}

bool Client::transferIntoAccounts(ClientAccount* fromAccount, ClientAccount* toAccount, double sum)
{
	if (fromAccount->getOwnerBank() == toAccount->getOwnerBank())
		if (fromAccount->withdrawBalance(sum))
			toAccount->toUpBalance(sum);
		else
			return false;
	else
		return this->transferIntoBanks(fromAccount, toAccount, sum);
	return true;
}


