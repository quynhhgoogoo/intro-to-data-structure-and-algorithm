/* Prim's Minimum Cost Spanning Tree */
#include <iostream>
#define I 32767

using namespace std;

int cost [][8] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6];

void prim_algorithm(){
    int i, j, k, u, v, n=7, min=I;

    /* Searching for mimimum cost edge in upper triangle of cost adjancy matrix */
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++){
            if (cost[i][j] < min){
                min = cost[i][j];
                /* Save the location of minimum cost edge on matrix */
                u = i;
                v = j;
            }
        }
    }
    /* Update vertexes on solution's table */
    t[0][0] = u;
    t[1][0] = v;

    /* Update vertexes on explored table */
    near[u] = near[v] = 0;

    /* Find the minimum cost edge between explored vertexes and unexplored vertexes
        Update the solution table  */
    for(i=1; i<=n; i++){

        if(near[i] != 0){
            if (cost[i][u] < cost[i][v]){
                near[i] = u;
            }
            else{
                near[i] = v;
            }
        }
    }

    for (i = 1; i < n-1; i++){
        min = I;
        for(j = 1; j <= n ; j++){
            /* Iterate through the neighbour list and find the minimum cost edge */
            if (near[j] != 0 && cost[near[j]][j] < min){
                k = j;
                min = cost[near[j]][j];
            }
        }

        /* Save value of vertexes that has minimum cost edge inside matrix */
        t[0][i] = k;
        t[1][i] = near[k];
        
        /* Update explored vertex */
        near[k] = 0;

        /* Compare the cost edge between unexplored vertex with explored vertex 
        Update solution table*/
        for(j = 1; j <= n; j++){
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]]){
                near[j] = k;
            }
        }

    }

    cout << "Update the solution table for spanning tree" << endl;
    for(i = 0; i < n-1; i++){
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
}

int main(){
    prim_algorithm();
    return 0;
}
