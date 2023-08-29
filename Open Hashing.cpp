#include<iostream>
#include<list>
using namespace std;

class OpenHash{
	list<string> *hash;
	int capacity;
	
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
	public:	
	OpenHash(int size){
		this->capacity=getPrime(size);
		hash=new list<string>[capacity];
	}
	
	
	
	void add(int r,string name){
		int index=r%capacity;
		hash[index].push_back(name);
	}
	
	
	
	void del(int r,string name){
		int index=r%capacity;
		list<string> :: iterator i;
		for(i=hash[index].begin() ; i!=hash[index].end() ; i++){
			if(*i==name) break;
		}
		if( i!=hash[index].end() ) hash[index].erase(i);
	}
	
	
	
	void print(){
		list<string> :: iterator i; cout<<capacity<<endl;
		for(int j=0;j<capacity;j++){
			cout<<"["<<j<<"]: ";
			for(i=hash[j].begin() ; i!=hash[j].end() ; i++){
				cout<<*i<<" ---> ";
			} cout<<endl;
		}
	}
	
	
	void Search(int r,string name){
		int index=r%capacity;
		int x=0;
		bool ans=false;
		list<string> :: iterator i;
		for(i=hash[index].begin() ; i!=hash[index].end() ; i++){
			if(*i==name){
				cout<<"Record found at ["<<x<<"]"<<endl;
				ans=true;
				break;
			}
			x++;
		}
		if(!ans) cout<<"Record not exist"<<endl;
	}
};

int main(){
	OpenHash h(10); h.add(231,"Rohma"); h.add(31,"Sufia"); h.add(111,"Sony"); h.add(139,"Ali"); h.add(44,"farwa"); h.add(31,"Aliya"); h.del(31,"Aliya");
	h.print(); h.Search(231,"Rohma");
	return 0;
}
