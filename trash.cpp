#include <bits/stdc++.h>
using namespace std;

int main()
{

	// step 1
	cout << "+-------------------------------------------------+" << endl;
	cout << "|         Computer Science and Engineering        |" << endl;
	cout << "|         CSCE 1030 - Computer Science I          |" << endl;
	cout << "|         Student Name EUID euid @my.unt.edu      |" << endl;
	cout << "+-------------------------------------------------+" << endl;

	// step 2
	int ACCOUNT_LENGTH = 6;

	// step 3
	enum propertyType
	{
		Commercial = 1,
		Residential = 2
	};

	// step 4
	string name;
	bool valid = false;
	while (!valid)
	{
		cout << "Enter your name : ";
		getline(cin, name);
		for (int i = 0; i < name.length(); i++)
		{
			if (name[i] != ' ' && !isalpha(name[i]))
			{
				cout << "Your name can only have alphabets or spaces. Enter again." << endl;
				valid = false;
				break;
			}
			else
			{
				valid = true;
				name[0] = toupper(name[i]);
				if(isspace(name[i])
				   name[i+1] = toupper(name[i+1]);
			}
		}
	}

	// step 5
	valid = false;
	string accountNumber;
	while (!valid)
	{
		cout << "Enter Account Number : ";
		getline(cin, accountNumber);
		if (accountNumber.length() != ACCOUNT_LENGTH)
			cout << "Your account number must have 6 alphanumeric characters. Please enter again." << endl;
		else
		{
			for (int i = 0; i < accountNumber.length(); i++)
			{
				if (!isalpha(accountNumber[i]) && !isdigit(accountNumber[i]))
				{
					cout << "Your account number must have only alphabets or numbers. Please enter again." << endl;
					valid = false;
					break;
				}
				else
					valid = true;
			}
		}
	}

	// step 6
	valid = false;
	int numberOfProperty;
	while (!valid)
	{
		cout << "How many properties do you want to process?";
		cin >> numberOfProperty;

		if (numberOfProperty <= 0)
		{
			cout << "You cannot enter a negative value. Please enter again." << endl;
			valid = false;
		}
		else
			valid = true;
	}

	// step 7
	double totalTax = 0.00;

	// step 8
	for (int i = 1; i <= numberOfProperty; i++)
	{
		double currentTax = 0.00, value;
		bool valid = false;
		cout << "Processing Property #" << i << endl;
		while (!valid)
		{
			cout << "1. Commercial\n2. Residential " << endl;
			cout << "Enter Property Type : ";
			int property;
			cin >> property;

			switch (property)
			{
			case Commercial:
				valid = true;
				cout << "Enter property value: ";
				cin >> value;
				if (value <= 1000000)
				{
					currentTax = 0.035 * value;
					totalTax += currentTax;
				}
				else
				{
					currentTax = 0.035 * 1000000 + 0.05 * (value - 1000000);
					totalTax += currentTax;
				}
				cout << "Tax owed for property #" << i << ": $" << fixed << setprecision(2) << currentTax << endl;
				break;

			case Residential:
				double exemptedTax;
				valid = true;
				cout << "Enter property value: ";
				cin >> value;
				if (value <= 100000)
				{
					currentTax = 0.00;
					totalTax += currentTax;
				}
				
				else
				{
					currentTax = 0.035 * (value - 100000);
					if (numberOfProperty == 1)
					{
						srand((unsigned int)time(NULL));
						exemptedTax = rand() % 1001 + 1000;
						currentTax -= exemptedTax;
						if (currentTax < 0)
						{
							currentTax = 0;
							totalTax = 0;
						}
					}
				}
				totalTax += currentTax;
				cout << "Tax owed for property #" << i << ": $" << fixed << setprecision(2) << currentTax << endl;
				cout << "Single property tax exemption: $" << fixed << setprecision(2) << exemptedTax << endl;
				break;

			default:
				cout << "Invalid Property Type. Please enter again." << endl;
				valid = false;
				break;
			}
		}
	}

	// step 9
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Your total taxes are: $" << totalTax << endl;

	return 0;
}
