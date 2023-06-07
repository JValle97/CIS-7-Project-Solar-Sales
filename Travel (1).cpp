#include "Travel.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <queue>
using namespace std;

/******************************************************************************
 * Displays the main menu and calls the appropriate 
 * function based on user selection.
******************************************************************************/
void Travel::mainMenu(Travel t)
{
    switch (toupper(selection))
    {
    case 'A': t.lowestcost(); break;
    case 'B': t.shortestpath(); break;
    case 'C': t.adjacency(); break;
    case 'D': t.matrix(); break;
    }
}
/******************************************************************************
 * Calculates and displays the shortest path round trip for 
 * each city.
******************************************************************************/
void Travel::shortestpath()
{
    // Creating a graph with 4 vertices.
    Graph g(4);
    
    // Adding edges to the graph using the distance array.
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            g.addEdge(i, j, distance[i][j]);
        }
    }
    
    // Looping through each city.
    for (int i = 0; i < 4; i++)
    {
        string name = city[i];
        int currentCity = i;
        
        cout << "Shortest path round trip: " << name << endl 
             << "\t" << city[currentCity];
             
        // Using Dijkstra's algorithm to prevent "reinventing the wheel" and to
        // find the shortest path from the current city to all other cities.
        vector<int> dist(4, numeric_limits<int>::max());
        dist[currentCity] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        greater<pair<int, int>>> pq;
        pq.push({0, currentCity});
        
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            for (int v = 0; v < 4; v++)
            {
                if (g.adjMatrix[u][v] && dist[v] > dist[u] + g.adjMatrix[u][v])
                {
                    dist[v] = dist[u] + g.adjMatrix[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    
        // Finding the next closest city.
        vector<bool> visited(4, false);
        visited[currentCity] = true;
        for (int s = 0; s < 3; s++)
        {
            int minDistance = numeric_limits<int>::max();
            int nextCity;
            for (int n = 0; n < 4; n++)
            {
                if (!visited[n] && dist[n] < minDistance)
                {
                    minDistance = dist[n];
                    nextCity = n;
                }
            }
            cout << " => " << city[nextCity];
            currentCity = nextCity;
            visited[nextCity] = true;
        }
        cout << " => " << city[i] << endl << endl;
    }
}
/******************************************************************************
 * Displays the adjacency list for the selected starting city.
******************************************************************************/
void Travel::adjacency()
{
    cout << endl << "adjacenccy function working" << endl;
    
    // Displays the starting city.
    cout << city[start - 1] << endl;
    
    // Loops through all cities.
    for (int index = 0; index < 4; index++)
    {
        // Displays the distance from the starting city to the current city.
        if (index == 0 || index == 2)
        {
            cout << setw(8) << "=> " << city[index]
                << "\t" << distance[start - 1][index] << " Mi" << endl;
        }
        else
            cout << setw(8) << "=> " << city[index]
            << "\t\t" << distance[start - 1][index] << " Mi" << endl;
    }

    cout << endl;
}
/******************************************************************************
 * Displays the adjacency matrix for all cities.
******************************************************************************/
void Travel::matrix()
{
    cout << endl << "matrix function working" << endl;
    
    // Loops through all cities.
    for (int x = 0; x < 4; x++)
    {
        // Displays the current city.
        cout << "City: " << city[x] << endl;
        
        // Looping through all cities.
        for (int i = 0; i < 4; i++)
        {
            // Displays distance from the current city to the other city.
            cout << setw(4) << "(" << city[x] << ", " << city[i]
                << ", " << distance[x][i] << " Mi)\n";
        }
        cout << endl;
    }
}
/******************************************************************************
 * Calculates and displays the lowest cost path between two cities
 * with an optional stopover.
******************************************************************************/
void Travel::lowestcost()
{
    cout << endl << "Lowest cost function working" << endl;

    int start2EndDist, start2StopDist, firstStopDist, secondStopDist,
        firstStop, secondStop, totalDist;
    
    // Calculates the distance from the starting city to the ending city.
    start2EndDist = distance[start - 1][end - 1];
    // Calculates the distance from the starting city to the stopover city.
    start2StopDist = distance[start - 1][stop - 1];
    
    // Determines if it's faster to go directly to the ending city or to 
    // the stopover city first.
    if (start2EndDist < start2StopDist)
    {
        firstStop = end - 1;
        secondStop = stop - 1;
        firstStopDist = start2EndDist;
        secondStopDist = distance[end - 1][stop - 1];
    }
    else
    {
        firstStop = stop - 1;
        secondStop = end - 1;
        firstStopDist = start2StopDist;
        secondStopDist = distance[stop - 1][end - 1];
    }
    
    // Calculates the total distance of teh lowest cost path.
    totalDist = firstStopDist + secondStopDist;
    
    // Displays lowest cost path.
    cout << "Lowest Cost Path:\n" << setw(13) << city[start - 1]
        << " =>(" << firstStopDist << ") " << city[firstStop] << " =>("
        << secondStopDist << ") " << city[secondStop] << " (= " 
        << totalDist << " Mi)" << endl;
}
/******************************************************************************
 * Sets the menu selection.
******************************************************************************/
void Travel::setSelection(char s)
{
    selection = s;
}
/******************************************************************************
 * Sets the starting city.
******************************************************************************/
void Travel::setStart(int st)
{
    start = st;
}
/******************************************************************************
 * Sets the stopover city.
******************************************************************************/
void Travel::setStop(int sp)
{
    stop = sp;
}
/******************************************************************************
 * Sets the ending city.
******************************************************************************/
void Travel::setEnd(int e)
{
    end = e;
}
/******************************************************************************
 * Returns the menu selection.
******************************************************************************/
char Travel::getSelection()
{
    return selection;
}
/******************************************************************************
 * Returns the starting city.
******************************************************************************/
int Travel::getStart()
{
    return start;
}
/******************************************************************************
 * Returns the ending city.
******************************************************************************/
int Travel::getEnd()
{
    return end;
}
/******************************************************************************
 * Returns the stopover city.
******************************************************************************/
int Travel::getStop()
{
    return stop;
}