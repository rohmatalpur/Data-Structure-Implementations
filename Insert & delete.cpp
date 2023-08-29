#include<iostream>
using namespace std;
class node1{
		public:
		int numb;
		int count;
		node1* next;
		node1(int n){
			numb=n;
			count=1;
			next=NULL;
		}
	};
class LinkList{
	public:
	node1 *head;
	LinkList(){
		head=NULL;
	}
	~LinkList(){
		delete head;
	}
	void add(int val){
		if(head==NULL){
			this->head=new node1(val);
			head->next=NULL;
			return;
		}
		else if(val==head->numb){
			head->count++;
			return;
		}
		else{
			node1 *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
				if(val==temp->numb){
					temp->count++;
					return;
				}
			}
			temp->next=new node1(val);
			temp->next->next=NULL;
		}
	}
	void print(){
		if(head==NULL){
			cout<<"No duplicate number entered"<<endl;
			return;
		}
		else{
			node1 *temp=head;
			cout<<"Printing Duplicate Numbers"<<endl;
			cout<<"Number '"<<temp->numb<<"' occured '"<<temp->count<<"' times"<<endl;
			while(temp->next!=NULL){
				temp=temp->next;
				cout<<"Number '"<<temp->numb<<"' occured '"<<temp->count<<"' times"<<endl;
			}
		}
	}
};
class node{
	public:
		int data;
		node *left;
		node *right;
		node(int data){
			this->data=data;
			right=NULL;
			left=NULL;
		}
};

class Tree{
	public:
		LinkList L1;
		node *head;
		Tree(){
			head=NULL;
		}
		~Tree(){
			delete head;
		}
		
		void Dublicate(){
			L1.print();
		}
		void insert(int n){
			this->head=insert(n,this->head);
		}
		node* insert(int n,node *temp){
			if(this->head==NULL){
				node* t=new node(n);
				head=t;
				return head; 
			}
			else if(temp==NULL){
				node* t=new node(n);
				temp=t;
				return temp;
			}
			else if(n < temp->data){
				temp->left=insert(n,temp->left);
			}
			else if(n > temp->data){
				temp->right=insert(n,temp->right);
			}
			else if(n == temp->data){
				cout<<"Number already in Tree"<<endl;
				L1.add(n);
			}
			return temp;
		}
		
		
		
		
		void Remove(int n){
			this->head=Remove(n,this->head);
		}
		node* Remove(int n,node *temp){			
			if(n==temp->data){
				if(temp->left==NULL && temp->right==NULL){
					node *temp1=temp;
					temp=NULL;
					delete temp1;
					return temp;
				}
				if(temp->left!=NULL && temp->right==NULL){
					node *temp1=temp;
					temp=temp->left;
					delete temp1;
					return temp;
				}
				if(temp->right!=NULL && temp->left==NULL){
					node *temp1=temp;
					temp=temp->right;
					delete temp1;
					return temp;
				}
				if(temp->left!=NULL && temp->right!=NULL){
					node *temp1=temp->right;       
					while(temp1->left!=NULL){
						temp1=temp1->left;
					}
					temp->data=temp1->data;
					temp->right=Remove(temp->data,temp->right);
				}
			}
			else if(n < temp->data && temp->left!=NULL){
				temp->left=Remove(n,temp->left); 
			}
			else if(n > temp->data && temp->right!=NULL){
				temp->right=Remove(n,temp->right);
			}
			return temp;
		}
		
		
		
		
		void Inorder(){
			Inorder(this->head);
		}
		void Inorder(node *temp){
			if(temp==NULL){
				cout<<"Tree empty"<<endl;
				return;
			}
			if(temp->left!=NULL) Inorder(temp->left);
			cout<<temp->data<<"  ";
			if(temp->right!=NULL) Inorder(temp->right);
		}
};


int main(){
	Tree t; t.insert(67);   t.insert(67); t.insert(67);
	t.insert(13);
	t.insert(50); 
	t.insert(50); t.insert(50); t.insert(50); 
	t.insert(70);  t.Remove(67); t.Remove(70); 
	t.Inorder(); cout<<endl; t.Dublicate();
	return 0;
}
