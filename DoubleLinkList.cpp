#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node *prev;
		node(int data){
			this->data=data;
			next=NULL;
			prev=NULL;
		}
};

class DoubleList{
	private:
		int length;
		node* head;
	public:
		DoubleList(){
			length=0;
			head=NULL;
		}
		~DoubleList(){
			head=NULL;
			delete head;
		}
//		
		void add(int numb){
			if(head==NULL){
				head=new node(numb);
				head->next=NULL;
				length++;}
			else{
				node *temp=head;
				while(temp->next!=NULL){
					temp=temp->next;}
				node *temp1;
				temp1=new node(numb);
				temp->next=temp1;
				temp1->prev=temp;
				length++;}	}
		
		
		
		
		void addAt(int numb,int pos){
			if(pos>length+1){
				cout<<"list is not big enough"<<endl;
				return;}
				
			else if(pos==1){
				if(head==NULL){
					node *temp=new node(numb);
					head=temp;
					head->next=NULL;
					length++;}
				else{
					node *temp=new node(numb);
					temp->next=head;
					temp->prev=NULL;
					head=temp;
					length++; } }
			else{
				node *temp=head;
				for(int i=1;i<pos-1;i++){
					temp=temp->next;}
				node *temp1=new node(numb);
				temp1->next=temp->next;
				if(temp1->next!=NULL) temp1->next->prev=temp1;
				temp->next=temp1;
				temp1->prev=temp; length++;}	}
		
		
		
		
		void remove(){
			node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;	}
			if(temp->prev!=NULL)temp->prev->next=NULL;
			else if(temp->prev==NULL)head=NULL;
			delete temp;
			length--;	}
		
		
		
		
		void removeAt(int pos){
			if(pos>length){
				cout<<"list is not long enough for this deletion"<<endl;
				return;}
			node *temp=head;
			for(int i=1;i<pos;i++){
				temp=temp->next;}
			if(temp->next!=NULL){
				if(temp->prev!=NULL){temp->prev->next=temp->next; }
				else{ this->head=temp->next; head->prev=NULL; }
				
				temp->next->prev=temp->prev;}
			else if(temp->next==NULL){
				
				if(temp->prev!=NULL){ temp->prev->next=NULL; }
				else{
					this->head=temp->next; head->prev=NULL; }	}
			delete temp;
			length--;	}
	
	
		
		void Update(int val,int pos){
			if(pos>length) return;
			node *temp=head;
			for(int i=1;i<pos;i++){
				temp=temp->next;	}
			temp->data=val;	}
		
		
		
		void Copy(DoubleList d){
			if(d.head==NULL){
				cout<<"empty to copy"<<endl;
				return;}
			node *te=d.head;
			//this->add(temp->data);
			for(int i=1;i<d.length;i++){
				this->add(te->data);
				te=te->next;} 
			this->add(te->data);
			cout<<d.head->data;	}
		
		
		
		void Clear(){
			int num=length;
			for(int i=0;i<num;i++){
				remove();}	}
		
		
		
		void get(){
			cout<<"Enter position you want to get? ";
			int pos; cin>>pos;
			if(pos>length || pos<1){
				cout<<"List not have this position"<<endl;
				return;}
			node * temp=head;
			for(int i=1;i<pos;i++){
				temp=temp->next;	}
			cout<<"Your number is: "<<temp->data<<endl;}
		
		
		
		void Find(){
			cout<<"Enter numb for search? ";
			int numb,pos=1; cin>>numb;
			node *temp=head;
			if(temp->data==numb){
				cout<<"your numb on position "<<1<<endl;
					return;}
			while(temp->next!=NULL){
				temp=temp->next; pos++;
				if(temp->data==numb){
					cout<<"your numb on position "<<pos<<endl;
					return;}	}
			cout<<"your numb is not in list"<<endl;    }
		
		
		
		void print(){
			if(head==NULL){
				cout<<"Nothing to print in the list."<<endl;}
			else{
				cout<<"The list is printed below:"<<endl;
				node *temp=this->head;
				for(int i=1;i<length;i++){
					cout<<" <====> "<<temp->data;
					temp=temp->next;	}
				cout<<" <====> "<<temp->data;
				cout<<endl;}	}
		
		void OddEven(){
			DoubleList E,O;
			node *temp=head;
			while(temp!=NULL){
				if(temp->data%2==0){
					E.add(temp->data);
				}
				else if(temp->data%2!=0){
					O.add(temp->data);
				}
				temp=temp->next;	}
			cout<<"Printing Even list"<<endl;
			E.print();
			cout<<"Printing Odd list"<<endl;
			O.print();
		}
		
		bool IsSorted(){
			node *temp=this->head;
			if(head==NULL || head->next==NULL) return true;
			while(temp->next!=NULL){
				temp=temp->next;
				if( !(temp->prev->data < temp->data) ){
					if(temp->prev->data != temp->data){
						return false;}	}
			}
			return true;
		}
		
		void split(){
			if(this->length<2){
				cout<<"Not big enough"<<endl;
				return;
			}
			DoubleList F,B;
			node *temp=head;
			int front,back;
			if(this->length%2==0){
				front=length/2;
				back=front;
			}
			else if(this->length%2!=0){
				front = (length/2)+1 ;
				back=length/2;
			}
			for(int i=0;i<front;i++){
				F.add(temp->data);
				temp=temp->next;
			}
			if(back==1) B.add(temp->data);
			else{
				for(int i=0;i<back-1;i++){
				B.add(temp->data);
				temp=temp->next;}
				B.add(temp->data);	}
			cout<<"Printing Front half: ";
			F.print();
			cout<<"Printing Back half: ";
			B.print();
			
		}
		
		
};
int main(){
	DoubleList l;
	l.addAt(45,1); 
	l.add(67); 
	l.addAt(67,3); 
	l.addAt(89,4);
	l.add(867);
	l.print();
	cout<<endl;
	if(l.IsSorted()) cout<<"List is sorted"<<endl;
	else cout<<"List not sorted"<<endl;
	//l.OddEven();
	l.split();
	
	return 0;
}
