#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int data){
			this->data=data;
			next=NULL;
		}
};
class queue{
	private:
		node *front,*rear,*t;
		int l;
		int s;
		
	public:
		queue(int size){
			s=size; l=0; front=rear=t=NULL;
		}
		void enqueue(int val){
			if(l==s){
				cout<<"Queue overflow";
				return;
			}
			if(front==NULL){
				front=rear=new node(val);
				rear->next=NULL;
				l++;
				return;
			}
			else{
				t=new node(val);
				rear->next=t;
				rear=t;
				rear->next=NULL;
				l++;
				return;
			}
		} 
   
    	int dequeue(){
    		if(front==NULL){
				cout<<"Queue underflow,return -1 ";
				return -1;
			}
			if(front==rear){
				t=front;
				front=rear=NULL;
				l--;
				return t->data;
			}
			else{
				t=front;
				front=front->next;
				int d=t->data;
				delete t;
				return d;
			}
		}
		
    	void display(){
    		if(front==NULL){
    			cout<<"Empty"<<endl;
    			return;
			}
    		cout<<"Printing queue:  ";
    		t=front;
    		while(t!=rear->next){
    			cout<<t->data<<"  ";
    			t=t->next;
			}
			cout<<endl;
		}
};

int main(){
	queue q(3);
	q.display();  q.enqueue(32); q.enqueue(678); q.dequeue(); q.display();
	return 0;
}
