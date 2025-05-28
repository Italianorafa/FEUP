
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
            /* Exercise 4a) */
        }
        
        int countNeighbours(int node)
        {
            /* Exercise 4b) */
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
