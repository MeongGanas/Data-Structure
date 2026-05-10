#include <iostream>
#include <vector>
#include <map>

using namespace std;

// code saya
int findCenter(vector<vector<int>>& edges) {
    int n = edges.size();
    map<int, int> counting_connections;
    
    for(int i = 0; i < n; i++){
        int vertex_0 = edges[i][0];
        int vertex_1 = edges[i][1];

        if(counting_connections[vertex_0] > 0){
            counting_connections[vertex_0] += 1;
        } else if (counting_connections[vertex_1] > 0){
            counting_connections[vertex_1] += 1;
        } else {
            counting_connections[vertex_1] = 1;
            counting_connections[vertex_0] = 1;
        }

        if(counting_connections[vertex_0] == n){
            return vertex_0;
        } else if (counting_connections[vertex_1] == n){
            return vertex_1;
        }
    }
    return -1;
}

// code AI
int findCenter(vector<vector<int>>& edges) {
    // The center node must appear in both edges[0] and edges[1].
    // Let's check if the first node of the first edge matches 
    // either node in the second edge.
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    }
    
    // If it doesn't match, the second node of the first edge MUST be the center.
    return edges[0][1];
}

int main(){
    vector<vector<int>> edges = {{1,2},{5,1},{1,3},{1,4}};
    cout << findCenter(edges);
}