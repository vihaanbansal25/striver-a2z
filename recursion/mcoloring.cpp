#include <bits/stdc++.h>
using namespace std;
// https://takeuforward.org/plus/dsa/problems/m-coloring-problem?source=strivers-a2z-dsa-track
class Solution{
private:
bool possible(int col, int node, vector<int>& color, int n, vector<vector<int>>& mat){
    for (int i = 0; i < n; i++){
        if (mat[node][i] == 1 && color[i] == col){
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<int>& color, int m, int n, vector<vector<int>>& mat){
    if (node == n){
        return true;
    }

    for (int col = 1; col <= m; col++){
        if (possible(col, node, color, n, mat)){
            color[node] = col;
            if (solve(node + 1, color, m, n, mat)) return true;
            color[node] = 0;
        }
    }
    return false;
}
public:
    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
    	//your code goes here
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < edges.size(); i++){
            mat[edges[i][0]][edges[i][1]] = 1;
            mat[edges[i][1]][edges[i][0]] = 1;
        }

        vector<int> color(n, 0);
        
        return solve(0, color, m, n, mat);
    }
};