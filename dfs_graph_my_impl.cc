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

	void find_connected(int s){
		int i=0;
		cout << "s: " << s << endl;
		for (auto x:graph){
			if ( i == s){
				// cout << "s: " << s << " " << "i: " << i << endl;
				for(auto k:graph[i])
				 connected.push_back(k);
				break;
			}
/*
 * THIS WONT BE COMMENTED FOR UN DIRECTED GRAPH
			else{
				for( auto y:x){
					if (y == s) connected.push_back(i);
				}
				break;
			}
*/
			i++;
		}
		cout << endl; cout << s << " conect to " ;
	 	for(auto x:connected) cout <<  " " << x  ;
		cout << endl;
	}

	void BFS(int s){

		int tmp=0;
		queue<int> q;
		vector<int> bfs;
		bfs.push_back(s);
		q.push(s);
		
		while(!q.empty()){
			tmp = q.front();
			q.pop();
			find_connected(tmp);
			for(auto x:connected){
				auto it = std::find (bfs.begin(), bfs.end(), x);
				if (*it != x){
					bfs.push_back(x); 
					q.push(x);
				}
			}
	 		for(auto x:bfs) cout <<  " " << x  ;
			cout << endl;
			connected.clear();
			int k; cin >> k;
		}
	}

	vector<vector<int>> graph;
	vector<int> connected;
private:
	int V;
	bool* visited;
	vector<int> bfs;
};

int main(){

	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(2, 6);

	g.BFS(0);

/*
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

	g.BFS(0);

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

	g.BFS(0);
*/

}
	




