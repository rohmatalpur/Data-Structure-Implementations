#include<iostream>
using namespace std;

class queue{
	private:
		int *arr;
		int l;
		int s;
		int front,rear;
	public:
		queue(int size){
			arr=new int[size];
			s=size; l=0; front=rear=-1;
		}
		void enqueue(int val){
			if(l==s){
				cout<<"Queue overflow";
				return;
			}
			arr[++rear]=val;
			//l++;
			if(l==0){
				front=rear;
			}
			l++;
		} 
   
    	int dequeue(){
    		if(l== 0){
				cout<<"Queue underflow,return -1 ";
				return -1;
			}
			if(l== 1){
				rear=-1;
				return arr[front++];
			}
			l--;
			return arr[front++];
		}
		
    	void display(){
    		if(l==0){
    			cout<<"Empty"<<endl;
    			return;
			}
    		cout<<"Printing queue:  ";
    		for(int i=front;i<=rear;i++){
    			cout<<arr[i]<<"   ";
			}
			cout<<endl;
		}
};

int main(){
	queue q(3);
	q.display(); q.dequeue(); q.enqueue(32); q.enqueue(678); q.dequeue(); q.display();
	return 0;
}
