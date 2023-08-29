#include<iostream>
using namespace std;


class node{
	public:
		node *previous;
		int data;
		node(int val){
			data=val;
			previous=NULL;
		}
};

class stack{
	private:
		node *top;
		int length;
		int size;
	public:
		stack(){
			top=NULL;
			length=0;
			size=10;
		}
		
		void push(int val);
		void display();
		int pop();
		
		int peek(){
			return top->data;
		}
		bool IsEmpty();
		int getlength();
		void setSize(int size){
			this->size=size;
		}
};
int main(){
	stack stack1,stack2;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);
	stack1.push(6);
	stack1.pop();
	stack1.display();
	cout<<endl<<"Stack size "<<stack1.getlength()<<endl;
	return 0;
}                                                                       

bool stack::IsEmpty(){
	if(length==0)
		return true;
	else
		return false;
}

int stack::pop(){
	if(IsEmpty()){
		cout<<"List is empty: Stack under flow, return -1"<<endl;
		return -1;
	}
	else{
		node *curr=top;
		int data=curr->data;
		top=curr->previous;
		delete curr;
		length--;
		return data;
	}
}

void stack::push(int val){
	if(length<size){
		node *t=new node(val);
		if(top==NULL){
			top=t;
			length++;
		}
		else{
			t->previous=top;
			top=t;
			length++;
		}
	}
	else{
		cout<<"Stack full: overflow"<<endl;
	}
}

void stack::display(){
	node *curr=top;
	while(curr!=NULL){
		cout<<"Node: "<<curr->data<<endl;
		curr=curr->previous;
	}
}

int stack::getlength(){
	return length;
}