#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <limits>
#define infinity std::numeric_limits<int>::max()
using namespace std;

class Graph{
    public:
    int stations;
    int routes;
    int graph[100][100];
    int shorts[100][100];
    Graph(int r, int s);
    
    void addRoute(int from, int to, int weight);
    void calcShortestPaths(){
        for(int k = 0; k < this->stations; k++){
            for(int i =0; i < this->stations; i++){
                for(int j = 0; j<this->stations; j++){
                    if((this->graph[i][j] > this->graph[i][k]+this->graph[k][j] and this->graph[i][k] != infinity and this->graph[k][j] !=infinity) and (this->graph[i][k] != -1 or this->graph[k][j] != -1)){
                        this->graph[i][j] = this->graph[i][k]+this->graph[k][j];
                        this->shorts[i][j] = this->graph[i][k];
                    }
                }
            }
        }
    }
    vector<int> getPath(int s, int e){
        vector<int> path;
        if(this->shorts[s][e] == -1){
            return path;
        }
        while(s != e){
            s = this->shorts[s][e];
            path.push_back(s);
        }
        return path;
    }
    int shortestPath(int src, int dest){
        this->calcShortestPaths();
        return this->graph[src][dest];
    }
    int searchPaths(int from, int to){
        int w;
        w = 0;
        if(this->graph[from][to] != infinity){
            w += this->graph[from][to];
            return w;
        } else {
            for (int x = 0; x < this->stations; x++){
                int k = this->graph[from][x];
                if( k != infinity){
                    int depth = this->searchPaths(x,to);
                    if(depth > 0){
                        return w+depth+k;
                    }
                }
            }
            // looped and found no path to the to station
            return w;
        }
    }
    bool isPath(int from, int to){
        if(searchPaths(from, to)<infinity){
            return true;
        }
        return false;
    }
};
Graph::Graph(int r, int s){
    this->stations = s;
    this->routes = r;
    for (int i = 0; i < s; i++){
        for (int x = 0; x < s; x++){
            this->shorts[i][x] = -1;
            this->graph[i][x] = infinity;
        }
    }
}

void Graph::addRoute(int from, int to, int weight){
    this->graph[from][to] = weight;
}


void queryRoutes(Graph *g, bool shortest){
    string start;
    string end;
    map<string, int> index;
    map<int, string> revindex;
    string line;
    string tempS;
    int tempI;
    ifstream f;
    f.open("input2.txt");
    while(getline(f, line)){
        stringstream p(line);
        p>>tempI>>tempS;
        index.insert(make_pair(tempS, tempI));
        revindex.insert(make_pair(tempI, tempS));
        cout<<"made pair "<<tempS<<"->"<<tempI<<endl;
    }
    string cont;
    cout <<"Where would you like to start?"<< endl;
    cin>>start;
    cout <<"Where would you like to end?"<< endl;
    cin>>end;
    int pathLength = shortest ? g->shortestPath(index[start], index[end]) : g->searchPaths(index[start], index[end]);
    if(pathLength < infinity and pathLength != infinity){
        vector<int> routes = g->getPath(index[start], index[end]);
        cout<<"Your path will be "<<endl;
        for(int i = 0; i < routes.size(); i++){
            cout<<"-> "<<revindex[routes[i]]<<endl;
        }
        cout<<endl;
    } else {
        cout<<"No you would not be able to travel from station "<<start<<" to station "<< end<<"."<<endl;
    }
    cout<<"Would you like to continue (Y/N)?"<<endl;
    cin>>cont;
    if (cont =="y" || cont =="Y"){
        queryRoutes(g, shortest);
    }else{
        return;
    }
}
void printMenu(){
    cout<<"--Menue--\n"<<endl;
    cout<<"0 -> exit \n"<<endl;
    cout<<"1 -> print menu \n"<<endl;
    cout<<"2 -> check if path exists (recursive, performance agnostic for existence of path)\n"<<endl;
    cout<<"3 -> get shortest path if exists\n"<<endl;
}

void menu(Graph *g){
    int selection;
    cin>>selection;
    switch(selection){
    case 0:
        return;
    case 1:
        printMenu();
        menu(g);
    case 2:
        queryRoutes(g, false);
        break;
    case 3:
        queryRoutes(g, true);
        break;
    default:
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
    printMenu();
    menu(g);

    delete g;
    return 0;
}
