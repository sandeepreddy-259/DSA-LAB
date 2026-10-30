#include <stdio.h>

#define MAX_VERTICES 100

int main(void)
{
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int vertex_count, edge_count, start;
    int front = 0, rear = 0;
    int i, from, to;

    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &vertex_count, &edge_count) != 2 ||
        vertex_count < 1 || vertex_count > MAX_VERTICES ||
        edge_count < 0 || edge_count > vertex_count * (vertex_count - 1) / 2)
    {
        fprintf(stderr, "Invalid number of vertices or edges.\n");
        return 1;
    }

    printf("Enter each edge (two vertex numbers, 0 to %d):\n", vertex_count - 1);
    for (i = 0; i < edge_count; i++)
    {
        if (scanf("%d %d", &from, &to) != 2 ||
            from < 0 || from >= vertex_count ||
            to < 0 || to >= vertex_count || from == to)
        {
            fprintf(stderr, "Invalid edge.\n");
            return 1;
        }

        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    printf("Enter starting vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= vertex_count)
    {
        fprintf(stderr, "Invalid starting vertex.\n");
        return 1;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("Breadth-first traversal: ");
    while (front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);
        for (i = 0; i < vertex_count; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");

    return 0;
}
