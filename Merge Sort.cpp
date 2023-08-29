#include<iostream>
using namespace std;


void MergeSort(int* a,int size){
	if(size==1) return ;
	int s=size/2;
	int arr1[s];
	int arr2[s];
	for(int i=0;i<s;i++){
		arr1[i]=*(a+i);
	}
	int j=0;
	for(int i=s;i<size;i++){		
		arr2[j++]=*(a+i);
	}
	MergeSort(arr1,s);
	MergeSort(arr2,s);
	int* ptr1=arr1; int c1=1;
	int c2=1;
	int* ptr2=arr2;
	int *AnsArr=new int[size];
	for(int i=0;i<size;i++){
		if(*arr1 > *arr2){
			AnsArr[i] = *arr1;
			c1++; 
			if(c1<s) cout<<"H";//arr1++;
			else{
				*arr1=-1;
			}
			//cout<<*(a-1)<<" ans1   ";
		}
		else{
			AnsArr[i] = *(arr2); 
			c2++;
			if(c2<s)  cout<<"H";//arr2++;
			else{
				*arr2=-1;
			}
			//cout<<*(a-1)<<" ans2   ";
		}
	} cout<<endl;
	
	
	for(int i=0;i<size;i++){
		cout<<AnsArr[i]<<"  ";
	}  cout<<endl;
	return AnsArr
	
}
int main(){
	int arr[4]={23,21,222,32}; int temp; 
	MergeSort(arr,4);
	
	
	
//	for(int i=3;i>=0;i--){
//		for(int j=0;j<=i;j++){
//			if(arr[j]>arr[j+1]){
//				temp=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=temp;
//			}
//		}
//	}
	
	for(int i=0;i<5;i++) cout<<arr[i]<<"  ";
}
