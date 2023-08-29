#include<iostream>
#include<list>
using namespace std;

class Graph{
	private:
		list<int> *Adj;
		int No_Of_Edges;
	public:
		Graph(int n){
			No_Of_Edges=n;
			Adj=new list<int>[n];
		}
		void AddEdge(int SInd,int EInd,bool ans){
			Adj[SInd].push_back(EInd);
			if(ans) Adj[EInd].push_back(SInd);
		}
		void DelEdge(int SInd,int EInd,bool ans){
			Adj[SInd].remove(EInd);
			if(ans) Adj[EInd].remove(SInd);
		}
		void Print(){
			for(int i=0;i<No_Of_Edges;i++){
				cout<<"Adjacent of ["<<i<<"]: ";
				for(auto it=Adj[i].begin();it!=Adj[i].end();it++){
					cout<<*it<<" ,";
				}
				cout<<endl;
			}
		}
};

int main(){
	Graph g(4);
	 g.AddEdge(0,2,true); g.AddEdge(0,1,true); g.AddEdge(1,2,true); g.AddEdge(0,3,true); g.AddEdge(3,2,true); 
	 g.AddEdge(1,3,true); g.AddEdge(2,2,true);
	 g.Print();
	 g.DelEdge(0,2,true); cout<<endl<<endl;
	 g.Print();
	return 0;
}
