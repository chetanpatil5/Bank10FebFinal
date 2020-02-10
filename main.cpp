//#pragma once
//#include"Bank.h"
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int runn = 1;
//	int cnt = 0;
//	vector<Bank> vc1;
//	Bank b;
//	while (1)
//	{
//		b.AddNewCustomer(&vc1);
//		b.DisplayCustomers(&vc1);
//		
//			if (cnt == 2)
//			{
//				b.Withdraw(&vc1);
//				//b.WriteCustomerNames(&vc1);
//				//cout << "\nPrinted in file";
//				break;
//			}
//			cnt++;
//	}
//
//
//	return 0;
//}

#pragma once
#include"Bank.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int runn = 1;
	int cnt = 0;
	vector<Bank> vc1;
	Bank b;
	int choice=0;
	while (1)
	{
		cout << "\n1. Add New Customers :";
		cout << "\n2. Display Customers :";
		cout << "\n3. Search Customer By Name :";
		cout << "\n4. Search Customer By Acc No :";
		cout << "\n5. Update Customer By Name :";
		cout << "\n6. Update Customer By Acc No :";
		cout << "\n7.Withdrawl";
		cout << "\n8.Deposit";
		cin >> choice;
		switch (choice)
		{
		case 1:b.AddNewCustomer(&vc1);
			break;
		case 2:b.DisplayCustomers(&vc1);
			break;
		case 3:b.SearchCustomerByName(&vc1);
			break;
		case 4:b.SearchCustomerByAcc(&vc1);
			break;
		case 5:b.UpdateCustomerByName(&vc1);
			break;
		case 6:b.UpdateCustomerByAcc(&vc1);
			break;
		case 7:b.Withdraw(&vc1);
			break;
		case 8:b.Deposit(&vc1);
			break;
		case 9:b.WriteCustomerNames(&vc1);
			break;
		default:
			break;
		}
		
	}


	return 0;
}