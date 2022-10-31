#include "ClientAccount.h"
#include "Bank.h"

ClientAccount::ClientAccount(Bank* bank, Client* client)
	: Account(client)
{
	this->_ownerBank = bank;
	this->setId(this->generateId());
}


ClientAccount::~ClientAccount()
{}


Bank* ClientAccount::getOwnerBank()
{
	return _ownerBank;
}

std::string ClientAccount::generateId()
{
	return "BankOwner:<" + this->_ownerBank->getName() + ">\nAccountOwner:<"+
		this->getOwnerClient()->getName()+">";
}