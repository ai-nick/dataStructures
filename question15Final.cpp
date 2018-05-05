#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <limits>
#define infinity std::numeric_limits<int>::max()
using namespace std;

class AdjacencyNode{
    public:
    int routes[10];
    void addRoute(int r, int w){
        routes[r] = w;
    }
};

class AdjacencyList{
    public:
    AdjacencyNode *nodes[10];
    AdjacencyList(int v){
        for(int x = 0; x< v; x++){
            AdjacencyNode *n = new AdjacencyNode();
            this->nodes[x] = n;
        }
    }
};

class Graph{
    public:
    int stations;
    int routes;
    int graph[10][10];
    Graph(int r, int s);
    
    void addRoute(int from, int to, int weight);
};
Graph::Graph(int r, int s){
    this->stations = s;
    this->routes = r;
    for (int i = 0; i < s; i++){
        for (int x = 0; x < s; x++){
            this->graph[i][x] = -1;
        }
    }
}

void Graph::addRoute(int from, int to, int weight){
    this->graph[from][to] = weight;
}


int main(void){
    int routes = 4;
    int stations = 4;
    Graph *g = new Graph(routes, stations);
    g->addRoute(0, 1, 3);
    g->addRoute(0, 3, 1);
    g->addRoute(1, 2, 5);
    g->addRoute(2, 3, 5);
    AdjacencyList *al = new AdjacencyList(stations);
    al->nodes[0]->addRoute(1, 3);
    al->nodes[0]->addRoute(3, 1);
    al->nodes[1]->addRoute(2, 5);
    al->nodes[2]->addRoute(3, 5);
    cout<<al->nodes[2]->routes[3]<<endl;
    cout<<g->graph[2][3]<<endl;
    
}