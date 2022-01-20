#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;

unordered_map<string, string> m;
unordered_map<string, long> counts;
unordered_set<string> u;

void printSolution(vector<int> &dist)
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}

int main() {
    string input, n1, n2;
    vector<vector<int>> v;
    int x;
    while (getline(cin, input)) {
        stringstream ss (input);
        vector<int> temp;
        for (int i = 0; i < input.length()-1; ++i) {
            temp.push_back(input[i]-'0');
        }
        v.push_back(temp);
    }
    int row = v.size(), col = v[0].size();
    vector<vector<int>> dp (row, vector<int> (col, 0));
    dp[0][0] = v[0][0];
    for (int i = 1; i < col; ++i) {
        dp[0][i] = v[0][i] + dp[0][i-1];
    }
    for (int i = 1; i < row; ++i) {
        dp[i][0] = v[i][0]+ dp[i-1][0];
    }
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + v[i][j];
            // cout << dp[i][j] << ' ';
        }
        for (int k = col-2; k >= 0; --k) {
            dp[i][k] = min(dp[i][k], v[i][k] + dp[i][k+1]);
        }
        // cout << endl;
    }
    cout << dp[row-1][col-1] - v[0][0]<< endl;

}