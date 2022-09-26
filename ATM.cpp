#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	float password;
	int choice;
	float balance = 1000.00;
	float amount;
	long accnum;
	
	cout<<"Please enter your password = ";
	cin>>password;
	
	if (password==123456) {
		
		cout<<"Menu ATM Bank ABC "<<endl;
		cout<< "1. View Balance \n2. Deposit \n3. Withdraw \n4. Transfer Fund"<<endl;
		cout<<"Your Choice = ";
		cin>>choice;
		
		switch (choice){
		case 1:
			cout<<"Your balance = "<<balance<<endl;
			break;
		case 2:
			cout<<"Enter the amount of deposit = ";
			cin>>amount;
			balance = balance + amount;
			cout<<"Your new balance is = "<<balance;
			break;
		case 3:
			cout<<"Enter the amount to withdraw = ";
			cin>>amount;
			if (amount<=balance){
			balance = balance - amount;
			cout<<"Your new balance is = "<<balance;}
			 else
			  cout<<"Insufficient amount to withdraw.";
			break;
		case 4:
			cout<<"Enter the account number (9-digits) = ";
			cin>>accnum;
			 if (accnum<1000000000 && accnum>99999999){
			   cout<<"Enter the amount of fund transfer = ";
			   cin>>amount;
			   if (amount<=balance){
			   balance = balance - amount;
			   cout<<amount<<" has been transfered to account "<<accnum<<".The current balance is "<<balance;}
			   else 
			   cout<<"Insufficient amount to transfer.";
			  }
			  
			else
				cout<<"Invalid account number."; 
			break;
		default :
			cout<<"Wrong choice.";
		 }
		
	}
	
	else 
	cout<<"Wrong Password. Please try again.";
	
	return 0;
}
