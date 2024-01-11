/*
Write a C Program where a directed acyclic graph (DAG) of n nodes labeled from 0 to n-
1 is given, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i
(i.e., there is a directed edge from node i to node graph[i][j]).
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/

#include<stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int path[MAX_NODES];
int pathIndex;

void findAllPaths(int currentNode, int targetNode)
{
    visited[currentNode] = 1;
    path[pathIndex++] = currentNode;

    if (currentNode == targetNode)
    {
        for (int i = 0; i < pathIndex; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; graph[currentNode][i] != -1; i++)
        {
            int nextNode = graph[currentNode][i];
            if (!visited[nextNode])
            {
                findAllPaths(nextNode, targetNode);
            }
        }
    }

    visited[currentNode] = 0;
    pathIndex--;
}

int main()
{
    int n, m;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);

    printf("Enter the connections:\n");
    for (int i = 0; i < n; i++)
    {
        printf("From node %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        graph[i][m] = -1;
    }

    pathIndex = 0;
    for (int i = 0; i < MAX_NODES; i++)
    {
        visited[i] = 0;
    }

    printf("All possible paths from node 0 to node %d:\n", n - 1);
    findAllPaths(0, n - 1);

    return 0;
}
