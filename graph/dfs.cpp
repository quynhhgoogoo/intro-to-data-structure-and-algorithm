#include <iostream>
#include <stack>

using namespace std;

void DFS (int vertex, int A[][8], int n){
    stack<int> Stk;
    
    /* Initialize an array of visited vertex*/
    int visited[8] {0};
    Stk.emplace(vertex);

    /* Explore adjancency vertex */
    while (!Stk.empty()){
        /* Pop out next vertex in stack */
        int explore_vertex = Stk.top();
        Stk.pop();

        if( visited[vertex] != 1){
            cout << vertex << "," << flush;
            visited[vertex] = 1;

            for (int vertex_index=n-1; vertex_index>=0; vertex_index--){
                if (A[explore_vertex][vertex_index] == 1 && visited[vertex_index] == 0){
                    Stk.emplace(vertex_index);
                    cout << vertex_index << "," << flush;
                }
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
    DFS(1, A, 8);

    cout << "Vertex 4: " << flush;
    DFS(4, A, 8);

    return 0;
}