#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;  // {distance, node}

class Graph {
public:
    int V;
    vector<vector<pii>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    void dijkstra(int src) {
        vector<int> dist(V, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();

            int d = top.first;
            int node = top.second;

            for (auto edge : adj[node]) {
                int nbr = edge.first;
                int wt = edge.second;

                if (d + wt < dist[nbr]) {
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " : " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(3,4,1);

    g.dijkstra(0);
    cin.ignore();
    cin.get();
    return 0;
}
