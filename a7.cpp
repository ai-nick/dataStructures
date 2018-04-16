#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
class Graph{
    public:
    int stations;
    int routes;
    int graph[100][100];
    Graph(int r, int s);
    void addRoute(int from, int to, int weight);
    bool isRoute(int from, int to);
};
Graph::Graph(int r, int s){
    this->stations = s;
    this->routes = r;
    for (int i = 0; i < s; i++){
        for (int x = 0; x < s; x++){
            this->graph[x][i] = -1;
        }
    }
}

void Graph::addRoute(int from, int to, int weight){
    this->graph[from][to] = weight;
}

bool Graph::isRoute(int from, int to){
    if(this->graph[from][to] >-1){
        return true;
    }
    else return false;
}

void queryRoutes(Graph *g){
    int start;
    int end;
    string cont;
    cout <<"Where would you like to start?"<< endl;
    cin>>start;
    cout <<"Where would you like to end?"<< endl;
    cin>>end;
    if(g->isRoute(start, end)){
        cout<<"Yes you would be able to travel the (weight = "<<g->graph[start][end]<<") route from station "<<start<<" to station "<< end<<"."<<endl;
    } else {
        cout<<"No you would not be able to travel from station "<<start<<" to station "<< end<<"."<<endl;
    }
    cout<<"Would you like to continue (Y/N)?"<<endl;
    cin>>cont;
    if (cont =="y" || cont =="Y"){
        queryRoutes(g);
    }else{
        return;
    }
}

int main(void){
    int stations;
    int routes;
    ifstream file;
    file.open("input.txt");
    string firstLine;
    getline(file, firstLine);
    stringstream first(firstLine);
    first>>stations;
    first>>routes;
    Graph *g = new Graph(routes, stations);
    cout<<"initializing graph with "<<g->stations<<" stations and  " <<g->routes<<" routes"<<endl;
    while(getline(file, firstLine)){
        stringstream edge(firstLine);
        int f, t, w;
        edge>>f>>t>>w;
        g->addRoute(f,t,w);
    }
    queryRoutes(g);
    delete g;
    return 0;
}
