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
	this->addClient(new Client("Client 1", 10000));
	this->addClient(new Client("Client 2"));
	this->addClient(new Client("Client 3"));
	this->addClient(new Client("Client 4", 1000));
}


std::vector<Client*> Service::getFisClients()
{
	return _fisClients;
}
std::vector<Client*> Service::getLegClients()
{
	return _legClients;
}

void Service::addClient(Client* client)
{
	if (client->isFis())
		_fisClients.push_back(client);
	else
		_legClients.push_back(client);
}