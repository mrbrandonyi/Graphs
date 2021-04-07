/**
 * @file main.cpp
 * @brief This is HW14 - Matrix Based Graph for CPTR 227 class.
 * @author Brandon Yi
 * @date 4/7/2021
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int n; // the number of vertices
    vector<vector<bool> > a;
    
public:
    Graph(int nV) {
        n = nV;
        for(int i = 0; i < n; i++) {
            vector<bool> newRow(n,false);
            a.push_back(newRow);
        }
    }

    void addEdge(int i, int j) {
        a[i][j] = true;
    }

    void removeEdge(int i, int j) {
        a[i][j] = false;
    }

    bool hasEdge(int i, int j) {
        return a[i][j];
    }

    void outEdges(int i, vector<bool> &edges) {
        for (int j = 0; j < n; j++)
            if (a[i][j]) edges.push_back(j);
    }

    void inEdges(int i, vector<bool> &edges) {
        for (int j = 0; j < n; j++)
            if (a[j][i]) edges.push_back(j);
    }

    int nVertices() {
        return n; 
    }

    void printgraph() {
        cout << "\t";
        for(int i = 0; i < n; i++) {
            cout << i << "\t";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << i << "\t";
            for(int j = 0; j < n; j++)
                cout << a[i][j] << "\t";
            cout << endl;
        }   
    }

};

// breadth-first search
void bfs(Graph &g, int r) {
    bool *seen = new bool[g.nVertices()];
    queue <int> q;
    q.push(r);
    seen[r] = true;
    while (q.size() > 0) {
        int i = q.front();
        q.pop();
        vector<bool> edges;
        g.outEdges(i, edges);
        for (int k = 0; k < edges.size(); k++) {
            int j = edges.at(k);
            if (!seen[j]) {
                q.push(j);
                seen[j] = true;
            }
        }
    }
    delete[] seen;
}

int main() {
    Graph g(12);
    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    g.addEdge(0,4);
    g.addEdge(4,0);
    g.addEdge(4,5);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,5);
    g.addEdge(6,7);
    g.addEdge(7,6);
    g.addEdge(3,7);
    g.addEdge(7,3);
    g.addEdge(1,5);
    g.addEdge(5,1);
    g.addEdge(2,6);
    g.addEdge(6,2);
    g.addEdge(4,8);
    g.addEdge(8,4);
    g.addEdge(8,9);
    g.addEdge(9,8);
    g.addEdge(5,9);
    g.addEdge(9,5);
    g.addEdge(9,10);
    g.addEdge(10,9);
    g.addEdge(6,10);
    g.addEdge(10,6);
    g.addEdge(10,11);
    g.addEdge(11,10);
    g.addEdge(7,11);
    g.addEdge(11,7);
    g.addEdge(1,6);
    g.addEdge(5,2);
    cout << "This is the output of addEdge function" << endl;
    g.printgraph();
    g.addEdge(0,5);
    cout << "Added edge (0,5)" << endl;
    g.printgraph();
    g.removeEdge(0,5);
    cout << "Removed edge(0,5)" << endl;
    g.printgraph();
    g.hasEdge(11,6);
    cout << "This is the output of hasEdge function" << endl;
    g.printgraph();
    
}
