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

class Ring{
	private:
		node *head;
		int length;
	public:
		Ring(){
			length=0;
			head=NULL;
			//head->next=head;
		}
		~Ring(){
			head=NULL;
			delete head;
		}
		
		
		
		void Copy(Ring r){
			node *temp=r.head;
			this->add(r.head->data);
			while(temp->next!=r.head){
				temp=temp->next;
				this->add(temp->data);				
			}
		}
		
		void print(){
			node *temp=head;
			cout<<"List is printed below: "<<endl;
			while(temp->next!=head){
				cout<<"<====>"<<temp->data;
				temp=temp->next;
			}
			cout<<"<====>"<<temp->data;
			cout<<endl;
		}
		
		void Clear(){
			for(int i=0;i<=length;i++){
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
				length++;
				return;
			}
			node *temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			node *temp1=new node(val);
			temp1->next=temp->next;
			temp->next=temp1;
			length++;	
		}
		
		
		
		void addAt(int val,int pos){
			if(pos>length+1 || pos<=0){
				cout<<"wrong position"<<endl;
				return;
			}
			if(pos==1){
				node *t=head; node *t1=head;
				while(t1->next!=head){
					t1=t1->next;
				}
				head=new node(val);
				head->next=t;
				t1->next=head;
				length++;
				return;
			}
			
			node *temp=head;
			for(int i=1;i<pos-1;i++){
				temp=temp->next;
			}
			node *temp1=new node(val);
			temp1->next=temp->next;
			temp->next=temp1;
			length++;
			
		}
		
		
		
		void Remove(){
			if(head==NULL){
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
			node *temp1;
			node *temp=head;
			while(temp->next!=head){
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=temp->next;
			delete temp;
			length--;			
		}
	
	
	
		void RemoveAt(int pos){
			if(pos>length || pos<1){
				cout<<"wrong position"<<endl;
				return;
			}
			if(pos>1){
				node *temp1,*temp=head;
				for(int i=1;i<pos;i++){
					temp1=temp;
					temp=temp->next;
				}
				temp1->next=temp->next;
				delete temp;
				length--;
			}
			else if(pos==1){
				node *temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				if(length>1){
					node *temp1=temp->next;
					temp->next=temp->next->next;
					head=temp1->next;
					delete temp1;
					length--;
				}
				else{
					head=NULL;
					delete temp;
					length--;
				}
			}
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
};

int main(){
	Ring r,r1; r.add(67); r.add(89); r.addAt(3,3); r.addAt(45,1); r.RemoveAt(2); r1.Copy(r); //r.Clear(); r.Update(78,2); 
	//r.get(); r.get(); r1.get(); r1.get();
	r.print(); r1.print();
	cout<<"bh";
	return 0;
}
