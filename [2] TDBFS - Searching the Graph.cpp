#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    vector <int> neighbours;
    bool visited = false;
};


class Graph {
private:
    vector <int> sequence;
    stack <int> myStack;
    queue <int> myQueue;
    vector <Node> graph;
    vector <Node> graphBackup;
public:


    void DFS(int vertex);
    void BFS(int vertex);
    void showSequence();
    void makeGraphBackup();
    void restorGraphBackup();
    void addNode();
    void addNeighbor(int neighbor);
};


void Graph::BFS(int vertex) {
    myQueue.push(vertex);
    sequence.push_back(vertex);
    graph[vertex].visited = true;

    while(!myQueue.empty()) {
        vertex = myQueue.front();
        myQueue.pop();

        for(int i = 0, sasiad; i < graph[vertex].neighbours.size(); i++) {
            sasiad = graph[vertex].neighbours[i];
            if(!graph[sasiad].visited) {
                myQueue.push(sasiad);
                sequence.push_back(sasiad);
                graph[sasiad].visited = true;
            }
        }
        graph[vertex].neighbours.clear();
    }
}

void Graph::DFS(int vertex) {
    myStack.push(vertex);
    sequence.push_back(vertex);
    graph[vertex].visited = true;
    while(!myStack.empty()) {
        bool visited = false;
        vertex = myStack.top();

        for(int i = 0, sasiad; i < graph[vertex].neighbours.size(); i++) {
            sasiad = graph[vertex].neighbours[i];
            if(!graph[sasiad].visited) {
                visited = true;
                myStack.push(sasiad);
                sequence.push_back(sasiad);
                graph[sasiad].visited = true;
                break;
            }
        }

        if(!visited)
            myStack.pop();
    }
}

void Graph::showSequence() {
    for(int i = 0; i < sequence.size(); i++)
        cout << sequence[i] << " ";
    cout << endl;
    sequence.clear();
}

void Graph::makeGraphBackup() {
    graphBackup = graph;
}

void Graph::restorGraphBackup() {
    graph = graphBackup;
}

void Graph::addNode() {
    Node node;
    graph.push_back(node);
}

void Graph::addNeighbor(int neighbor) {
    graph.back().neighbours.push_back(neighbor);
}


int main() {
    ios_base::sync_with_stdio(0);
    int t, n, m, a, v, i;
    cin >> t;

    for(int k = 0; k < t; k++) {
        cin >> n;
        Graph graph;
        graph.addNode();
        for(int j = 0; j < n; j++) {
            cin >> i >> m;
            graph.addNode();
            while(m--) {
                cin >> a;
                graph.addNeighbor(a);
            }
        }

        cout << "graph " << k + 1 << endl;
        graph.makeGraphBackup();
        while(cin >> v >> i) {
            if(v == 0 && i == 0) break;

            if(0 == i) graph.DFS(v);
            else graph.BFS(v);
            graph.showSequence();
            graph.restorGraphBackup();
        }
    }
}