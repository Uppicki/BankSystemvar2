// BankSystem_task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Service.h"

void printShortClients(std::vector<Client*> clients);
void printShortClient(Client* client);
void printClients(std::vector<Client*> clients);
void printClient(Client* client);

void printShortBanks(std::vector<Bank*> banks);
void printShortBank(Bank* bank);
void printBanks(std::vector<Bank*> banks);
void printBank(Bank* bank);

void printAccounts(std::vector<ClientAccount*> accounts);
void printAccount(ClientAccount* account);

int main()
{
	Service* service = new Service();



    int change = -1;

	while (change != 0)
	{
		std::cout << "\nInput your actions:\n"
			<< "\t1)Show clients\n"
			<< "\t2)Show banks\n"
			<< "\t3)To up balance\n"
			<< "\t4)Withdraw balance\n"
			<< "\t5)Transfer\n"
			<< "\t6)Add Account\n"
			<< "\t7)Create bank\n"
			<< "\t8)Delete bank\n"
			<< "\t9)Create client\n"
			<< "\t10)Delete client\n";

		std::cin >> change;



		switch (change)
		{
		case 1:
			while (change != 9)
			{
				std::cout << "\nInput your actions:\n"
					<< "\t1)Show all clients\n"
					<< "\t2)Show fiz clients\n"
					<< "\t3)Show legal clients\n";

				std::cin >> change;

				switch (change)
				{
				case 1:
					printShortClients(service->getAllClients());
					break;
				case 2:
					printShortClients(service->getFisClients());
					break;
				case 3:
					printShortClients(service->getLegClients());
					break;
				}
			}
		case 2:
			printShortBanks(service->getBanks());
			break;
		case 3:
		{
			int innerchange1;
			int innerchange2;
			double sum;
			std::vector<Client*> clients = service->getClientsWithAccount();
			std::vector<ClientAccount*> accounts = {};

			printShortClients(clients);
			std::cout << "\nChange person: \n";

			std::cin >> innerchange1;

			accounts = clients[innerchange1]->getAccounts();

			printAccounts(accounts);

			std::cout << "\nChange account: \n";
			std::cin >> innerchange2;

			std::cout << "\Input sum: \n";
			std::cin >> sum;

			if (clients[innerchange1]->toUpBalanceAccount(accounts[innerchange2], sum))
				std::cout << "\nOperation Complete\n";
			else
				std::cout << "\nOperation Failed\n";

			break; 
		}
		case 4:
		{
			int innerchange1;
			int innerchange2;
			double sum;
			std::vector<Client*> clients = service->getClientsWithAccount();
			std::vector<ClientAccount*> accounts = {};

			printShortClients(clients);
			std::cout << "\nChange person: \n";

			std::cin >> innerchange1;

			accounts = clients[innerchange1]->getAccounts();

			printAccounts(accounts);

			std::cout << "\nChange account: \n";
			std::cin >> innerchange2;

			std::cout << "\Input sum: \n";
			std::cin >> sum;

			if (clients[innerchange1]->withdrawBalanceAccount(accounts[innerchange2], sum))
				std::cout << "\nOperation Complete\n";
			else
				std::cout << "\nOperation Failed\n";

			break;
		}
		case 5:
		{
			int innerchange1;
			int innerchange2;
			int innerchange3;
			int innerchange4;
			double sum;
			std::vector<Client*> clients = service->getClientsWithAccount();
			std::vector<ClientAccount*> accounts1 = {};
			std::vector<ClientAccount*> accounts2 = {};

			printShortClients(clients);
			std::cout << "\nChange person from: \n";

			std::cin >> innerchange1;

			std::cout << "\nChange person to: \n";

			std::cin >> innerchange2;

			accounts1 = clients[innerchange1]->getAccounts();

			printAccounts(accounts1);

			std::cout << "\nChange account: \n";
			std::cin >> innerchange3;

			accounts2 = clients[innerchange2]->getAccounts();

			printAccounts(accounts2);

			std::cout << "\nChange account: \n";
			std::cin >> innerchange4;

			std::cout << "\Input sum: \n";
			std::cin >> sum;

			if (clients[innerchange1]->transferIntoAccounts(accounts1[innerchange3], accounts2[innerchange4], sum))
				std::cout << "\nOperation Complete\n";
			else
				std::cout << "\nOperation Failed\n";

			break;
		}
		case 6:
		{
			int innerchange1;
			int innerchange2;
			std::vector<Client*> clients = service->getAllClients();
			std::vector<Bank*> banks = {};

			printShortClients(clients);
			std::cout << "\nChange person: \n";

			std::cin >> innerchange1;

			banks = service->getFreeBanks(clients[innerchange1]);

			printShortBanks(banks);

			std::cout << "\nChange bank: \n";
			std::cin >> innerchange2;

			banks[innerchange2]->addClient(clients[innerchange1]);
		}
		case 7:
		{
			int innerchange1;
			std::string name;
			std::vector<Client*> clients = service->getLegClients();

			printShortClients(clients);
			std::cout << "\nChange person from: \n";

			std::cin >> innerchange1;

			std::cout << "\nInput name: \n";

			std::cin >> name;

			service->addBank(name, clients[innerchange1]);			

			break;
		}
		case 8:
		{
			int innerchange1;
			std::vector<Bank*> banks = service->getBanks();

			printShortBanks(banks);
			std::cout << "\nChange bank: \n";

			std::cin >> innerchange1;

			service->deleteBank(banks[innerchange1]);

			break;
		}
		case 9:
		{
			char type;
			std::string name;
			std::string surname;
			double sum;
			
			std::cout << "\nIs FizClient(+/-) : \n";

			std::cin >> type;

			std::cout << "\nInput name: \n";

			std::cin >> name;

			std::cout << "\nInput balance: \n";

			std::cin >> sum;

			if (type == '+')
				service->addClient(new FizClient(name, surname, sum));
			else
				service->addClient(new LegClient(name, sum));
		}
		case 10:
		{
			int innerchange1;
			std::vector<Client*> clients = service->getAllClients();

			printShortClients(clients);
			std::cout << "\nChange person to delete: \n";

			std::cin >> innerchange1;

			service->deleteClient(clients[innerchange1]);
			break;
		}
		}
	}

}


void printShortClients(std::vector<Client*> clients)
{
	if (clients.size() == 0)
		std::cout << "\nList is empty\n";
	else
	{
		std::cout << "\nList size: " << clients.size() << "\n";
		int i = 0;
		for (Client* c : clients)
		{
			std::cout << "\n\n" << i++;
			printShortClient(c);
		}
	}
	std::cout << "\n";
}
void printShortClient(Client* client)
{
	std::cout << "\nClient name: " << client->getName();
	std::cout << "\nClient type: " << client->getType();
	std::cout << "\nClient balance: " << client->getBalance();
	std::cout << "\nClient accounts: " << client->getAccounts().size();
}


void printClients(std::vector<Client*> clients)
{
	if (clients.size() == 0)
		std::cout << "\n\n\nList is empty\n";
	else
	{
		std::cout << "\n\n\nList size: " << clients.size() << "\n";
		for (Client* c : clients)
			printClient(c);
	}
}
void printClient(Client* client)
{
	std::cout << "\n";
	std::cout << "\nClient name: " << client->getName();
	std::cout << "\nClient type: " << client->getType();
	std::cout << "\nClient balance: " << client->getBalance();
	std::cout << "\nClient accounts: " << client->getAccounts().size();
	printAccounts(client->getAccounts());
}


void printShortBanks(std::vector<Bank*> banks)
{
	if (banks.size() == 0)
		std::cout << "\nList is empty\n";
	else
	{
		std::cout << "\nList size: " << banks.size() << "\n";
		int i = 0;
		for (Bank* b : banks)
		{
			std::cout << "\n\n" << i++;
			printShortBank(b);
		}
	}
	std::cout << "\n";
}
void printShortBank(Bank* bank)
{
	std::cout << "\nBank name: " << bank->getName();
	std::cout << "\nBank owner account: " << bank->getOwnerAccount()->getID();
	std::cout << "\nBank balance: " << bank->getBalance();
	std::cout << "\nBank client List: " << bank->getAccounts().size();
}


void printBanks(std::vector<Bank*> banks)
{
	if (banks.size() == 0)
		std::cout << "\n\n\nList is empty\n";
	else
	{
		std::cout << "\n\n\nList size: " << banks.size() << "\n";
		for (Bank* b : banks)
			printBank(b);
	}
}
void printBank(Bank* bank)
{
	std::cout << "\n";
	std::cout << "\nBank name: " << bank->getName();
	std::cout << "\nBank owner account: " << bank->getOwnerAccount()->getID();
	std::cout << "\nBank balance: " << bank->getBalance();
	std::cout << "\nBank client List: ";
	printAccounts(bank->getAccounts());
}


void printAccounts(std::vector<ClientAccount*> accounts)
{
	if (accounts.size() == 0)
		std::cout << "\nList is empty\n";
	else
	{
		std::cout << "\nList size: " << accounts.size() << "\n";
		int i = 0;
		for (ClientAccount* a : accounts)
		{
			std::cout << "\n\n" << i++;
			printAccount(a);
		}
	}
	std::cout << "\n";
}
void printAccount(ClientAccount* account)
{
	std::cout << "\nAccount ID: " << account->getID();
	std::cout << "\nAccount balance: " << account->getBalance();
}







// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
