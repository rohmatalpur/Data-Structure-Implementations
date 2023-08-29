//stack using array
#include<iostream>
using namespace std;

class stack{
	int *arr;
	int *top;
	int length;
	int size;
	public:
		stack(int size){
			this->size=size;
			arr=new int[size];
			top=arr;
			length=0;
		}
		void push(int val){
			if(length==size){
				cout<<"Stack is Overflow"<<endl;
				return;
			}
			else{
				if(length==0){
					*top=val;
					//top++;
					length++;
				}
				else{
					*++top=val;
					length++;
				}
			}
		}
		int pop(){
			if(length==0){
				cout<<"Stack underflow,returning -1"<<endl;
				return -1;
			}
			else{
				length--;
				return *top--;
			}
		}
		int peek(){
			if(length==0){
				cout<<"Stack empty,returning -1"<<endl;
				return -1;
			}
			else{
				return *top;
			}
		}
		
		void display(){
			if(length==0){
				cout<<"Nothing to print here"<<endl;
				return;
			}
			int *temp=top;
			cout<<"Printing stack:  ";
			for(int i=1;i<length;i++){
				cout<< *temp-- <<"    ";
			}
			cout<< *temp <<"    ";
		}
		void merge(stack S1){
			if(size>=length+S1.length){
				int var;
				for(int i=0;i<=S1.length;i++){
					var=S1.pop();
					push(var);
				}
			}
			else{
				cout<<"this stack is not big enough for this merging"<<endl;
			}
		}
		
		void reverse(){
			int *arr=new int[this->length];
			int l=length;
			int *include=arr; int var;
			int *exclude=arr;
			for(int i=0;i<l;i++){
				*include++ = this->pop();
			}
			for(int i=0;i<l;i++){
				var=*exclude++;
				this->push(var);
			}	
		}
		
		void sort(){
			int *arr=new int[this->length];
			int l=length;
			int *include=arr; 
			int var, min,temp;
			int *exclude=arr;
			for(int i=0;i<l;i++){
				*include++ = this->pop();
			}
			
			for(int i=0;i<l;i++){
				min=arr[i];
				for(int j=i;j<l;j++){
					if(min<arr[j]){
						temp=arr[j];
						arr[j]=min;
						min=temp;
						arr[i]=min;
					}
				}
			}
			
			for(int i=0;i<l;i++){
				var=*exclude++;
				this->push(var);
			}	
		}
};

int main(){
	stack s(3),s1(5);
	s.peek(); s.pop(); s.display(); s.push(45); s.push(98); 
	s.display();
	s1.push(5); s1.push(23); s1.merge(s); s1.display(); s1.reverse(); s1.display(); cout<<endl;
	s1.sort(); s1.display();
	return 0;
}
