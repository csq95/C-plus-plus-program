#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int country;
	float msia;
	long amount;
	
	
	do{
	cout<<"Welcome to Currency Converter!"<<endl;
	cout<<"Please enter the number that represent the country: "<<endl;
	cout<<"1. USD \n2. AUB \n3. GBP \n4. EUR \n5. RMB \n6. JPY \n7. THB \n8. SGD \n9. Exit "<<endl;
	cin>>country;
	cout<<"Please enter the amount = ";
	cin>>amount;
	
	switch (country) {
	
		case 1 :
			msia=amount*4.1842313;
			cout<<amount<<" USD = "<<msia<<" MYR"<<endl;
			break;
		case 2 :
			msia=amount*3.0474045;
			cout<<amount<<" AUB = "<<msia<<" MYR"<<endl;
			break;
		case 3 :
			msia=amount*5.6862416;
			cout<<amount<<" GBP = "<<msia<<" MYR"<<endl;
			break;
		case 4 :
			msia=amount*4.833468;
			cout<<amount<<" EUR = "<<msia<<" MYR"<<endl;
			break;
		case 5 :
			msia=amount*0.64850458;
			cout<<amount<<" RMB = "<<msia<<" MYR"<<endl;
			break;
		case 6 :
			msia=amount*0.037517282;
			cout<<amount<<" JPY = "<<msia<<" MYR"<<endl;
			break;
		case 7 :
			msia=amount*0.122377114;
			cout<<amount<<" THB = "<<msia<<" MYR"<<endl;
			break;
		case 8 :
			msia=amount*3.0785846;
			cout<<amount<<" SGD = "<<msia<<" MYR"<<endl;
			break;
		default :
			cout<<"Invalid number. \nPlease try again. \nThanks"; };
	
		} while (country!=9);
		
	
	return 0;
}
