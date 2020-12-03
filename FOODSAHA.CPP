#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
static int custCount=0,tranCount=0, empCount=0;
class Transcation
{
	public:
		int tranID;
		int custID;
		int amount;
		char description;
		char date[12];

	public:
		void makeDonation(int custID,char name[20])
		{
			cout<<"\nDonor Name:"<<name;
			custID=custID;
			cout<<"\nAmount:";cin>>amount;
			cout<<"\n Date(dd/mm/yyyy):";cin>>date;
		}
};
Transcation transcation[100];
class Employee
{
	public:
		int empID;
		char empName[10],email[20],password[10];

	public:
		void updateEmail(char email[20])
		{
			email=email;
		}
		void updateDetails(char password[20])
		{
			password=password;
		}
		void displayDetails()
		{
			cout<< empID<<" "<< empName<< " "<< email;
		}
		void addDetails()
		{
			cout<< "Enter the Employee ID:";
			cin>>empID;
			cout<< "Enter the Employee Name:";
			cin>>empName;
			cout<< "Enter the Employee Email:";
			cin>>email;
			cout<< "Enter the Employee Password:";
			cin>>password;

		}
};
Employee employee[10];
class Customer
{
	public:
		int custID;
		char custName[10],email[20],password[10];

	public:
		void updateEmail(char email[20])
		{
			email=email;
		}
		void updateDetails(char password[20])
		{
			password=password;
		}
		void displayDetails()
		{
			cout<< custID <<" "<< custName << " "<< email;
		}
		void addDetails()
		{
			cout<< "Enter the Customer ID:";
			cin>>custID;
			cout<< "Enter the Customer Name:";
			cin>>custName;
			cout<< "Enter the Customer Email:";
			cin>>email;
			cout<< "Enter the Customer Password:";
			cin>>password;

		}
};

Customer customer[15];
void funCustomer()
{
   int i=0,isTrue=0;
   char userEmail[20],userPassword[20];
   int ch,isFunExit,currPos;
   do
   {
	cout<<"Please select from following options\n\n";
	cout<<"1.Login for Current Customer\n2.Registration for New Customer";
	cout<<"\n\nEnter Selected Option:";cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"\n*****Please Login For Customer*****\n\n";
		cout<<"\nUsername:";cin>>userEmail;
		cout<<"\nPassword:";cin>>userPassword;

		for(i=0;i<10;i++)
		{
			if((strcmp(customer[i].email,userEmail)==0)&&(strcmp(customer[i].password,userPassword)==0))
			{
				currPos=i;
				isTrue=1;
				break;
			}
		}
		if(isTrue)
		{
			int isLogout,custCh;
			do
			{
				cout<<"\n\nplease select from following options";
				cout<<"\n1.Make Donation\n2.View All Donation\n3.Update profile\n4.View Profile\n5.Logout";
				cout<<"\n\n Enter the selected option:";cin>>custCh;
				switch(custCh)
				{
					case 1:
						transcation[tranCount].makeDonation(customer[currPos].custID,customer[currPos].custName);
						isLogout=1;
						tranCount++;
						break;
					case 2:
						for(int k=0;k<tranCount;k++)
						{

							if(transcation[k].custID==customer[currPos].custID)
							{
								cout<<"run";
								cout<<"\nThe donation of AUD"<<transcation[k].amount<<"done on "<<transcation[k].date;
							}
						}
						isLogout=1;
						break;
					case 3:
						int updateP=0;
						cout<<"\nPlease select from following options\n 1.Email Update \n2.Password Update\nEnter the selection Option:";
						cin>>updateP;
						if(updateP==1)
						{
							char email[20];
							cout<<"\nEnter the Updated Email:";cin>>email;
							customer[currPos].updateEmail(email);
						}
						else
						{
							char password[20];
							cout<<"\nEnter the Updated Password:";cin>>password;
							customer[currPos].updateEmail(password);
						}
						isLogout=1;
						break;
					case 4:
						customer[currPos].displayDetails();
						isLogout=1;
						break;
					default:
						return;
				}

			}while(isLogout);
		}
		else
		{
			cout<<"Please enter valid username or password!!!!";
		}
		isFunExit=1;
		break;

		case 2:
		customer[custCount].addDetails();
		custCount++;
		isFunExit=1;
		break;

		default:
		isFunExit=0;
		break;
	}
   }while(isFunExit);




}
void funEmployee()
{
   int i=0,isTrue=0;
   char userEmail[20],userPassword[20];
   int ch,isFunExit,currPos;
   do
   {
	cout<<"\nPlease select from following options\n\n";
	cout<<"1.Login for Current Employee\n2.Registration for New Employee";
	cout<<"\n\nEnter Selected Option:";cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"\n*****Please Login For Employee*****\n\n";
		cout<<"\nUsername:";cin>>userEmail;
		cout<<"\nPassword:";cin>>userPassword;

		for(i=0;i<10;i++)
		{
			if((strcmp(employee[i].email,userEmail)==0)&&(strcmp(employee[i].password,userPassword)==0))
			{
				currPos=i;
				isTrue=1;
				break;
			}
		}
		if(isTrue)
		{
			int isLogout,custCh;
			do
			{
				cout<<"\n\nplease select from following options";
				cout<<"\n1.View All Donors\n2.View All Donations\n3.Update profile\n4View Profile\n5.Logout";
				cout<<"\n\n Enter the selected option:";cin>>custCh;
				switch(custCh)
				{
					case 1:
						for(int j=0;j<custCount;j++)
						{
							customer[j].displayDetails();
						}
						isLogout=1;
						break;
					case 2:
						for(j=0;j<tranCount;j++)
						{
							cout<<"\nThe donation of AUD"<<transcation[j].amount<<"done on "<<transcation[j].date;
						}
						isLogout=1;
						break;
					case 3:
						int updateP=0;
						cout<<"Please select from following options\n 1.Email Update \n2.Password Update\nEnter the selection Option:";
						cin>>updateP;
						if(updateP==1)
						{
							char email[20];
							cout<<"\nEnter the Updated Email:";cin>>email;
							employee[currPos].updateEmail(email);
						}
						else
						{
							char password[20];
							cout<<"\nEnter the Updated Password:";cin>>password;
							employee[currPos].updateEmail(password);
						}
						isLogout=1;
						break;
					case 4:
						employee[currPos].displayDetails();
						isLogout=1;
						break;
					default:
						return;
				}

			}while(isLogout);
		}
		else
		{
			cout<<"Please enter valid username or password!!!!";
		}
		isFunExit=1;
		break;

		case 2:
		employee[custCount].addDetails();
		empCount++;
		isFunExit=1;
		break;

		default:
		isFunExit=0;
		break;
	}
   }while(isFunExit);
}
void main()
{
	int ch,isExit=0;
	clrscr();
	do
	{
		cout<<"Please select from the following options\n";
		cout<<"\n1.Customer\n2.Employee\n3.Exit\nEnter Selected Option:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\nSelected options is customer";
			funCustomer();
			isExit=1;
			break;

			case 2:
			funEmployee();
			isExit=1;
			break;

			default:
			isExit=0;

		}
	}while(isExit);
	getch();
}
