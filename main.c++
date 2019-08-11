#include <stdio.h> 
#include <limits.h>
#include <iostream>
#include <vector>

#define V 85

using namespace std;

vector<int> graph[V];
bool sptSet[V];


int minDistance(int dist[], bool sptSet[]){ 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) min = dist[v], min_index = v; 
    }

    return min_index; 
} 


void printPath(int parent[], int j){ 
    if (parent[j] != - 1)
        printPath(parent, parent[j]); 
        printf("%d ", j); 
} 


void printSolution(int dist[], int n, int parent[], int src, int des, bool legalMove){
    if (des == -1){
        printf("Vertex\t Distance\tPath\n"); 
        for (int i = 1; i < V; i++){ 
            if (dist[i] != INT_MAX & ((legalMove && dist[i] <= 10) || !legalMove)){
                printf("%d -> %d \t %d \t\t", src, i, dist[i]); 
                printPath(parent, i); 
                cout << endl;
            }
        } 
    }
    else {
        if (dist[des] != INT_MAX & ((legalMove && dist[des] <= 10) || !legalMove)){
            printf("%d -> %d \t %d \t\t", src, des, dist[des]); 
            printPath(parent, des); 
            cout << endl;
        }
        else cout << "Unreachable with legal moves" << endl;
    }
} 


void dijkstra(vector<int> graph[V], int src, int des, bool legalMove) { 
    int dist[V];  
    int parent[V]; 

    for (int i = 0; i < V; i++) { 
        parent[i] = -1; 
        dist[i] = INT_MAX; 
    }
    dist[src] = 0; 

    for (int count = 0; count < V-1; count++) { 
        int u = minDistance(dist, sptSet); 
        sptSet[u] = true; 
        if (!graph[u].empty()){
            vector<int>::iterator v;
            for(v = graph[u].begin(); v != graph[u].end(); v++){
                if (!sptSet[*v] && dist[u] != INT_MAX && dist[u]+1 < dist[*v]){
                    dist[*v] = dist[u] + 1; 
                    parent[*v] = u; 
                }
            }
        } 
    }
    printSolution(dist, V, parent, src, des, legalMove); 
} 


int main(){ 
    int src;
    int des;
    char legalMove = 'N';
    
    cout << "Source: ";
    cin >> src;
    
    cout << "Destination (All path -1): ";
    cin >> des;
    
    cout << "Only legal move? [y/N]: ";
    cin >> legalMove;
    
    cout << endl;

    graph[0] = {7, 11, 6, 2, 1, 4, 5};
    graph[1] = {2, 3, 4, 0};
    graph[2] = {6, 14, 3, 1, 0};
    graph[3] = {4, 1, 2, 14, 10, 19, 20};
    graph[4] = {1, 3, 20, 21, 5, 0};
    graph[5] = {0, 4, 21};
    graph[6] = {12, 11, 13, 17, 14, 2, 0};
    graph[7] = {15, 9, 8, 11, 0};
    graph[8] = {7, 9, 11};
    graph[9] = {7, 15, 8};
    graph[10] = {3, 19, 18, 14};
    graph[11] = {7, 8, 12, 0};
    graph[12] = {11, 13};
    graph[13] = {12, 11, 6, 17, 16};
    graph[14] = {6, 2, 3, 10, 18, 17};
    graph[15] = {7, 9};
    graph[16] = {13, 17, 36, 38, 32, 48};
    graph[17] = {6, 13, 16, 36, 18, 14};
    graph[18] = {19, 10, 14, 17, 36, 28, 72};
    graph[19] = {20, 3, 10, 18, 72, 23, 22};
    graph[20] = {21, 4, 3, 19, 22};
    graph[21] = {5, 4, 20, 22, 24};
    graph[22] = {21, 20, 19, 23, 24};
    graph[23] = {22, 19, 72, 34, 35, 31, 25, 24};
    graph[24] = {21, 22, 23, 25};
    graph[25] = {24, 23, 31, 27, 26};
    graph[26] = {25, 27};
    graph[27] = {26, 25, 31};
    graph[28] = {29, 72, 18, 36, 38};
    graph[29] = {30, 34, 72, 18, 28};
    graph[30] = {35, 34, 29, 33};
    graph[31] = {27, 25, 23, 35, 33};
    graph[32] = {16, 38};
    graph[33] = {31, 35, 30};
    graph[34] = {35, 30, 29, 72, 23};
    graph[35] = {34, 30, 33, 31, 23};
    graph[36] = {18, 17, 16, 38, 28};
    graph[37] = {41};
    graph[38] = {32, 16, 36, 28, 39};
    graph[39] = {38, 42, 40, 43};
    graph[40] = {39, 41};
    graph[41] = {37, 40};
    graph[42] = {39, 43, 44};
    graph[43] = {71, 45, 44, 39, 42};
    graph[44] = {42, 43, 45, 46};
    graph[45] = {46, 64, 65, 43,44};
    graph[46] = {64, 45, 44, 47};
    graph[47] = {48, 53, 54, 56, 46};
    graph[48] = {49, 50, 51, 53, 47, 16};
    graph[49] = {50, 48};
    graph[50] = {49, 52, 51, 48};
    graph[51] = {52, 50, 55, 53, 48};
    graph[52] = {50, 55, 51};
    graph[53] = {51, 55, 54, 47, 48};
    graph[54] = {53, 55, 57, 56, 47};
    graph[55] = {52, 51, 53, 54, 57};
    graph[56] = {47, 54, 57, 63};
    graph[57] = {55, 54, 56, 63, 58, 59};
    graph[58] = {57, 59, 60, 62, 61, 63};
    graph[59] = {57, 58, 60};
    graph[60] = {59, 58, 62};
    graph[61] = {63, 58, 62, 64};
    graph[62] = {60, 58, 61};
    graph[63] = {56, 57, 58, 61, 64};
    graph[64] = {63, 61, 65, 45, 46};
    graph[65] = {45, 64, 66};
    graph[66] = {65, 67};
    graph[67] = {66, 68};
    graph[68] = {67, 69};
    graph[69] = {68, 70};
    graph[70] = {69, 81};
    graph[71] = {43};
    graph[81] = {70, 82};
    graph[82] = {81, 84};
    graph[84] = {82};

    if (legalMove == 'y') dijkstra(graph, src, des, 1); 
    else dijkstra(graph, src, des, 0); 

    return 0; 
} 
