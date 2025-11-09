#include <stdio.h>

int graph[20][20], visited[20], queue[20];
int n, front = 0, rear = 0;

void DFS(int v){
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < n; i++){
        if(graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int v){
    int i;
    visited[v] = 1;
    queue[rear++] = v;

    while(front < rear){
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++){
            if(graph[v][i] == 1 && !visited[i]){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int i, j, start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("\nNodes reachable using DFS: ");
    for(i = 0; i < n; i++) visited[i] = 0;
    DFS(start);

    printf("\nNodes reachable using BFS: ");
    for(i = 0; i < n; i++) visited[i] = 0;
    BFS(start);

    return 0;
}
