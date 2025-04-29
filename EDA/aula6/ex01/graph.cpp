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
    if(v1<0 || v1 > v){
        return -1;
    }
    if(v2>=0){
        adj[v1].push_back(v2);
    }
    return 0;
}

int Graph::removeEdge(int v1, int v2)
{
    if(v1<0 || v2>v || v2<0) return -1;
    else{
        adj[v1].remove(v2);
        return 1;
    }
    
    return 0;
}

bool Graph::existsNeighbor(int v1, int v2)
{
    if(v1<0 || v1>v || v2<0) return false;
    auto it = find(adj[v1].begin(), adj[v1].end(), v2);
    if(it == adj[v1].end()){
        return false;
    }
	return true;
}


int Graph::outDegree(int v)
{
    if(v<0 || v>Graph::v) return -1;
    else{
        return adj[v].size();
    }
}

vector<list<int>> Graph::transposeGraph()
{
    vector<list<int>> transp(v);
    for(int i = 0; i<v; i++){
        for(auto c: adj[i]){
            transp[c].push_back(i);
        }
    }
    return transp;
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


