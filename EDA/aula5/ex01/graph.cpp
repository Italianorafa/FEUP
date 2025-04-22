/*****************************************************************/
/*   Grafo c/ listas de adjacencias | ESDA | LEEC | 2023/24      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"

Graph::Graph(int v)
{
    if (v > 0) {
        this->v = v; // atribui o número de vértices
        this->adj.resize(v);
    }
}

int Graph::addEdgeDirected(int v1, int v2)
{
    

    return -1;
}

int Graph::removeEdge(int v1, int v2)
{
    /* Alinea 1.a */
    
    return -1;
}

bool Graph::existsNeighbor(int v1, int v2)
{
    /* Alinea 1.a */
	return false;
}


int Graph::outDegree(int v)
{
    /* Alinea 1.b */
	return 0;
}

vector<list<int>> Graph::transposeGraph()
{
    /* Alinea 1.c */
    return {};
}

void Graph::print()
{
    for(int i=0; i < this->v; i++){
        cout << i << " -> ";
        for(auto it : this->adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::print(vector<list<int>> vet)
{
    for(int i=0; i < vet.size(); i++){
        cout << i << " -> ";
        for(auto it : vet[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}


