#include <stdio.h>
#include <string.h>
#define MAX 10

int adj[MAX][MAX];
char city[MAX][20];
int n;

// Create graph
void createGraph() {
    int src, dest, cost;

    printf("Enter number of cities/airports: ");
    scanf("%d", &n);

    // Input city names
    printf("\nEnter names of cities:\n");
    for (int i = 0; i < n; i++) {
        printf("City %d: ", i);
        scanf("%s", city[i]);
    }

    // Initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("\nEnter direct flights (source destination cost)\n");
    printf("(Use city numbers based on the above list)\n");
    printf("Enter -1 -1 -1 to stop.\n");

    while (1) {
        scanf("%d %d %d", &src, &dest, &cost);
        if (src == -1 && dest == -1 && cost == -1)
            break;

        if (src >= 0 && dest >= 0 && src < n && dest < n)
            adj[src][dest] = cost;
            adj[dest][src] = cost;
        else
            printf("Invalid city numbers!\n");
    }
}

// Display adjacency matrix
void displayGraph() {
    printf("\nFlight Cost Matrix:\n      ");
    for (int i = 0; i < n; i++)
        printf("%8s", city[i]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%8s", city[i]);
        for (int j = 0; j < n; j++)
            printf("%8d", adj[i][j]);
        printf("\n");
    }
}

// Check direct flight
void checkFlight() {
    char srcName[20], destName[20];
    int src = -1, dest = -1;

    printf("\nEnter source city name: ");
    scanf("%s", srcName);
    printf("Enter destination city name: ");
    scanf("%s", destName);

    // Find city indices
    for (int i = 0; i < n; i++) {
        if (strcmp(city[i], srcName) == 0)
            src = i;
        if (strcmp(city[i], destName) == 0)
            dest = i;
    }

    if (src == -1 || dest == -1)
        printf("Invalid city name!\n");
    else if (adj[src][dest] != 0)
        printf("✅ Flight from %s → %s with cost %d\n", city[src], city[dest], adj[src][dest]);
    else
        printf("❌ No direct flight from %s → %s\n", city[src], city[dest]);
}

int main() {
    createGraph();
    displayGraph();
    checkFlight();
    return 0;
}
