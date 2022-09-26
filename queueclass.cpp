#include <iostream>
using namespace std;

class Queue{
	private :
		int rear;
		int front;
		int queue[5];
		
	public :
		Queue(){
			rear=0;
			front=0;
		}
		
		int insert(int x){
			if(rear==sizeof(queue)-1){
				cout<<"FULL"<<endl;
			}
			 else {
				queue[rear]=x;
				rear++;
			}
		}

		void deletefront(){
			if (front>rear||front==rear){
				cout<<"THIS IS AN EMPTY ARRAY"<<endl;
			}
			 else {
				cout<<"Value "<<queue[front]<<" is deleted."<<endl;
				front++;
			}
		}

		void display(){
			cout<<"Display = "<<endl;
			for(int i=front;i<rear;i++){
			cout<<queue[i]<<endl;
			}
		}
};

int main(){
	Queue q1;
	q1.deletefront();
	q1.insert(1);
	q1.display();
	q1.insert(2);
	q1.display();
	q1.deletefront();
	q1.insert(3);
	q1.display();
	q1.insert(4);
	q1.display();
	q1.insert(5);
	q1.display();
	q1.deletefront();
	q1.display();
	return 0;
}
