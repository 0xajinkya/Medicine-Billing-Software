#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>
using namespace std;
void login();
void ending();
void check_stock();
void check_customer();

void working()
{
	cout << endl
		 << endl;
	cout << "\t\t\tWe are working hard" << endl;
}

struct id
{
	string fullName;
	long long int mobNo;
};

void genarate_bil(string name, long long int mob)
{
	int n;
	cout << "Enter Total Number of Medicine: ";
	cin >> n;
	string medicineName[n];
	int Quantity[n];
	float price[n];
	int total[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter Name of Medicine: ";
		cin >> medicineName[i];

		cout << "Quantity of Medicine: ";
		cin >> Quantity[i];

		cout << "Price of Medicine: ";
		cin >> price[i];
		total[i] = Quantity[i] * price[i];
		system("cls");
	}
	cout << endl;
	cout << "Customer Name:" << name << "\t\t\tMobile Number:   " << mob << endl;
	cout << endl;

	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "Name of Medicinet\t\t\tQuantity\t\tPrice\t\tTotal" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << medicineName[i] << "\t\t\t\t\t" << Quantity[i] << "\t\t" << price[i] << "\t\t" << total[i] << endl;
	}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "				****Thanks You****" << endl;
	cout << endl;
	cout << endl;
}

int main(int argc, char const *argv[])
{
	id data;
	int x = 0, n;
	system("cls");
	login();
	data.mobNo = 0;

	do
	{
		cout << "\n\n\n\t\t\t\t     Medical Billing Software" << endl;
		cout << "Main Menu" << endl;
		cout << "1.		Add Customer" << endl;
		cout << "2.		Create Bill" << endl;
		cout << "3.		Add Medicine" << endl;
		cout << "4.		Check Stock" << endl;
		cout << "5.		Customer Names" << endl;
		cout << "6.		This Month Sell" << endl;
		cout << "7.\t\tExit" << endl;
		cout << "Enter Your choice :";
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			cout << "Customers Name:";
			getline(cin, data.fullName);
			cout << "Mobile Number:";
			cin >> data.mobNo;
			system("cls");
			break;
		case 2:
			if (data.mobNo != 0)
			{
				genarate_bil(data.fullName, data.mobNo);
			}
			else
			{
				cout << endl;
				cout << "\t\tCreate Customer First." << endl;
				cout << endl;
			}
			break;
		case 3:
			working();
			break;
		case 4:
			check_stock();
			break;
		case 5:
			check_customer();
			break;
		case 6:
			working();
			break;

		case 7:
			ending();
			getch();
			return 0;
			break;
		}
		cout << endl;
		cout << "Enter 1 to go back to main menu or 0 to exit" << endl;
		cin >> x;
		system("cls");
		if (x == 0)
		{
			ending();
			getch();
			return 0;
		}
	} while (x == 1);

	return 0;
}

void login()
{
	string pass = "";
	char ch;
	cout << "\n\n\n\n\t\t\t\t     Medical Billing Software";
	cout << "\n\n\n\n\n\n\n\t\t\t\t\tEnter Password: ";
	ch = _getch();
	while (ch != 13)
	{ // character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (pass == "pranjali")
	{
		cout << "\n\n\t\t\t\t\tAccess Granted \n";
	}
	else
	{
		cout << "\n\n\t\t\t\t\tAccess Aborted...Press Any Key To Try Again\n";
		ch = _getch();
		system("CLS");
		login();
	}
	system("PAUSE");
	system("CLS");
}

void ending()
{
	system("cls");
	cout << "\n\n\n\n\t\t\t\t     Thanks For Using";
}

void check_stock()
{
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("medicine_data.csv", ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	cout << endl;
	cout << "Your Stock items is:" << endl;
	cout << endl;
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}
}
void check_customer()
{
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("customer.csv", ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	cout << endl;
	cout << "Your Customer List is:" << endl;
	cout << endl;
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}
}
