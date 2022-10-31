#pragma once
#include <string>
#include <vector>

class ClientAccount;

class Client
{
private: 
	std::string _name;
	double _balance;

	std::vector<ClientAccount*> _clientAccouts;
public:
	Client(std::string name);
	Client(std::string name, double balance);

	~Client();

	virtual std::string getName();

	double getBalance();
	void setBalance(double balance);

	virtual bool isFis() = 0;
	virtual std::string getType() = 0;

	void addAccount(ClientAccount* account);
	std::vector<ClientAccount*> getAccounts();

	bool toUpBalanceAccount(ClientAccount* account, double sum);
	bool withdrawBalanceAccount(ClientAccount* account, double sum);
	bool transferIntoAccounts(ClientAccount* fromAccount, ClientAccount* toAccount, double sum);
	virtual bool transferIntoBanks(ClientAccount* fromAccount, ClientAccount* toAccount, double sum) = 0;
};

