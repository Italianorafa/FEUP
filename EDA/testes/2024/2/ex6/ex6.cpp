
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

class Graph {
    private:
        int v; 
        vector<list<int>> edges;

    public:
        // Constructor
        Graph(int v) {
            if (v > 0) {
                this->v = v; 
                this->edges.resize(v);
            }
        }

        // Utility function
        void print();

/* --------------- Implement here --------------- */

        int addEdge(int v1, int v2) //undirected graph
        {
            if(v1<0 || v2<0 || v1>this->v || v2>this->v) return -1;
            for(int ed: edges[v1]){
                if(ed == v2) return 1;
            }
            for(int ed: edges[v2]){
                if(ed == v1) return 1;
            }
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
            return 0;
        }
        
        int countNeighbours(int node)
        {
            if(node<0 || node>v) return -1;
            return edges[node].size();
        }
};

/* ---------------------------------------------- */


/* ---------- Test Code. Do not change ---------- */ 
int main()
{
	int n = 10;
    int n_edges = 15; //tentative n
	Graph u_graph(n);

    srand(time(0));

    int cont = 0;
    for (int i = 0; i < n_edges; ++i) {
        int v1 = rand() % (n * 2);
        int v2 = rand() % (n * 2);
        if (v1 < n && v2 < n && v1 != v2 && u_graph.addEdge(v1, v2) == 0) {
            cont++;
        }
    }
	cout << "Graph has " << n << " nodes and " << cont << " edges." << endl;
	
    u_graph.print();

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " has " << u_graph.countNeighbours(i) << " neighbours." << endl;
    }

	return 0;
}

void Graph::print()
{
    for(int i=0; i < this->v; i++){
        cout << i << " -> ";
        for(auto it : this->edges[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}
