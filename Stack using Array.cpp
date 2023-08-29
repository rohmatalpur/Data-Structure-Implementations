#include<iostream>
using namespace std;

class Stack{
	private:
	int *arr;
	int size;
	int noOfElements;
	int top;
	public:
	Stack(int size){
		this->size=size;
		arr=new int[size];
		top=-1;
	}
	~Stack(){
		delete []arr;
	}
	
	void push(int val){
		if(top==size-1){
			cout<<"Stack overflow"<<endl;
			return;
		}
		arr[++top]=val;
		noOfElements++;
	}
	
	int pop(){
		if(top== -1){
			cout<<"Stack underflow"<<endl;
			return 0;
		}
		else
		return arr[top--];
	}
	
//	int peek(){
//		if(top== -1)
//	}

	void display(){
		int x=0;
		for(int i=top;i>=0;i--){
			cout<<"Item "<<++x<<" : "<<arr[i]<<endl;
		}
	}
};
int main(){
	Stack stack1(5);
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);
	stack1.push(6);
	stack1.display();
	stack1.pop();
	stack1.display();
	return 0;
}
