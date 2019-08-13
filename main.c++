#include <stdio.h> 
#include <limits.h>
#include <iostream>
#include <vector>

#define V 85

using namespace std;

vector<int> map1[V];
bool sptSet[V];


int minDistance(int dist[], bool sptSet[]){ 
    int min = INT_MAX, min_index; 
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min){ 
            min = dist[v];
            min_index = v;
        }
    }
    return min_index; 
} 


void printPath(int parent[], int j){ 
    if (parent[j] != - 1)
        printPath(parent, parent[j]); 
        printf("%d ", j); 
} 


void printSolution(int dist[], int n, int parent[], int src, int des, int legalMove){
    if (des == -1){
        printf("Vertex\t Distance\tPath\n"); 
        for (int i = 0; i < V; i++){ 
            if (src != i && dist[i] != INT_MAX & (((legalMove == 2 && dist[i] <= 7) || legalMove != 2) & ((legalMove == 1 && dist[i] <= 10) || legalMove != 1))){
                printf("%d -> %d \t %d \t\t", src, i, dist[i]); 
                printPath(parent, i); 
                cout << endl;
            }
        }
    } 
    else {
        if (dist[des] != INT_MAX & (((legalMove == 2 && dist[des] <= 7) || legalMove != 2) & ((legalMove == 1 && dist[des] <= 10) || legalMove != 1))){
            printf("%d -> %d \t %d \t\t", src, des, dist[des]); 
            printPath(parent, des); 
            cout << endl;
        }
        else cout << "Unreachable with legal moves" << endl;
    }   
}


void dijkstra(vector<int> graph[V], int src, int des, int legalMove) { 
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
    char legalMove = 'n';
    int typeMove = 0;
    
    cout << "Source: ";
    cin >> src;
    
    cout << "Destination (All path -1): ";
    cin >> des;
    
    cout << "Only legal move? [y/n]: ";
    cin >> legalMove;
    
    if (legalMove == 'y'){
        typeMove = 1;
        cout << "Only safe move? [y/n]: ";
        cin >> legalMove;
        if (legalMove == 'y') typeMove = 2;
    }
    cout << endl;

    map1[0] = {7, 11, 6, 2, 1, 4, 5};
    map1[1] = {2, 3, 4, 0};
    map1[2] = {6, 14, 3, 1, 0};
    map1[3] = {4, 1, 2, 14, 10, 19, 20};
    map1[4] = {1, 3, 20, 21, 5, 0};
    map1[5] = {0, 4, 21};
    map1[6] = {12, 11, 13, 17, 14, 2, 0};
    map1[7] = {15, 9, 8, 11, 0};
    map1[8] = {7, 9, 11};
    map1[9] = {7, 15, 8};
    map1[10] = {3, 19, 18, 14};
    map1[11] = {7, 8, 12, 0};
    map1[12] = {11, 13};
    map1[13] = {12, 11, 6, 17, 16};
    map1[14] = {6, 2, 3, 10, 18, 17};
    map1[15] = {7, 9};
    map1[16] = {13, 17, 36, 38, 32, 48};
    map1[17] = {6, 13, 16, 36, 18, 14};
    map1[18] = {19, 10, 14, 17, 36, 28, 72};
    map1[19] = {20, 3, 10, 18, 72, 23, 22};
    map1[20] = {21, 4, 3, 19, 22};
    map1[21] = {5, 4, 20, 22, 24};
    map1[22] = {21, 20, 19, 23, 24};
    map1[23] = {22, 19, 72, 34, 35, 31, 25, 24};
    map1[24] = {21, 22, 23, 25};
    map1[25] = {24, 23, 31, 27, 26};
    map1[26] = {25, 27};
    map1[27] = {26, 25, 31};
    map1[28] = {29, 72, 18, 36, 38};
    map1[29] = {30, 34, 72, 18, 28};
    map1[30] = {35, 34, 29, 33};
    map1[31] = {27, 25, 23, 35, 33};
    map1[32] = {16, 38};
    map1[33] = {31, 35, 30};
    map1[34] = {35, 30, 29, 72, 23};
    map1[35] = {34, 30, 33, 31, 23};
    map1[36] = {18, 17, 16, 38, 28};
    map1[37] = {41};
    map1[38] = {32, 16, 36, 28, 39};
    map1[39] = {38, 42, 40, 43};
    map1[40] = {39, 41};
    map1[41] = {37, 40};
    map1[42] = {39, 43, 44};
    map1[43] = {71, 45, 44, 39, 42};
    map1[44] = {42, 43, 45, 46};
    map1[45] = {46, 64, 65, 43,44};
    map1[46] = {64, 45, 44, 47};
    map1[47] = {48, 53, 54, 56, 46};
    map1[48] = {49, 50, 51, 53, 47, 16};
    map1[49] = {50, 48};
    map1[50] = {49, 52, 51, 48};
    map1[51] = {52, 50, 55, 53, 48};
    map1[52] = {50, 55, 51};
    map1[53] = {51, 55, 54, 47, 48};
    map1[54] = {53, 55, 57, 56, 47};
    map1[55] = {52, 51, 53, 54, 57};
    map1[56] = {47, 54, 57, 63};
    map1[57] = {55, 54, 56, 63, 58, 59};
    map1[58] = {57, 59, 60, 62, 61, 63};
    map1[59] = {57, 58, 60};
    map1[60] = {59, 58, 62};
    map1[61] = {63, 58, 62, 64};
    map1[62] = {60, 58, 61};
    map1[63] = {56, 57, 58, 61, 64};
    map1[64] = {63, 61, 65, 45, 46};
    map1[65] = {45, 64, 66};
    map1[66] = {65, 67};
    map1[67] = {66, 68};
    map1[68] = {67, 69};
    map1[69] = {68, 70};
    map1[70] = {69, 81};
    map1[71] = {43};
    map1[81] = {70, 82};
    map1[82] = {81, 84};
    map1[84] = {82};

    dijkstra(map1, src, des, typeMove); 

    return 0; 
} 
