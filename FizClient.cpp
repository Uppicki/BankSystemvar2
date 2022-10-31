#include "FizClient.h"

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