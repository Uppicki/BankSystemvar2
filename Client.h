#pragma once
#include <string>
#include <vector>
class Client
{
private: 
	std::string _name;
	double _balance;
public:
	Client(std::string name);
	Client(std::string name, double balance);

	~Client();

	virtual std::string getName();

	double getBalance();
	void setBalance(double balance);

	virtual bool isFis() = 0;
	virtual std::string getType() = 0;
};

