#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *prev;
	node(int data){
		this->data=data;
		prev=NULL;
	}
};

class Stack{
	private:
		node *top;
		int l;
		int s;
	public:
		Stack(int size){
			s=size;
			l=0;
			top=NULL;
		}
		void push(int val){
			if(l==s){
				cout<<"stack overflow"<<endl;
				return;
			}
			node *t=new node(val);
			if(l==0){
				top=t;
				t->prev=NULL;
			}
			else{
				t->prev=top;
				top=t;
			}
			l++;
		}
		
		void pop(){
			if(l==0){
				cout<<"stack underflow"<<endl;
				return;
			}
			node *curr=top;
			top=top->prev;
			delete curr;
			l--;
		}
		
		int peek(){
			if(l==0){
				cout<<"stack underflow,return -1"<<endl;
				return -1;
			}
			return top->data;
		}
		
		void display(){
			if(l==0){
				cout<<"Nothing to print"<<endl;
				return;
			}
			node *curr=top;
			for(int i=0;i<l;i++){
				cout<<curr->data<<"   ";
				curr=curr->prev;
			}
			cout<<endl;
		}
		void merge(Stack S){
			if(s<l+S.l){
				cout<<"Stack not long for merging"<<endl;
				return;
			}
			int ll=S.l; int val;
			for(int i=0;i<ll;i++){
				val=S.peek();
				S.pop();
				this->push(val);
			}
		}
		
		void reverse(){
			int arr[this->l]; 
			int ll=l;
			for(int i=0;i<ll;i++){
				arr[i]=peek();
				pop();
			}
			for(int i=0;i<ll;i++){
				push(arr[i]);
			}
		}
		
		void sort(){
			int arr[l]; //cout<<l<<endl; 
			int ll=l; int min,temp;
			for(int i=0;i<ll;i++){
				arr[i]=peek();
				pop();
			}
			for(int i=0;i<ll;i++){
				min=arr[i];
				for(int j=i;j<ll;j++){
					if(min>arr[j]){
						temp=arr[j];
						arr[j]=arr[i];
						min=temp;
						arr[i]=min;	
					}
				}
			}
			for(int i=0;i<ll;i++){
				push(arr[i]);
			}
		}
};

int main(){
	Stack s(4);
	s.push(1); s.push(4); s.push(555); s.push(95);   s.display(); s.reverse(); s.display(); s.sort(); s.display();
	return 0;
}
