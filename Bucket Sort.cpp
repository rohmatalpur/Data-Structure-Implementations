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

class List{
	private:
		node *curr;
		int length;
		//node *head;
		
	public:
		node *head;
		List(){
			head=NULL;
			length=0;
		}
		~List(){
			delete head;
		}
		int GetLength(){
			return length;
		}
//		void back(){
//			curr--;
//		}
//		void next(){
//			curr++;
//		}
//		void start(){
//			curr=head;
//		}
//		void tail(){
//			curr=head+length;
//		}
		
		
		node* add(int val,node* r){
			if(r==NULL){
				if(head==NULL){
					head=new node(val);
					head->next=NULL;
				}
				else{
					r=new node(val);
					r->next=NULL;
				}
				length++;
				return r;
			}
			else if(r->data > val){
				node* temp=new node(val);
				temp->next=r;
				length++;
				if(r==head) head=temp;
				return temp;
			}
			r->next = add(val,r->next);
		}
		

		void print(){
			node* temp=head;
			while(temp->next!=NULL){
				cout<<temp->data<<"  ";
				temp=temp->next;
			}
			cout<<temp->data<<"  ";
		}
	
};
int main(){
	List l[10];
	int arr[18]={34,543,754,345,23,2,5,24,257,76,443,76,66,54,77,432,75,345};
	for(int i=0;i<18;i++){
		if(arr[i]<100){
			l[1/10].add(arr[i],l[1/10].head);
		}
		else{
			l[1/100].add(arr[i],l[1/10].head);
		}
	}
	for(int i=0;i<10;i++){
		if(l[i].head!=NULL) l[i].print();
	}
	return 0;
}
