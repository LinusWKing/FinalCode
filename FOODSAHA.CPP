#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <time.h>

static int custCount = 0, tranCount = 0, empCount = 0;
int main();

void PressAKeyToContinue()
{
	int c;
	printf("\nPress any key to continue... \n");
	c = getch();
	if (c == 0 || c == 224)
		getch();
}

class Transcation
{
public:
	std::string tranID;
	std::string custID;
	int amount;
	std::string description;
	std::string date;

public:
	void makeDonation(std::string mcustID, std::string name)
	{
		time_t rawtime;
		char now[30];
		tm *curr_tm;
		time(&rawtime);
		curr_tm = localtime(&rawtime);
		strftime(now, 50, "%x %X", curr_tm);

		tranID = "TN" + std::to_string(tranCount + 1);
		std::cout << "\nDonor Name:" << name;
		custID = mcustID;
		std::cout << "\nAmount:";
		std::cin >> amount;
		date = now;
		description = name;
	}
};
Transcation transcation[100];

class Employee
{
public:
	std::string loginID, email, password, empName, empID;

public:
	void updateEmail(std::string memail)
	{
		email = memail;
	}
	void updatePassword(std::string mpassword)
	{
		password = mpassword;
	}
	void displayDetails()
	{
		std::cout << "Employee ID: " << empID << std::endl
				  << "Employee name: " << empName << std::endl
				  << "Employee Email: " << email;
	}
	void addDetails()
	{

		empID = "EM" + std::to_string(empCount + 1);
		loginID = "FSE" + std::to_string(empCount);
		std::cout << "\t\t EMPLOYEE REGISTRATION \n\n";
		std::cout << "Enter the Employee Name: ";
		std::cin >> empName;
		std::cout << std::endl;
		std::cout << "Enter the Employee Email: ";
		std::cin >> email;
		std::cout << std::endl;
		std::cout << "Enter the Employee Password: ";
		std::cin >> password;
		std::cout << std::endl;

		std::cout << "Account created successfully!" << std::endl
				  << "Your login details are: " << std::endl
				  << "Login ID: " << loginID << std::endl
				  << "Password: " << password << std::endl;
		PressAKeyToContinue();
	}
};
Employee employee[10];

class Customer
{
public:
	std::string loginID, email, password, custName, custID;

public:
	void updateEmail(std::string memail)
	{
		email = memail;
	}
	void updatePassword(std::string mpassword)
	{
		password = mpassword;
	}
	void displayDetails()
	{
		std::cout << "Customer ID: " << custID << std::endl
				  << "Customer name: " << custName << std::endl
				  << "Customer Email: " << email;
	}
	void addDetails()
	{
		custID = "CR" + std::to_string(custCount + 1);
		loginID = "FSC" + std::to_string(custCount);
		// std::cout << "Enter the Customer ID:";
		// std::cin >> custID;
		std::cout << "\t\t CUSTOMER REGISTRATION \n\n";
		std::cout << "Enter the Customer Name: ";
		std::cin >> custName;
		std::cout << std::endl;
		std::cout << "Enter the Customer Email: ";
		std::cin >> email;
		std::cout << std::endl;
		std::cout << "Enter the Customer Password: ";
		std::cin >> password;
		std::cout << std::endl;

		std::cout << "Account created successfully!" << std::endl
				  << "Your login details are: " << std::endl
				  << "Login ID: " << loginID << std::endl
				  << "Password: " << password << std::endl;
		PressAKeyToContinue();
	}
};
Customer customer[15];

void funCustomer()
{
	int i = 0, isTrue = 0;
	int ch, isFunExit, currPos;
	std::string loginID;
	std::string password;
CUS:
	do
	{

		std::cout << "\t\t HELLO CUSTOMER \n\n";
		std::cout << "Please select an option\n\n";
		std::cout << "1.Login for Current Customer\n2.Registration for New Customer\n0.Previous Menu";
		std::cout << "\n\nEnter Selected Option: ";

		if (!(std::cin >> ch))
		{
			std::cout << "\nPlease Input Valid Numeric Choice Only" << std::endl;
			PressAKeyToContinue();
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		switch (ch)
		{
		LOGIN:
		case 1:
			std::cout << "\n*****Please Login For Customer*****\n\n";
			std::cout << "\nLogin ID: ";
			std::cin >> loginID;
			std::cout << "\nPassword: ";
			std::cin >> password;

			for (i = 0; i < 15; i++)
			{
				if (customer[i].loginID == loginID && customer[i].password == password)
				{
					currPos = i;
					isTrue = 1;
					break;
				}
			}
			if (isTrue)
			{
				int isLogout, custCh;
				std::cout << "\t\t Welcome, " << customer[currPos].custName;
			ACC:
				do
				{

					std::cout << "\n\nPlease select from following options: \n";
					std::cout << "\n1.Make Donation\n2.View All Donation\n3.Update profile\n4.View Profile\n5.Logout";
					std::cout << "\n\nEnter the selected option: ";

					if (!(std::cin >> custCh))
					{
						std::cout << "Please Input Valid Numeric Choice Only" << std::endl;
						PressAKeyToContinue();
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						goto ACC;
					}

					switch (custCh)
					{
					case 1:
						transcation[tranCount].makeDonation(customer[currPos].custID, customer[currPos].custName);
						isLogout = 1;
						tranCount++;
						break;

					case 2:
						for (int k = 0; k < tranCount; k++)
						{

							if (transcation[k].custID == customer[currPos].custID)
							{
								//std::cout << "run";
								std::cout << k + 1 << ". "
										  << "Transaction ID " << transcation[k].tranID << " A donation of AUD " << transcation[k].amount
										  << " done on " << transcation[k].date << std::endl;
							}
						}
						PressAKeyToContinue();
						isLogout = 1;
						break;

					UPD:
					case 3:
						int updateP;
						std::cout << "\nPlease select from following options\n\n1.Email Update \n2.Password Update\n\nEnter the selection Option: ";
						if (!(std::cin >> updateP))
						{
							std::cout << "\nPlease Input Valid Numeric Choice Only\n"
									  << std::endl;
							PressAKeyToContinue();
							std::cin.clear();
							std::cin.ignore(10000, '\n');
							goto UPD;
						}
						if (updateP == 1)
						{
							std::string email;
							std::cout << "Current Email is: " << customer[currPos].email;
							std::cout << "\nEnter the Updated Email: ";
							std::cin >> email;
							customer[currPos].updateEmail(email);
							std::cout << "Email updated successfuly";
							PressAKeyToContinue();
						}
					PASS:
						if (updateP == 2)
						{
							std::string password;
							std::cout << "\nEnter the Updated Password: ";
							std::cin >> password;

							if (password == customer[currPos].password)
							{
								std::cout << "\nNew Password cannot be the same as old password. Please try again.";
								PressAKeyToContinue();
								std::cin.clear();
								std::cin.ignore(10000, '\n');
								goto PASS;
							}
							else
							{

								customer[currPos].updatePassword(password);
								std::cout << "Password updated successfuly";
								PressAKeyToContinue();
							}
						}
						isLogout = 1;
						break;

					case 4:
						customer[currPos].displayDetails();
						isLogout = 1;
						PressAKeyToContinue();
						break;

					case 5:
						funCustomer();

					default:
						std::cout << "\n Invalid option selected. Please try again.\n";
						PressAKeyToContinue();
						break;
					}

				} while (isLogout);
			}
			else
			{

				std::cout << "\nPlease enter valid username or password!!!!\n";
				PressAKeyToContinue();
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			isFunExit = 1;
			break;

		case 2:
			customer[custCount].addDetails();
			custCount++;
			isFunExit = 1;
			break;

		case 0:
			main();
		default:
			std::cout << "\n Invalid Choice. Try Again \n";
			PressAKeyToContinue();
			goto CUS;
		}
	} while (isFunExit);
}

void funEmployee()

{
	int i = 0, isTrue = 0;
	int ch, isFunExit, currPos;
	std::string loginID;
	std::string password;
EMP:
	do
	{

		std::cout << "\t \t \n HELLO EMPLOYEE \n\n";
		std::cout << "Please select from following options\n\n";
		std::cout << "1.Login for Current Employee\n2.Registration for New Employee\n0.Previous Menu";
		std::cout << "\n\nEnter Selected Option: ";

		if (!(std::cin >> ch))
		{
			std::cout << "Please Input Valid Numeric Choice Only" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		switch (ch)
		{
		LOGIN:
		case 1:
			std::cout << "\n*****Please Login For Employee*****\n\n";
			std::cout << "\nLoginID: ";
			std::cin >> loginID;
			std::cout << "\nPassword: ";
			std::cin >> password;

			for (i = 0; i < 10; i++)
			{
				if (employee[i].loginID == loginID && employee[i].password == password)
				{
					currPos = i;
					isTrue = 1;
					break;
				}
			}
			if (isTrue)
			{
				int isLogout, empCh;
				std::cout << "\t\t Welcome, " << employee[currPos].empName;
			ACC:
				do
				{
					std::cout << "\n\nPlease select an option";
					std::cout << "\n1.View All Donors\n2.View All Donations\n3.Update profile\n4.View Profile\n5.Logout";
					std::cout << "\n\nEnter the selected option: ";

					if (!(std::cin >> empCh))
					{
						std::cout << "Please Input Valid Numeric Choice Only" << std::endl;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						PressAKeyToContinue();
						goto ACC;
					}

					switch (empCh)
					{
					case 1:
						for (int j = 0; j < custCount; j++)
						{
							customer[j].displayDetails();
							std::cout << std::endl;
							std::cout << std::endl;
						}
						PressAKeyToContinue();
						isLogout = 1;
						break;
					case 2:
						for (int j = 0; j < tranCount; j++)
						{
							std::cout << j + 1 << ". "
									  << "Transaction ID " << transcation[j].tranID
									  << " A donation of AUD " << transcation[j].amount
									  << " done on " << transcation[j].date
									  << " by client ID " << transcation[j].custID << " - "
									  << transcation[j].description
									  << std::endl;
						}
						PressAKeyToContinue();
						isLogout = 1;
						break;
					UPD:
					case 3:
						int updateP;
						std::cout << "\nPlease select from following options\n\n1.Email Update \n2.Password Update\nEnter the selection Option: ";

						if (!(std::cin >> updateP))
						{
							std::cout << "Please Input Valid Numeric Choice Only" << std::endl;
							PressAKeyToContinue();
							std::cin.clear();
							std::cin.ignore(10000, '\n');
							goto UPD;
						}
						if (updateP == 1)
						{
							std::string email;
							std::cout << "Current Email is: " << employee[currPos].email;
							std::cout << "\nEnter the Updated Email: ";
							std::cin >> email;
							employee[currPos].updateEmail(email);
							std::cout << "\n Email updated successfully" << std::endl;
							PressAKeyToContinue();
						}
					PASS:
						if (updateP == 2)
						{
							std::string password;
							std::cout << "\nEnter the Updated Password: ";
							std::cin >> password;

							if (password == employee[currPos].password)
							{
								std::cout << "New Password cannot be the same as old password. Please try again.";
								PressAKeyToContinue();
								std::cin.clear();
								std::cin.ignore(10000, '\n');
								goto PASS;
							}
							else
							{
								employee[currPos].updatePassword(password);
								std::cout << "\n Password updated successfully" << std::endl;
								PressAKeyToContinue();
							}
						}
						isLogout = 1;
						break;
					case 4:
						std::cout << std::endl;
						employee[currPos].displayDetails();
						isLogout = 1;
						PressAKeyToContinue();
						break;

					case 5:
						funEmployee();

					default:
						std::cout << "Invalid selection. Please Try Again.\n";
						PressAKeyToContinue();
						continue;
					}
				} while (isLogout);
			}
			else
			{
				std::cout << "\nPlease enter valid username or password!!!!\n";
				PressAKeyToContinue();
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			isFunExit = 1;
			break;

		case 2:
			employee[empCount].addDetails();
			empCount++;
			isFunExit = 1;
			break;

		case 0:
			main();

		default:
			std::cout << "\n Invalid Choice. Try Again \n";
			PressAKeyToContinue();
			goto EMP;
		}
	} while (isFunExit);
}

int main()
{
	int ch, isExit = 0;

LOOP:
	do
	{
		std::cout << "\nPlease select from the following options\n";
		std::cout << "\n1.Customer\n2.Employee\n3.Exit\n\nEnter Selected Option: ";
		if (!(std::cin >> ch))
		{
			std::cout << "\nPlease Input Valid Numeric Choice Only" << std::endl;
			PressAKeyToContinue();
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			goto LOOP;
		}
		switch (ch)
		{
		case 1:
			funCustomer();
			isExit = 1;
			break;

		case 2:
			funEmployee();
			isExit = 1;
			break;

		case 3:
			std::cout << "\n\n\t\t*****Thank you for using Food Sahara*****";
			PressAKeyToContinue();
			exit(0);

		default:
			std::cout << "\nInvalid choice. Please try again" << std::endl;
			PressAKeyToContinue();
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			goto LOOP;
		}
	} while (isExit);
	getch();
}
