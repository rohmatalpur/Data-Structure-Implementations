#include<iostream>
using namespace std;

int main(){
	int arr[18]={34,54,70,31,14,23,20,35,24,25,76,44,16,66,52,77,43,75};
	int size=10;
	for(int i=0;i<2;i++){
		for(int i=0;i<18;i++){
			for(int j=i;j<18;j++){
				if( (arr[i]%size) > (arr[j]%size) ){
					int temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		size=size*10;
	}
	
//	for(int i=0;i<18;i++){
//		cout<<arr[i]<<"  ";
//	} cout<<endl;
//	for(int i=0;i<18;i++){
//		for(int j=i;j<18;j++){
//			if( (arr[i]/10) > (arr[j]/10) ){
//				int temp=arr[i];
//				arr[i]=arr[j];
//				arr[j]=temp;
//			}
//		}
//	}
	for(int i=0;i<18;i++){
		cout<<arr[i]<<"  ";
	} cout<<endl;
	return 0;
}
