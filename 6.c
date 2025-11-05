#include <stdio.h>
#define INF 9999
#define V 6

void dijkstra(int graph[V][V], int start) {
    int cost[V][V], distance[V], visited[V], pred[V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];

    for(int i=0;i<V;i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;

    for(int count=1; count<V-1; count++) {
        int min = INF, next;
        for(int i=0;i<V;i++)
            if(distance[i]<min && !visited[i])
                min = distance[i], next=i;
        visited[next]=1;
        for(int i=0;i<V;i++)
            if(!visited[i])
                if(min+cost[next][i] < distance[i]) {
                    distance[i] = min+cost[next][i];
                    pred[i] = next;
                }
    }

    printf("Shortest distances from vertex %d:\n", start);
    for(int i=0;i<V;i++)
        if(i!=start)
            printf("%d -> %d : %d\n", start, i, distance[i]);
}

int main() {
    int graph[V][V] = {
        {0,4,2,0,0,0},
        {4,0,1,5,0,0},
        {2,1,0,8,10,0},
        {0,5,8,0,2,6},
        {0,0,10,2,0,3},
        {0,0,0,6,3,0}
    };
    dijkstra(graph, 0);
    return 0;
}
