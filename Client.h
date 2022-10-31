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

	std::string getName();
	void setName(std::string);

	double getBalance();
	void setBalance(double balance);

	bool isFis();
	std::string getType();
};

