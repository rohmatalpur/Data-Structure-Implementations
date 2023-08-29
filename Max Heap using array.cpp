#include<iostream>
#include<cmath>
using namespace std;
//Max heap using array[]
class node{
	public:
		int static stat;
		int data;
		int number;
		node(){
		}
		node(int data){
			this->data=data;
			this->number= ++stat;
		}
};
class MaxHeap{
	private:
		node *arr;
		int capacity;
		int TItems;
	public:
		
		MaxHeap(){
			arr=NULL;
			capacity=0;
			TItems=0;
		}
		
		MaxHeap(int size){
			arr=new node[size];
			capacity=size;
			TItems=0;
		}
		
		
		void doubleCapacity(){
			if(arr==NULL){
				this->capacity=1;
				this->arr=new node[1];
				return;
			}
			int newcapacity=capacity*2;
			node *tempArr=new node[newcapacity];
			for(int i=0;i<TItems;i++){
				tempArr[i]=this->arr[i];
			}
			this->arr=tempArr;
			this->capacity=newcapacity;
		}
		
		
		
		void insert(int val){
			if(TItems==capacity){
				doubleCapacity();
			}
			this->arr[TItems]=val;
			ShiftUp(TItems);
			TItems++;
		}
		
		
		void ShiftUp(int index){
			if(index==0) return;
			int parent=(index-1)/2;
			if( this->arr[index].data > this->arr[parent].data ){
				int temp = this->arr[parent].data;
				this->arr[parent].data = this->arr[index].data;
				this->arr[index].data = temp;
			}
			ShiftUp(parent);
		}
		
		
		void Shiftdown(int index){
			int Lchild=(2*index)+1;
			int Rchild=(2*index)+2;
			if( Lchild > TItems-1 && Rchild > TItems-1 ) return;
			if(this->arr[Lchild].data > this->arr[Rchild].data ){
				int temp = this->arr[index].data;
				this->arr[index].data = this->arr[Lchild].data;
				this->arr[Lchild].data = temp;
				Shiftdown(Lchild);
			}
			else{
				int temp = this->arr[index].data;
				this->arr[index].data = this->arr[Rchild].data;
				this->arr[Rchild].data = temp;
				Shiftdown(Rchild);
			}
		}
		
		
		void Delete(){
			if(TItems==0){
				cout<<"Heap empty"<<endl;
				return;
			}
			if(TItems==1){
				this->arr=NULL;
				TItems=0;
				return;
			}
			this->arr[0]=this->arr[--TItems];
			Shiftdown(0);
		}
		
		void inorder(int index){
			int Lchild=(2*index)+1;
			int Rchild=(2*index)+2;
			if(Lchild<TItems) inorder(Lchild);
			cout<<this->arr[index].data<<"  ";
			if(Rchild<TItems) inorder(Rchild);
		}
		
		void Rpostorder(int index){
			int Lchild=(2*index)+1;
			int Rchild=(2*index)+2;
			if(Lchild<TItems) Rpostorder(Lchild);
			if(Rchild<TItems) Rpostorder(Rchild);
			cout<<this->arr[index].data<<"  ";
			
		}
		void Rpreorder(int index){
			int Lchild=(2*index)+1;
			int Rchild=(2*index)+2;
			cout<<this->arr[index].data<<"  ";
			if(Lchild<TItems) Rpreorder(Lchild);
			if(Rchild<TItems) Rpreorder(Rchild);
		}
		
//		void Ipreorder(int index){
//			while(count<TItems){
//				int Lchild=index;
//				while(Lchild<TItems-1){
//					index=Lchild;
//					cout<<this->arr[index].data<<"  ";
//					count++;
//					Lchild=(2*Lchild)+1;
//				}
//				int Rchild=(2*index)+2;
//			}
//		}
		void EvenNode(int index,int* c){
			int Lchild=(2*index)+1;
			int Rchild=(2*index)+2;
			if(Lchild<TItems || Lchild<TItems){
				if(this->arr[index].number%2==0){
					cout<<this->arr[index].data<<"  ";
					*c++;
				}
			}
			if(Lchild<TItems) EvenNode(Lchild,c);
			if(Rchild<TItems) EvenNode(Rchild,c);
		}
		
		void EvenNode(){
			int c=0;
			EvenNode(0,&c);
			cout<<endl;
			cout<<"Number of even parent nodes "<<c<<endl;
		}
		
		void NoOfNodes(){
			int h;int c=0;
			cout<<"Enter height to find nmber of nodes ";
			cin>>h;
			if(h==0 || h<0){
				cout<<"Invalid number "<<endl;
				return;
			}
			if(h==1){
				cout<<"Number of Nodes are "<<1<<endl;
				return;
			} 
			int temp=h-2;
			int cc=(pow(2,temp+1));
			for(int i=cc;i<=(pow(2,h)-1);i++){
				if(i==TItems) break;
				c++;
			}
			cout<<"Number of Nodes are "<<c<<endl;
		}
};
int node::stat=0;
int main(){
	MaxHeap H;
	H.insert(1);
	H.insert(1);
	H.insert(23);
	H.insert(11);
	H.insert(13);
	H.insert(1);
	H.insert(1);
	H.insert(1);
	H.inorder(0); cout<<endl;
	H.Rpreorder(0); cout<<endl;
	H.Rpostorder(0); H.EvenNode();
	return 0;
}
