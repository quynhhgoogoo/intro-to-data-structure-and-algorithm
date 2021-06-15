#include <iostream>
#define I 3267
#define V 7             /*no of vertexes*/
#define E 9             /*no of edges*/
using namespace std;


/* Merge two disconnected graphs into one */
void Union (int u, int v, int s[]){
    /* Chose a parent node for a new graph*/
    if (s[u] < s[v]){
        s[u] = s[u] + s[v];
        s[v] = s[u];
    }
    else{
        s[v] = s[v] + s[u];
        s[u] = s[v];
    }
}


/* Check if two vertexes are in the same set */
int Find (int u, int s[]){
    int v, x;

    /* Trace for parent node of node u */
    while (s[u] > 0){
        x = s[u];
    }

    /* Connect the node to its parent */
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void Kruskal (int A[3][E]){
    int T[2][V - 1];                /* Solution array of spanning tree*/
    int track[E] {0};               /* State of visited/not visited edge */
    int cycle[V + 1] {-1};            /* Trace cycle */

    int i = 0;
    while (i < V - 1){
        int min = I;
        int u = 0; int v = 0; int k = 0;

        /* Find minimum cost edge */
        for (int j = 0; j < E; j ++){
            
            /* if edge is not visited ad cost edge is min */
            if (track[j] == 0 && A[2][j] < min){
                min = A[2][j];
                /* Store the correspond vertexes and edge's index */
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }

        /* Check if min cost edge (u,v) form a circle or not*/
        if ( Find(u, cycle) != Find(v, cycle) ){
            /* Store vertex into solution table */
            T[0][i] = u;
            T[1][i] = v;

            /* Merge the sets where two vertexes belong to into one */
            Union(Find(u, cycle), Find(v,cycle), cycle);
            i++;
        }
        /*Update edge as visited*/
        track[k] = 1;
    }

    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

int main(){
    /* Store the cost of each path */
    int edges[3][E] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    
    Kruskal(edges);
    return 0;
}