//Queue Using Array
#include<iostream>
using namespace std;
class Queue{
    private:
    int *arr;
    int size;
    int rear, front; // Index
    int noOfElemets;
   
    public:
    Queue(int size){
        this->size= size;
        arr= new int[size];
        rear= -1, front=-1,noOfElemets=0 ;
    }
    ~Queue(){
        delete []arr;
    }
    void enqueue(int val){
        if(rear== size-1){
        	if(front==0){
        		cout<<"Queue OverFlow"<<endl;
            	return;
			}
            else{
            	rear=0;
            	arr[0] =val;
        		noOfElemets++;
        		return;
			}
        }
        if (front == - 1)
              front = 0;
        else if(front==rear+1){
        	cout<<"Queue OverFlow"<<endl;
            return;
		}
        arr[++rear] =val;
        noOfElemets++;
    }
   
    int dequeue()
    {
        if (front == - 1) {
              cout<<"Queue Underflow ";
              return -1;
           }
        else if(front==size){
        	if(rear==size-1){
        		front= -1;
        		cout<<"Queue Underflow ";
              	return -1;
			}
			front=0;
		}
		else if(front<=rear){
			cout<<"Element deleted from queue is, : "<< arr[front] <<endl;
			noOfElemets--;
        	return arr[front++];
			}
			
        else if(front>rear){
        	if(front<size){
        		cout<<"Element deleted from queue is : "<< arr[front] <<endl;
        		noOfElemets--;
        		return arr[front++];
			}
			else{
				cout<<"Queue Underflow ";
              	return -1;
			}	
		}
    }
    void display(){
        if (front == - 1)
               cout<<"Queue is empty"<<endl;
        else if(rear>front){
        	cout<<"Queue elements are : ";
        	if( (rear-(front-1)) == noOfElemets){
        		for(int i=front;i<=rear;i++) cout<<arr[i]<<" ";
			}
        	else{
        		for(int i=rear;i<size;i++){
        			cout<<arr[i]<<" ";
				}
				for(int i=0;i<=front;i++){
        			cout<<arr[i]<<" ";
				} 
				cout<<endl;
			}
		}
        else if(rear<front){
            cout<<"Queue elements are : ";
            for (int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        }
    }
};
int main (){
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
	q1.enqueue(65);
    q1.enqueue(7667);
    q1.enqueue(78);
    q1.display();
    return 0;
}
