#ifndef TRAVEL_H
#define TRAVEL_H
#include <string>
#include <vector>
using namespace std;


// Defining a graph data structure
struct Graph {
    int V;
    vector<vector<int>> adjMatrix;
    
    Graph(int V) : V(V), adjMatrix(V, vector<int>(V)) {};
    
    void addEdge(int u, int v, int w){
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }
};

class Travel
{
private:
    // Member variables
    char selection;
    int start,
        stop,
        end;

    std::string city[4] = {
        "Riverside", "Perris",
        "Moreno Valley", "Hemet"
    };
    int distance[4][4] = {
        { 0, 24, 16, 33 },
        { 24, 0, 18, 30 },
        { 16, 18, 0, 26 },
        { 33, 30, 26, 0 }
    };
    

public:
    // Member functions
    void mainMenu(Travel);
    void lowestcost();
    void shortestpath();
    void adjacency();
    void matrix();

    void setSelection(char);
    void setStart(int);
    void setEnd(int);
    void setStop(int);

    char getSelection();
    int getStart();
    int getEnd();
    int getStop();
};

#endif
