#include "FizClient.h"
#include "ClientAccount.h"
#include "Bank.h"

FizClient::FizClient(std::string name, std::string surname)
	: Client(name)
{
	this->_surname = surname;
}
FizClient::FizClient(std::string name, std::string surname, double balance)
	: Client(name, balance)
{
	this->_surname = surname;
}


bool FizClient::isFis() {
	return true;
}


std::string FizClient::getType()
{
	return "Fizical";
}

std::string FizClient::getName()
{
	return Client::getName() + " " + this->_surname;
}

bool FizClient::transferIntoBanks(ClientAccount* fromAccount, ClientAccount* toAccount, double sum)
{
	if (fromAccount->withdrawBalance(sum))
	{
		double p = fromAccount->getOwnerBank()->getProcent();
		toAccount->toUpBalance(sum*(1 - p));
		fromAccount->getOwnerBank()->toUpBalance(sum * p);
		return true;
	}
	else
		return false;
}