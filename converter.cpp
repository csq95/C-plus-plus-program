#include <iostream>
#include<iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void msia(float,int);
int main(int argc, char** argv) {
	int country;
	float amount;
	cout<<"Welcome to Currency Converter!"<<endl;
do{
	cout<<"       Country Menu "<<endl;
	cout<<"*******************************"<<endl;
	cout<<"1. USD \n2. AUB \n3. GBP \n4. EUR \n5. RMB \n6. JPY \n7. THB \n8. SGD \n9. Exit "<<endl;
	cout<<"Please enter the number that represent the country: "<<endl;
	cin>>country;
	cout<<"Enter Amount = ";
	cin>>amount;
	switch (country) {
	
		case 1 :
			country=4.1842313;
			msia(amount,country);
			break;
		case 2 :
			country=3.0474045;
			msia(amount,country);
			break;
		case 3 :
			country=5.6862416;
			msia(amount,country);
			break;
		case 4 :
			country=4.833468;
			msia(amount,country);
			break;
		case 5 :
			country=0.64850458;
			msia(amount,country);
			break;
		case 6 :
			country=0.037517282;
			msia(amount,country);
			break;
		case 7 :
			country=0.122377114;
			msia(amount,country);
			break;
		case 8 :
			country=3.0785846;
			msia(amount,country);
			break;
		case 9 :
			cout<<"Have a nice day!";
		default :
			cout<<"Invalid number. \nPlease try again. \nThanks"; };
	
		} while (country!=9);

		
	return 0;
}

void msia (float amount, int country ){
	float msia;
	msia=amount*country;
	cout<<amount<<" $ = "<<msia<<" MYR"<<fixed<<setprecision(2);

}
