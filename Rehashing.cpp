#include<iostream>
using namespace std;

class Rehashing{
	int capacity;
	int count;
	int* arr;
	
	int getPrime(int n){
		if(n%2==0){
			n++;	}
		bool ans;
		while(ans){
			ans=true;
			for(int i=2;i<n;i++){
				if(n%i==0) ans=false;
			}
			n+=2;	}
		cout<<n<<endl;
		return n;	}
	
	
	
	
	void double_cap(){
		int c2=getPrime(capacity*2);
		int* arr2=new int[c2];
		int ind;
		for(int i=0;i<c2;i++){
			arr2[i]= -1;
		}
		for(int i=0;i<capacity;i++){
			if(arr[i]!= -1){
				ind=arr[i]%c2;
				arr2[ind]=arr[i];
			}
		}
		this->capacity=c2;
		cout<<"capacity is "<<capacity<<endl;
		this->arr=arr2;	
	}
	public:
	Rehashing(int size){
		capacity=getPrime(size*2);
		arr= new int[capacity];
		count=0;
		for(int i=0;i<capacity;i++)
			arr[i]=-1;
	}
	
	void insert(int num){
		if((count/capacity)*100>=70) double_cap();
		int index=num%capacity;
		if(arr[index]== -1) arr[index]=num;
		else{
			bool ans;
			for(int i=index+1;i<capacity;i++){
				if(arr[i]== -1){
					arr[i]=num;
					ans=true;
					break;
				}	}
			if( !ans ){
				for(int i=0;i<index;i++){
					if(arr[i]== -1){
						arr[i]=num;
						break;
					}	}	}
		}
		this->count++;
	}
	
	void print(){
		cout<<"Printing: "<<capacity<<endl;
		for(int i=0;i<capacity;i++){
			if(arr[i]!=-1){
				cout<<"Number: "<<arr[i]<<" at "<<i<<" index"<<endl;
			}
		}
	}
	
	
	
};

int main(){
	Rehashing r(1); r.insert(2); r.insert(1); r.insert(0); r.insert(4);  r.insert(70); 
	r.print();
	return 0;
}
