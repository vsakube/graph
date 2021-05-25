#include<iostream>
#include<queue>
#include<list>
#include <algorithm>

using namespace std;

class Graph {

public:
	Graph(int _V){
		V = _V;
		graph.resize(V);
		
	}

	void addEdge(int v, int w)
	{
		graph[v].push_back(w); 
	}

	bool test_reachability(int s, int dst){

		int tmp=0;
		queue<int> q;
		bool *visited = new bool[V];

		if ( s == dst) return true;

		for (int i = 0; i < V; i++)
		        visited[i] = false;

		q.push(s); // Only q required, no dfs vector needed
		
		while(!q.empty()){
			tmp = q.front();
			cout << endl << "q.front(): " << tmp << endl;
			visited[tmp]=true;
			q.pop();
			if (tmp == dst){
	 			for(;;){ if( !q.empty()) { tmp = q.front(); q.pop(); cout <<  " " << tmp; } else break; }
				return true;
			}
			for( auto it = graph[tmp].begin(); it < graph[tmp].end(); it++){
				if( visited[*it] != true ){
					visited[*it] = true;
					q.push(*it);
				}
			}
		// int k=0; cin >> k;
		}
		return false;
	}

	vector<vector<int>> graph;
	vector<int> connected;
private:
	int V;
	bool* visited;
	vector<int> bfs;
};

int main(){

/*
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(2, 6);

	cout << endl << g.test_reachability(0, 6) << endl;
*/
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
        g.addEdge(1, 0);
        g.addEdge(1, 2);
        g.addEdge(1, 5);
        g.addEdge(1, 6);
        g.addEdge(2, 1);
        g.addEdge(3, 0);
        g.addEdge(4, 0);
        g.addEdge(5, 1);
        g.addEdge(6, 1);

	cout << endl << g.test_reachability(0, 2) << endl;
/*
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);

        for (auto x:g.graph){
                for(auto y:x)
                        cout << y << " " ;
                cout << endl;
        }
	g.find_connected(0);
	g.connected.clear();
	g.find_connected(1);
	g.connected.clear();
	g.find_connected(2);
	g.connected.clear();
	g.find_connected(3);
	g.connected.clear();

	g.test_reachability(0);
*/

}
	




