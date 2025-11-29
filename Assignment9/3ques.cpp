#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// ---------------- KRUSKAL ----------------
struct Edge {
    int u, v, wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[a] > rank[b]) parent[b] = a;
    else { parent[b] = a; rank[a]++; }
}

// ---------------- PRIM ----------------
typedef pair<int,int> pii;  // {wt, node}

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

    void primMST() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> inMST(V, false);

        pq.push({0, 0});
        int total = 0;

        cout << "\nPrim's MST:\n";

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();

            int wt  = top.first;
            int node = top.second;

            if (inMST[node]) continue;
            inMST[node] = true;
            total += wt;

            cout << "Pick node " << node << " weight " << wt << endl;

            for (auto edge : adj[node]) {
                int nbr = edge.first;
                int w   = edge.second;

                if (!inMST[nbr])
                    pq.push({w, nbr});
            }
        }

        cout << "Total Weight = " << total << endl;
    }
};

// ---------------- MAIN ----------------
int main() {

    // -------- KRUSKAL --------
    vector<Edge> edges = {
        {0,1,10},{0,2,6},{0,3,5},{2,3,4},{1,3,15}
    };

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(4), rank(4,0);
    for (int i=0;i<4;i++) parent[i]=i;

    cout << "Kruskal MST:\n";
    int cost = 0;

    for (auto e : edges) {
        if (findParent(e.u,parent) != findParent(e.v,parent)) {
            cout << e.u << " - " << e.v << " : " << e.wt << endl;
            cost += e.wt;
            unionSet(e.u, e.v, parent, rank);
        }
    }
    cout << "Total Weight = " << cost << endl;

    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(2,3,4);

    g.primMST();
    cin.ignore();
    cin.get();
    return 0;
}
