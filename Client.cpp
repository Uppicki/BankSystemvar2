#include "Client.h"


Client::Client(std::string name)
{
	this->_name = name;
	this->_balance = 0;
}

Client::Client(std::string name, double balance)
{
	this->_name = name;
	this->_balance = balance;
}


Client::~Client()
{}


std::string Client::getName()
{
	return _name;
}
void Client::setName(std::string name)
{
	this->_name = name;
}

double Client::getBalance()
{
	return _balance;
}
void Client::setBalance(double balance)
{
	this->_balance = balance;
}

bool Client::isFis()
{
	return true;
}
std::string Client::getType()
{
	return "type";
}