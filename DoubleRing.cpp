#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node *prev;
		node(int data){
			this->data=data;
			next=prev=NULL;
		}
};

class DoubleRing{
	private:
		node *head;
		int length;
	public:
		DoubleRing(){
			length=0;
			head=NULL;
		}
		~DoubleRing(){
			head=NULL;
			delete head;
		}
		
		
		
		void Copy(DoubleRing r){
			if(r.length>0){
				node *temp=r.head;
				this->add(r.head->data);
				while(temp->next!=r.head){
					temp=temp->next;
					this->add(temp->data);				
				}
			}
		}
		
		
		
		void Clear(){
			int numb=length;
			for(int i=0;i<numb;i++){
				this->Remove();
			}
		}
		
		
		
		void get(){
			cout<<"Enter position to get number? "; 
			int pos;
			cin>>pos;
			if(pos>length || pos<1){
				cout<<"wrong position"<<endl;
				return;
			}
			node *temp=head;
			for(int i=1;i<pos;i++){
				temp=temp->next;
			}
			cout<<"Number at "<<pos<<" is "<<temp->data<<endl;
		}
		
		
		
		void add(int val){
			if(head==NULL){
				head=new node(val);
				head->next=head;
				head->prev=head;
				length++;
				return;
			}
			node *temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=new node(val);
			temp->next->prev=temp;
			temp->next->next=head;
			head->prev=temp->next;
			length++;			
		}
		
		
		void addAt(int val,int pos){
			if(pos>length+1 || pos<1){
				cout<<"Wrong position"<<endl;
				return;
			}
			if(pos==1){
				node *temp1=new node(val);
				temp1->next=head->next;
				head->next->prev=temp1;
				head->next=temp1;
				temp1->prev=head;
				head=temp1;
				length++;
				return;
			}
			node *temp=head;
			for(int i=1;i<pos-1;i++){
				temp=temp->next;
			}
			node *temp1=new node(val);
			temp1->next=temp->next;
			temp->next->prev=temp1;
			temp->next=temp1;
			temp1->prev=temp;
			length++;
		}
		
		
		
		void Remove(){
			if(length<1){
				cout<<"Nothing to remove"<<endl;
				return;
			}
			if(length==1){
				node *temp=head;
				head=NULL;
				delete temp;
				length--;
				return;
			}
			node *temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			temp->next=temp->prev=temp;
			delete temp;
			length--;}
	
	
	
		void RemoveAt(int pos){
			if(pos>length || pos<1){
				cout<<"wrong position"<<endl;
				return;
			}
			if(pos>1){
				node *temp=head;
				for(int i=1;i<pos;i++){
					temp=temp->next;
				}
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
				length--;
			}
			else if(pos==1){
				node *temp=head;
				if(length>1){
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					delete temp;
					length--;
				}
				else{
					head=NULL;
					delete temp;
					length--;
				}
			}
		}
		
		void RemoveThis(int numb){
			node *temp=head;
			if(numb==temp->data){
				head=temp->next;
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				temp=NULL;
				delete temp;
				length--;
				return;
			}
			do{
				if(temp->data==numb){
					temp->next->prev=temp->prev;
					temp->prev->next=temp->next;
					temp=NULL;
					delete temp;
					length--;
					return;
				}
				temp=temp->next;
			}while(temp!=head);
			return;
		}
	
	
		void print(){
			if(length<1){
				cout<<"Nothing to print"<<endl;
				return;
			}
			node *temp=head;
			cout<<"List is printed below: "<<endl;
			while(temp->next!=head){
				cout<<"<====>"<<temp->data;
				temp=temp->next;
			}
			cout<<"<====>"<<temp->data;
			cout<<endl;
		}
		
		
	
		void Update(int val,int pos){
			if(pos>length || pos<1){
				cout<<"wrong position"<<endl;
				return;
			}
			node *temp=head;
			for(int i=1;i<pos;i++){
				temp=temp->next;
			}
			temp->data=val;
		}
		
		
		
		void Find(){
			cout<<"Enter numb to find? ";
			int numb,count=1,yes=0;
			cin>>numb;
			if(head==NULL){
				cout<<"ring is empty"<<endl;
				return;
			}
			node *temp=head;
			if(temp->data==numb){
				cout<<"your numb is at position: "<<count<<endl;
				yes=1;
			}
			while(temp->next!=head){
				temp=temp->next;
				count++;
				if(temp->data==numb){
				cout<<"your numb is at position: "<<count<<endl;
				yes=1;
				}
			}
			if(yes!=1) cout<<"your number is not in ring"<<endl;
		}
		
		void Joseph(){
			DoubleRing C;
			C.Copy(*this);
			cout<<"Enter count for delete: ";
			int numb,i; cin>>numb;
			node *temp=C.head;
			while(C.head->next!=C.head){
				for(i=0;i<numb;i++){
					temp=temp->next;
				}
				C.RemoveThis(temp->data);
			}
			C.print();
		}
		
};

int main(){
	DoubleRing d,d1; 
	d.add(67); d.add(78); d.addAt(787,2); d.addAt(56,4); //d.Update(56,7); d.Update(10,4); 
	d.RemoveThis(67);
	d.add(23); d.add(908);
	d.add(11); d.add(0);
	d.add(45); d.add(33);
	d.add(431); d.add(123);
	d.add(453); d.add(431);
	d.print();
	d.Joseph();
//	char ch='y';
//	int n,opt; 
//	while(ch=='y' || ch=='Y'){
//		cout<<"Choose:  1 (insert at beginning): "<<endl;
//		cout<<"         2 (delete at end): "<<endl;
//		cout<<"         3 (print): "<<endl;
//		cin>>opt;
//		switch(opt){
//			case 1:
//				cout<<"Insert number to add: ";
//				cin>>n;
//				d.add(n);
//				break;
//			case 2:
//				d.Remove();
//				break;
//			case 3:
//				d.print();
//				break;
//			default:
//				cout<<"Wrong option"<<endl;
//		}
//		cout<<"Do you want to continue 'y/n': ";
//		cin>>ch;		
//	}
	return 0;
}
