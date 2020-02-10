#pragma once
#include"Bank.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void Bank::AddNewCustomer(vector<Bank> *s1)
{
	c = new Customer;
	cout << "\nEnter the name of the customer : ";
	cin >> c->name;

	cout << "\nEnter the acc no of the customer : ";
	cin >> c->acc_no;

	cout << "\nEnter the balance of the customer : ";
	cin >> c->balance;

	s1->push_back(*this);



}
void Bank::DisplayCustomers(vector<Bank> *s1)
{
	vector<Bank>::iterator itr;
	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		cout << "\nThe name of the customer : " << itr->getCustomer()->name;

		cout << "\nThe acc no of the customer : " << itr->getCustomer()->acc_no;


		cout << "\nThe balance of the customer : " << itr->getCustomer()->balance;
	}



}

void Bank::SearchCustomerByName(vector<Bank> *s1)
{
	vector<Bank>::iterator itr;
	string name;
	cout << "Enter the name of the customer to be searched : ";
	cin >> name;
	int flag = 0;

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		if (name == itr->getCustomer()->name)
		{
			flag = 1;
			cout << "\nThe name of the customer : " << itr->getCustomer()->name;
			cout << "\nThe acc no of the customer : " << itr->getCustomer()->acc_no;
			cout << "\nThe balance of the customer : " << itr->getCustomer()->balance;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo match found";
	}
}

void Bank::SearchCustomerByAcc(vector<Bank> *s1)
{
	Customer*p;
	p = new Customer;
	vector<Bank>::iterator itr;
	long long int acc;
	cout << "Enter the Account No of the customer to be searched : ";
	cin >> p->acc_no;
	int flag = 0;

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		if (p->acc_no == itr->getCustomer()->acc_no)
		{
			flag = 1;
			cout << "\nThe name of the customer : " << itr->getCustomer()->name;
			cout << "\nThe acc no of the customer : " << itr->getCustomer()->acc_no;
			cout << "\nThe balance of the customer : " << itr->getCustomer()->balance;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo match found";
	}
}

void Bank::UpdateCustomerByName(vector<Bank> *s1)
{
	vector<Bank>::iterator itr;
	string name;
	cout << "Enter the name of the customer to be searched : ";
	cin >> name;
	int flag = 0;

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		if (name == itr->getCustomer()->name)
		{
			flag = 1;
			cout << "\nEnter the New Name Of The Customer";
			cin>> itr->getCustomer()->name;
			cout << "\nUpdated Details : ";
			cout << "\nThe name of the customer : " << itr->getCustomer()->name;
			cout << "\nThe acc no of the customer : " << itr->getCustomer()->acc_no;
			cout << "\nThe balance of the customer : " << itr->getCustomer()->balance;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo match found";
	}
}
void Bank:: UpdateCustomerByAcc(vector<Bank> *s1)
{

	Customer*p;
	p = new Customer;
	vector<Bank>::iterator itr;
	long long int acc;
	cout << "Enter the Account No of the customer to be searched : ";
	cin >> p->acc_no;
	int flag = 0;

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		if (p->acc_no == itr->getCustomer()->acc_no)
		{
			flag = 1;
			cout << "Enter updated acc no";
			cin >> itr->getCustomer()->acc_no;
			cout << "\nThe name of the customer : " << itr->getCustomer()->name;
			cout << "\nThe acc no of the customer : " << itr->getCustomer()->acc_no;
			cout << "\nThe balance of the customer : " << itr->getCustomer()->balance;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo match found";
	}
}

void Bank::WriteCustomerNames(vector<Bank> *s1)
{
	vector<Bank>::iterator itr;
	Customer*p;
	p = new Customer;

	Customer c1;
	
	
	ofstream fout;
	fout.open("CustomerList.dat");

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		p = itr->getCustomer();
		c1 = *p;
		fout.write((char *)(&c1), sizeof(Customer));
		//fout << itr->getCustomer()->name;
	}
	fout.close();
}

void Bank::Withdraw(vector<Bank> *s1)
{

	Customer*p;
	p = new Customer;
	vector<Bank>::iterator itr;
	long long int acc;
	long long int temp=0;
	cout << "\n\nEnter the Account No of the customer to be searched : ";
	cin >> p->acc_no;
	int flag = 0;

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		if (p->acc_no == itr->getCustomer()->acc_no)
		{
			flag = 1;
			cout << "\nThe  balance of the customer : " << itr->getCustomer()->balance;
			cout << "\nEnter the amount to be witdrawn :";
			cin >> temp;
			if (itr->getCustomer()->balance > 0 &&  itr->getCustomer()->balance-temp >0)
			{
				itr->getCustomer()->balance = itr->getCustomer()->balance - temp;
				cout << "\nWithdrawl successful";
			}

			cout << "\nThe Updated balance of the customer : " << itr->getCustomer()->balance;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo match found";
	}
}



void Bank::Deposit(vector<Bank> *s1)
{

	Customer*p;
	p = new Customer;
	vector<Bank>::iterator itr;
	long long int acc;
	long long int temp = 0;
	cout << "\n\nEnter the Account No of the customer to be searched : ";
	cin >> p->acc_no;
	int flag = 0;

	for (itr = s1->begin(); itr < s1->end(); itr++)
	{
		if (p->acc_no == itr->getCustomer()->acc_no)
		{
			flag = 1;
			cout << "\nThe  balance of the customer : " << itr->getCustomer()->balance;
			cout << "\nEnter the amount to be deposited :";
			cin >> temp;
			if (itr->getCustomer()->balance > 0 )
			{
				itr->getCustomer()->balance = itr->getCustomer()->balance + temp;
				cout << "\nDeposit successful";
			}

			cout << "\nThe Updated balance of the customer : " << itr->getCustomer()->balance;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo match found";
	}
}


Customer* Bank::getCustomer()
{

	return c;

}