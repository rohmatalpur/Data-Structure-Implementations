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
		node *head;
		
	public:
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
		
		void print(){
		if(head==NULL){
			cout<<"Nothing to print"<<endl; return;
		}
		node* temp=head;
		while(temp->next!=NULL){
			cout<<temp->data<<"  ";
			temp=temp->next;
		} cout<<temp->data<<"  ";	
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
		
		void Copy(List l){
			node *temp=l.head;
			while(temp->next!=NULL){
				add(temp->data);
				temp=temp->next;
			}
		}
		
		void Clear(){
			int numb=length;
			for(int i=0;i<numb;i++){
				Remove();
			}
		}
		
		void get(){
			int position;
			cout<<"Enter position of element you want to get from list: ";
			cin>>position;
			if(position<=length){
				node* temp;
				temp=head;
				for(int i=0;i<position;i++){
					if(i==position-1){
						cout<<"your number is "<<temp->data<<endl;
						break;
					}
					temp=temp->next;
				}
			}
			else if(position>length){
				cout<<"Sorry list is not that big"<<endl;
			}
		}
		void add(int val){
			if(head==NULL){
				head=new node(val);
				head->next=NULL;
			}
			else{
				node *temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=new node(val);
				temp->next->next=NULL;
			}
			length++;	
		}
		
		void addAt(int val,int position){
			if(position==1){
				node* temp=new node(val);
				temp->next=head;
				head=temp;
				return;
			}
			node *temp=head;
			for(int i=1;i<position-1;i++){
				if(temp->next==NULL){
					cout<<"Invalid position"<<endl;
					return;
				}
				temp=temp->next;
			}
			
			node* temp1=temp;
			node* t=new node(val);
			temp->next=t;
			t->next=temp1->next;
			length++;	
		}
	void Remove(){
		if(head==NULL){
			cout<<"List is empty to remove"<<endl;
			return;	
		}
		node *temp=head; 
		node *temp1;
		if(temp->next==NULL){
			delete temp;
			length--;
			return;
		}
		else{
			for(int i=0;i<length;i++){
				temp1=temp;
				temp=temp->next;
			}
			delete temp;
			temp1->next=NULL;
			length--;
		}
	}
	
	void RemoveAt(int position){
		if(head==NULL){
			cout<<"List is empty to remove"<<endl;
			return;	
		}
		else{
			node *temp=head; node *temp1;
			for(int i=1;i<position;i++){
				if(temp->next==NULL){
					cout<<"Invalid position"<<endl;
					return;
				}
				temp1=temp;
				temp=temp->next;
			}
			if(temp->next==NULL){
				temp1->next=NULL;
			}
			else{
				temp1->next=temp->next;
			}
			delete temp;
			length--;
		}
	}
	
	
	void Update(int val,int position){
			node *temp=head;
			for(int i=1;i<position;i++){
				if(temp->next==NULL){
					cout<<"Invalid position for update"<<endl;
					return;
				}
				temp=temp->next;
			}
			temp->data=val;	
		}
		void Find(){
			int numb,count=0;
			cout<<"What do you want to find in list ?";
			cin>>numb;
			node *temp=head;
			while(temp->next!=NULL){
				count++;
				if(temp->data==numb){
					cout<<"Yes your number is on "<<count<<" position."<<endl;
					return;
				}
				temp=temp->next;
			}
			cout<<"Number is not in list"<<endl;
		}
		
		void move(){
			node* temp=this->head; node* tempp=head;
			while(temp->next!=NULL){
				tempp=temp;
				temp=temp->next;
			}
			int temp1=temp->data;
			tempp->next=NULL;
			this->addAt(temp1,1);
		}
};
int main(){
	List l1,l2; l1.add(2); l1.add(100); l1.add(56); l1.add(-87); 
//	l1.get(); 
//	l1.addAt(765,5); l1.RemoveAt(2); l1.get(); l1.Remove(); l1.get(); l1.Update(22,2); 
//	l2.Copy(l1);  l2.get(); l2.get(); l2.get();  l2.Clear(); l2.get(); l1.Find();
l1.print(); l1.move(); l1.print();
	return 0;
}
