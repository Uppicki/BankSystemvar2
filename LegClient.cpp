#include "LegClient.h"


LegClient::LegClient(std::string name) 
	: Client(name)
{

}
LegClient::LegClient(std::string name, double balance)
	: Client(name, balance)
{

}


bool LegClient::isFis() {
	return false;
}


std::string LegClient::getType()
{
	return "LegalEntity";
}

bool LegClient::transferIntoBanks(ClientAccount* fromAccount, ClientAccount* toAccount, double sum)
{
	return false;
}