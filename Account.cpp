#include "Account.h"


Account::Account(Client* client)
{
	this->_ownerClient = client;
	this->_id = this->generateId();
	this->_balance = 0;
}


Account::~Account()
{
	if (this->_ownerClient != nullptr)
		this->getOwnerClient()->withdrawBalanceAccount((ClientAccount*)this, this->_balance);

}

double Account::getBalance()
{
	return _balance;
}

std::string Account::getID()
{
	return this->_id;
}

void Account::setId(std::string id)
{
	this->_id = id;
}

Client* Account::getOwnerClient()
{
	return  this->_ownerClient;
}

void Account::setOwnerClient(Client* client)
{
	this->_ownerClient = client;
}






std::string Account::generateId()
{
	return "BankOwnerAccount:<" + this->_ownerClient->getName() + ">";
}

void Account::toUpBalance(double sum)
{
	this->_balance += sum;
}

bool Account::withdrawBalance(double sum)
{
	if (this->_balance < sum)
		return false;
	this->_balance -= sum;
	return true;
}