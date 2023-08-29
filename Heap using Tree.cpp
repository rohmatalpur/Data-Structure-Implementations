#include<iostream>
#include<cmath>
int count=0;
using namespace std;
//Max heap using Tree
int elem=0;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int data){
			this->data=data;
			left=right=NULL;
		}
};
class MaxHeap{
	private:
		node* Root;
		int Level;
		int Nodes;
	public:
		
		MaxHeap(){
			Root=NULL;
			Level=0;
			Nodes=0;
		}
		
		
		node* insert(int val,node* r,int lh){
			if(elem==0){
				if(this->Root==NULL){
				this->Root=new node(val);
				Nodes++; //cout<<"ROOT"<<endl;
				return Root;
				}
				if(Nodes==( pow(2,Level+1)-1 )){
					node* temp=r;
					while(temp->left!=NULL){
						temp=temp->left;
					}
					temp->left=new node(val);
					this->Level++;
					Nodes++;
					elem=1; //cout<<"pow"<<endl;
					return r;
				}
				if(r->left!=NULL && r->right==NULL){
					r->right=new node(val);
					Nodes++;
					elem=1;  //cout<<"right==null"<<endl;
					return r;
				}
				if(r->left==NULL && r->right==NULL && lh<this->Level){
					r->left=new node(val);
					Nodes++;
					lh--;
					elem=1;  //cout<<"lh<this->Level"<<endl;
					return r;
				}
				if(r->left!=NULL && elem==0) r->left=insert(val,r->left,++lh);
				lh--;
				if(r->right!=NULL && elem==0) r->right=insert(val,r->right,++lh);
				lh--;
				return r;
			}
		}
		
		
		node* balance(node* r,int* x){
			if(r->left==NULL && r->right==NULL) return r;
			
			if(r->left!=NULL) r->left=balance(r->left,x);
			if(r->right!=NULL) r->right=balance(r->right,x);
			
			if(r->left!=NULL && r->right!=NULL){
				if(r->left->data > r->right->data){
					if(r->left->data > r->data){
						int temp=r->data;
						r->data=r->left->data;
						r->left->data=temp;
						*x++;		}	}
				else{
					if(r->right->data > r->data){
						int temp=r->data;
						r->data=r->right->data;
						r->right->data=temp;
						*x++;		}	}
			}
			
			
			if(r->left!=NULL && r->right==NULL){
				if(r->left->data > r->data){
					int temp=r->data;
					r->data=r->left->data;
					r->left->data=temp;
					*x++;		}	}
			return r;
		}
		
		
		
		void balance(){
			int count;
			int* cptr=&count;
			do{
				*cptr=0;
				this->Root=balance(this->Root,cptr);
			}while(*cptr!=0);
		}
		
		
		void insert(int val){
			elem=0;
			this->Root=insert(val,this->Root,0);
			balance();
		}
		
		void Delete(){
			this->Root=traverse(this->Root);
			count=0;
			if( this->Nodes==(pow(2,this->Level)-1 ) ){
				this->Level--;	}
			balance();	 
		}
		
		
		
		node* traverse(node *r){
			if(r==NULL){
				cout<<"Nothing to delete, tree is empty  "<<endl;	}
			if(r->left==NULL && r->right==NULL){
				count++;
				if(count==( Nodes-(pow(2,Level)-1) )){
				this->Root->data=r->data;
				r=NULL;
				this->Nodes--;
				return r;
				}	}
			if(r->left!=NULL) r->left=traverse(r->left);
			if(r->right!=NULL) r->right=traverse(r->right);
			return r;	}
		
		
		
		void print(){
			cout<<"Printing Tree "<<endl;
			Root=preorder(this->Root);
			cout<<endl;	}
		
		
		
		node* preorder(node *r){
			if(r==NULL) return r;
			cout<<r->data<<"  ";
			if(r->left!=NULL) r->left= preorder(r->left);
			if(r->right!=NULL) r->right=preorder(r->right);
			return r;
		}
		
};

int main(){
	MaxHeap h;
	h.insert(45); 
	h.insert(5);
	h.insert(55);
	h.insert(44);
	h.insert(6);
//	h.insert(15);
//	h.insert(4);
//	h.insert(9);
//	h.insert(85);                                  
//	h.insert(47);
//	h.insert(66);    
//	h.insert(55);
	h.print();
	h.Delete();
	h.print();
	h.Delete();
	h.print();
	h.Delete();
	h.print();
	return 0;
}
