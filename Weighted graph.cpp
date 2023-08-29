#include<iostream>
#include<list>
using namespace std;
class node{
	public:
		int SInd;
		int EInd;
		int cost;
};
class Graph{
	private:
		list<node> *Adj;
		int No_of_Ver;
	public:
		Graph(int n){
			Adj=new list<node>[n];
			No_of_Ver=n;
		}
		void AddEdg(int S,int E,int c){
			node* t;
			t->SInd=S; t->EInd=E; t->cost=c;
			Adj[S].push_back(*t);
		}
//		void DelEdg(int S,int E,int c){
//			node* t;
//			t->SInd=S; t->EInd=E; t->cost=c;
//			Adj[S].erase(E);
//		}
		void print(){
			for(int i=0;i<No_of_Ver;i++){
				cout<<"Adjacent of ["<<i<<"]: ";
				for(auto it=Adj[i].begin();it!=Adj[i].end();it++){
					cout<<it->EInd<<" [w:"<<it->cost<<"] ---> ";
				}
				cout<<endl;
			}
		}
		
		void Adj_Nodes(int n){
			cout<<"Adjacent of ["<<n<<"]: ";
			for(auto it=Adj[n].begin();it!=Adj[n].end();it++){
				cout<<it->EInd<<" [w:"<<it->cost<<"] ---> ";
			}
			cout<<endl<<endl;
		}
		
		void Find_path(int s,int e){
			int Tweight=0;
			int TempW;
			int tempi;
			list<node> :: iterator x;
			for(int i=s;i<e;i++){
				x=Adj[i].begin();
				TempW = x->cost;
				
				if(x->EInd <= e) tempi = x->EInd;
				else tempi = i;
				cout<<"Adjacent of ["<<i<<"]: ";
				for(auto it=Adj[i].begin();it!=Adj[i].end();it++){
					if(it->cost < TempW && it->EInd < e){
						tempi = it->EInd;
						TempW = it->cost;
					}
				}
				i=tempi-1;
				Tweight+=TempW;
				cout<<tempi<<" [w:"<<TempW<<"]";
				cout<<endl;
			}
			cout<<"Total cost: "<<Tweight<<endl;
		}
};
int main(){
	Graph g(4); g.AddEdg(0,1,5); g.AddEdg(1,1,3);g.AddEdg(1,2,2);g.AddEdg(0,2,1);g.AddEdg(2,3,0);g.AddEdg(3,3,5);g.AddEdg(3,1,5);
	g.Adj_Nodes(3);
	g.Find_path(1,3);
	g.print();
	return 0;
}
