#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct Customer
{
	string name;
	long long int acc_no;
	long long int balance;
}Customer;

class Bank
{
	Customer *c;
	
public:
	void AddNewCustomer(vector<Bank> *);
	void DisplayCustomers(vector<Bank> *);
	Customer* getCustomer();
	void SearchCustomerByName(vector<Bank> *);
	void SearchCustomerByAcc(vector<Bank> *);
	void UpdateCustomerByName(vector<Bank> *);
	void UpdateCustomerByAcc(vector<Bank> *);
	void WriteCustomerNames(vector<Bank> *);
	void Deposit(vector<Bank> *);
	void Withdraw(vector<Bank> *);

};
