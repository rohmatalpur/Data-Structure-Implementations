#include<iostream>
using namespace std;


bool Search(int key,int arr[],int IIndex,int FIndex){
	bool Ans;
	if(IIndex==FIndex){
		if(key==arr[IIndex]) return true;
		else return false;
	}
	int MIndex=IIndex+FIndex;
	if(key==arr[MIndex]) return true;
	if(key<arr[MIndex]) Ans=Search(key,arr,IIndex,MIndex-1);
	if(key>arr[MIndex]) Ans=Search(key,arr,MIndex+1,FIndex);
	
	if(Ans==true) return Ans;
	else return false;
}
int main(){
	int arr[6]={1,2,4,6,8,10};
	if(Search(6,arr,0,5)) cout<<"True";
	return 0;
}
