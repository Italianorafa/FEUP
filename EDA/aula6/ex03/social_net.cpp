/*****************************************************************/
/*   Grafo c/ matriz de adjacencias | ESDA | LEEC | 2023/24      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include "social_net.hpp"

using namespace std;

SocialNetwork::SocialNetwork(int V) : V(V) {
    // Initialize the adjacency matrix with all entries as false (no friendships)
    adjacencyMatrix.resize(V, vector<bool>(V, false));
}

void SocialNetwork::printSocialNetwork() {
        cout << "Social Network Graph (Adjacency Matrix):" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Person " << i << ": ";
            for (int j = 0; j < V; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
}


void SocialNetwork::addFriendship(int u, int v) {
    if(u<0 || u>this->V || v<0 || v>this->V) return;
    else{
        adjacencyMatrix[u][v] = true;
        adjacencyMatrix[v][u] = true;
    }
}

void SocialNetwork::findMutualFriends(int person1, int person2)
{
    vector<int> mutual;
    if(person1<0 || person1>V || person2<0 || person2>V) return;
    else{
        for(size_t i=0; i<adjacencyMatrix[person1].size(); i++){
            for(size_t j=0; j<adjacencyMatrix[person2].size(); j++){
                if(i==j){
                    if(adjacencyMatrix[person1][i]==1 && adjacencyMatrix[person2][j]==1){
                        mutual.push_back(i);
                        break;
                    }
                }
            }
        }
    }
    cout<<"mutual friends between person "<<person1<<" and person "<<person2<< ": ";
    for(int a : mutual){
        cout<< a << " ";
    }
    cout<<endl;
}

void SocialNetwork::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u = 0; u < V; ++u) {
        if (adjacencyMatrix[v][u] && !visited[u]) {
            DFSUtil(u, visited);
        }
    }
}

void SocialNetwork::findConnectedGroups() {
    
        // alínea c)

}