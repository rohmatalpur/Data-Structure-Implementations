//Queue Using Array
#include<iostream>
using namespace std;
class Queue{
    private:
    int *arr;
    int size;
    int *rear, *front; // Index
    int noOfElemets;
   
    public:
    Queue(int size){
        this->size= size;
        arr= new int[size];
        rear=NULL; front=arr; noOfElemets=0 ;
    }
    ~Queue(){
        delete []arr;
    }
    void enqueue(int val){
        if(noOfElemets==size){
            cout<<"Queue OverFlow"<<endl;
            return;
        }
        if(noOfElemets==0) rear=front;
        *rear++ = val;
        noOfElemets++;
    }
   
    int dequeue()
    {
        if (rear == NULL) {
              cout<<"Queue Underflow ";
              return -1;
           }
        if(front==rear){
        	rear=NULL;
        	noOfElemets--;
        	return *front;
		}
        else {
          cout<<"Element deleted from queue is : "<< *front <<endl;
          noOfElemets--;
         return *front++;
           }
    }
    void display(){
        if (rear==NULL)
               cout<<"Queue is empty"<<endl;
        else{
        	int *t=front;
            cout<<"Queue elements are : ";
            while(t!=rear){
            	cout<<*t++<<"  ";
			}
			cout<<endl;
        }
    }
    
    void merge(Queue q1){
    	if(size<noOfElemets+q1.noOfElemets){
    		cout<<"list is not big for merging"<<endl;
    		return;
		}
		//int d;
		int *t=q1.front;
		while(t!=q1.rear){
			this->enqueue(*t++);
		}
		this->enqueue(*t);
	}
	
	void reverse(){
		int arr[noOfElemets];
		int l=noOfElemets;
		for(int i=0;i<l;i++){
			arr[i]=this->dequeue();
		}
		int d; //cout<<arr[0];cout<<arr[1];cout<<arr[2];cout<<arr[3];
		for(int i=l-1;i>=0;i--){
			d=arr[i];
			this->enqueue(d);
		}
	}
};
int main (){
    Queue q1(5),q2(3);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    
    q1.display();
    q2.enqueue(45); q2.enqueue(0); q2.display(); q1.merge(q2); q1.display(); q1.reverse(); q1.display();
    return 0;
}
