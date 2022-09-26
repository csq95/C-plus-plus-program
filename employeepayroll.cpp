#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
using namespace std;

class PaySlip{
	private:
		char payDate[100]; // The default date.
		int hours;
		double pay; // the calculated pay (including tax)
		double tax; // the calculated tax.
		int b;
	public:
		PaySlip(){
		}
		PaySlip(int hours,double pay,double tax){
			time_t curr_time;
			tm * curr_tm;
			time(&curr_time);
			curr_tm = localtime(&curr_time);
			char date_string [100];
			strftime(date_string, 50, "%B / %d / %Y", curr_tm);
			strcpy(payDate, date_string);
			
			this->hours=hours;
			this->pay=pay;
			this->tax=tax;
			b++;
		}
		virtual void toString(){
			cout<<payDate<<" "<<hours<<" h  $"<<pay<<" "<<tax<<endl;
			
		}
		void setPay(double pay){
			this->pay=pay;
		}
		double getPay(){
			return pay;
		}
};

class Employee{
	protected:
		string IDnumber;
		string name;
		double payRate;// hourly rate
		PaySlip pslip[5];// an array of Payslip objects
		int payIndex;// the index of the next entry in the pSlip array
		double YTDpay;// Year to Date pay amount
		double YTDtax;// Year to Date tax amount
		friend class PaySlip;
		int hours;
		double annualpay;
		double annualtax;
		double weeklytax;
		
	public:
		Employee(){
		}
		Employee(string IDnumber,string name,double payRate){
				this->IDnumber=IDnumber;
				this->name=name;
				this->payRate=payRate;
		}
		virtual void toString(){
			cout<<"ID: "<<IDnumber<<" "<<name<<" $"<<payRate<<"p/h"<<endl;
		}
		virtual void calcPay(){
			cout<<"Enter hours = ";
			cin>>hours;
			cout<<"Pay = "<<hours*payRate<<endl;
			payIndex++;
		}
		virtual double calcTaxWeekly(double total){
			annualpay=total*52;
			
			if (annualpay<=6000){
				weeklytax=0;
				return weeklytax;
			}
			else if (annualpay>6000){
				annualtax=(annualpay-6000)*0.2;
				weeklytax=(annualtax/52);
				return weeklytax;
			}
			else{
				cout<<"Wrong amount to calculate weekly tax."<<endl;
			}
		
		}
		void setID(string IDnumber){
			this->IDnumber=IDnumber;
		}
		string getID(){
			return IDnumber;
		}
};

class Permanent:public Employee{ //weekly paid employee
	private:
		double holidays;
		friend class PaySlip;
		int x;
	public:
		Permanent(){
		}
		Permanent(string IDnumber, string name, double payRate){
			this->IDnumber=IDnumber;
			this->name=name;
			this->payRate=payRate;	
			x=0;
		}
		virtual void toString(){
			Employee::toString();
			for(int i=0; i<x;i++){
				pslip[i].toString();}
			cout<<"YTD pay = \t$"<<YTDpay<<" $"<<YTDtax<<endl;
			cout<<"Holidays : "<<holidays*0.2<<"days"<<endl;
		}
		virtual void calcPay(){
			int p;
			p=40*payRate;
			cout<<"Pay = "<<p<<endl;
			YTDpay+=p;
			YTDtax+=Employee::calcTaxWeekly(p);
			cout<<"YTDpay = "<<YTDpay<<endl;
			cout<<"YTDtax = "<<YTDtax<<endl;
			PaySlip* newSlip = new PaySlip(40,p,Employee::calcTaxWeekly(p));
			pslip[x] = *newSlip;
			x++;
			holidays++;
		}
		string getID(){
			return IDnumber;
		}
};
class Casual:public Employee{ // hourly paid employee
	private:
		int z;
		friend class PaySlip;
		int x;
	public:
		Casual(){
		}
		Casual(string IDnumber, string name, double payRate){
			this->IDnumber=IDnumber;
			this->name=name;
			this->payRate=payRate;
			x=0;
		}
		virtual void toString(){
			Employee::toString();
			for(int i=0; i<x;i++){
				pslip[i].toString();}
			cout<<"YTD pay = \t$"<<YTDpay<<" $"<<YTDtax<<endl;
		}
		string getID(){
			return IDnumber;
		}
		virtual void calcPay(){
			int p;
			cout<<"Enter hours = ";
			cin>>hours;
			p=hours*payRate;
			cout<<"Pay = "<<p<<endl;
			YTDpay+=p;
			YTDtax+=Employee::calcTaxWeekly(p);
			cout<<"YTDpay = "<<YTDpay<<endl;
			cout<<"YTDtax = "<<YTDtax<<endl;
			PaySlip* newSlip = new PaySlip(hours,p,Employee::calcTaxWeekly(p));
			pslip[x] = *newSlip;
			x++;
		}
		
};
int main(){
	int option;
	int type;
	string IDnumber;
	string name;
	double payRate;// hourly rate
	double hours;
	vector <Employee*> e;
	int a;
	
	do {
		cout<<"------- Payroll Menu ------"<<endl;
		cout<<"1. Add an employee"<<endl;
		cout<<"2. Pay an employee"<<endl;
		cout<<"3. Display Employee pay details"<<endl;
		cout<<"4. exit."<<endl;
		cout<<"Enter option = ";
		cin>>option;
		
		switch (option){
		case 1 :
				cout<<"Please choose what kind of employee : "<<endl;
				cout<<"1. Permanent / 2. Casual "<<endl;
				cin>>type;
				 if (type==1){
			 		cout<<"Enter ID = "<<endl;
			 		cin>>IDnumber;
			 		cout<<"Enter name = "<<endl;
			 		cin>>name;
			 		cout<<"Enter PayRate = "<<endl;
			 		cin>>payRate;
			 		Employee *newemployee = new Permanent(IDnumber,name,payRate);
			 		e.push_back(newemployee);
			 		a++;
			 	 }
			 	else if(type==2){
			 		cout<<"Enter ID = "<<endl;
			 		cin>>IDnumber;
			 		cout<<"Enter name = "<<endl;
			 		cin>>name;
			 		cout<<"Enter PayRate = "<<endl;
			 		cin>>payRate;
			 		Employee *newemployee = new Casual(IDnumber,name,payRate);
			 		e.push_back(newemployee);
			 		a++;
				 }
				else {
					cout<<"No such type of employee..."<<endl;
					break;
				 }
		break;
		
		case 2 :
				cout<<"Enter Employee ID = "<<endl;
				cin>>IDnumber;
				for(int i=0;i<a;i++){
					if (e[i]->getID()==IDnumber){
						e[i]->calcPay();
					}		
					else 
						continue;
				}
		break;
		
		case 3 :
			for(int i=0;i<e.size();i++){
			e[i]->toString();
			cout<<endl;}
		break;
		
		case 4 :
			break;
			
		default :
			cout<<"Wrong option,Please enter again..."<<endl;
	}
		
	} while (option!=4);
	
	return 0;
}
