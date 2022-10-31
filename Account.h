#pragma once
#include "FizClient.h"
#include "LegClient.h"



class Account
{
private:
	Client* _ownerClient;
	std::string _id;
	double _balance;
 
public:
	Account(Client* client);

	~Account();

	double getBalance();

	std::string getID();
	void setId(std::string id);
	virtual std::string generateId();

	Client* getOwnerClient();
};

