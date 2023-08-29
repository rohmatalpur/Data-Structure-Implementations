#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};
class Queue{
	private:
		node* front;
		node* rear;
		node* t;
		int len;
		int cap;
	public:
		Queue(int size){
			front=rear=t=NULL;
			cap=size;
			len=0;
		}
		~Queue(){
			delete front;
			delete rear;
			delete t;
		}
		void merge(Queue q){
			if(cap<len+q.len){
				return;
			}
			int ll=q.len; int data;
			for(int i=0;i<ll;i++){
				data=q.dequeue();
				this->enqueue(data);
			}
		}
		
		void reverse(){
			int arr[len];
			int ll=len; int data;
			for(int i=0;i<ll;i++){
				arr[i]=dequeue();
				//this->enqueue(data);
			}
			for(int i=ll-1;i>=0;i--){
				this->enqueue(arr[i]);
			}
		}
		
		void enqueue(int val);
		int dequeue();
		void print();
};

void Queue::enqueue(int val){
	if(front==NULL){
		rear=new node;
		rear->data=val;
		rear->next=NULL;
		front=rear;
		len++;
		return;
	}
	if(len<cap){
		rear->next=new node;
		rear=rear->next;
		rear->data=val;
		rear->next=NULL;
		len++;
		return;
	}
	else{
		cout<<"OverFlow!"<<endl;
		return;
	}
}
int Queue::dequeue(){
	if(front==NULL){
		cout<<"UnderFlow!,returning -1"<<endl;
		return -1;
	}
	t=front;
	front=front->next;
	int data=t->data;
	delete t;
	t=NULL;
	len--;
	return data;
}

void Queue::print(){
	cout<<"Queue: ";
	t=front;
	cout<<"Front  ";
	while(t!=NULL){
		cout<<t->data<<"<-";
		t=t->next;
	}
	cout<<"  Rear"<<endl;
	return;
}

int main(){
	Queue q(5),q1(3);
	q.enqueue(34); q.enqueue(4); q1.enqueue(84); q1.enqueue(56); q.print(); q1.print(); q.merge(q1); q.print(); q.reverse(); q.print();
}
