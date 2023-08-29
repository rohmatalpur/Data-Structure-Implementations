#include<iostream>
using namespace std;
//Min heap using array[]
class node{
	public:
		int data;
		node(){
		}
		node(int data){
			this->data=data;
		}
};
class MinHeap{
	private:
		node *arr;
		int capacity;
		int TItems;
	public:
		
		MinHeap(){
			arr=NULL;
			capacity=0;
			TItems=0;
		}
		
		MinHeap(int size){
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
			if( this->arr[index].data < this->arr[parent].data ){
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
			if(this->arr[Lchild].data < this->arr[Rchild].data ){
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
};

int main(){
	MinHeap H;
	H.insert(23);
	H.insert(13);
	H.insert(11);
	H.insert(1);
	H.inorder(0); cout<<endl;
	H.Delete();
	H.inorder(0);
	return 0;
}
