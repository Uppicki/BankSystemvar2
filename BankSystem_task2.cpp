// BankSystem_task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Service.h"

void printClients(std::vector<Client*> clients);
void printClient(Client* client);

void printBanks(std::vector<Bank*> banks);
void printBank(Bank* bank);

int main()
{
    std::cout << "Hello World!\n";



	Service* service = new Service();



    int change = -1;

	while (change != 0)
	{
		std::cout << "\nInput your actions:\n"
			<< "\t1)Show clients\n"
			<< "\t2)Show banks\n";

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
						printClients(service->getAllClients());
						break;
					case 2:
						printClients(service->getFisClients());
						break;
					case 3:
						printClients(service->getLegClients());
						break;
				}
			}
		case 2:
			printBanks(service->getBanks());
			break;
		default:
			break;
		}
	}
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
	std::cout << "\nClient name: " << client->getName();
	std::cout << "\nClient type: " << client->getType();
	std::cout << "\nClient balance: " << client->getBalance();
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
	std::cout << "\nBank name: " << bank->getName();
	std::cout << "\nBank balance: " << bank->getBalance();
	std::cout << "\nBank client List: ";
	printClients(bank->getClients());
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
