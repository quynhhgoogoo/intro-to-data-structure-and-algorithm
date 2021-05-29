#include <iostream>
#include <queue>

using namespace std;

void BFS (int vertex, int A[][8], int n){
    queue<int> Q;
    
    /* Initialize an array of visited vertex*/
    int visited[8] {0};
    cout << vertex << "," << flush;
    visited[vertex] = 1;
    Q.emplace(vertex);

    /* Explore adjancency vertex */
    while(!Q.empty()){
        /* Pop out next vertex in queue */
        int explore_vertex = Q.front();
        Q.pop();

        for (int vertex_index = 1; vertex_index <= n; vertex_index ++){
            /* if edges exist in array but not visited */
            if ( A[explore_vertex][vertex_index] == 1 && visited[vertex_index] == 0 ){
                visited[vertex_index] = 1;
                Q.emplace(vertex_index);
                cout << vertex_index << "," << flush;
            }
        }
    }

    cout << endl;
}

int main(){
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "vertex 1: " <<flush;
    BFS(1, A, 8);

    cout << "Vertex 4: " << flush;
    BFS(4, A, 8);

    return 0;
}