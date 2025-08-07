#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph {
private:
    int V;
    vector<unordered_map<int, int>> adjList;
    vector<bool> remainingNodes;
    vector<int> remainingIndices;

public:
    Graph(int vertices) : V(vertices), adjList(vertices), remainingNodes(vertices, true) {
        remainingIndices.reserve(V);
        for (int i = 0; i < V; ++i) {
            remainingIndices.push_back(i);
        }
        srand(time(0));
    }

    void addEdge(int u, int v, int weight) {
        adjList[u][v] = weight;
        adjList[v][u] = weight;
    }

    void generateCase1(int k) {
        int center = rand() % V;

        for (int i = 0; i < V; ++i) {
            if (i != center) {
                addEdge(center, i, 1 + rand() % 100);
            }
        }

        int edgesAdded = 0;
        while (edgesAdded < k) {
            int u = rand() % V;
            int v = rand() % V;
            if (u != v && adjList[u].count(v) == 0) {
                addEdge(u, v, 1 + rand() % 100);
                edgesAdded++;
            }
        }
    }

    void generateCase2(int k) {
        for (int i = 0; i < V - 1; ++i) {
            addEdge(i, i + 1, 1 + rand() % 100);
        }

        int edgesAdded = 0;
        while (edgesAdded < k) {
            int u = rand() % V;
            int v = rand() % V;
            if (u != v && adjList[u].count(v) == 0) {
                addEdge(u, v, 1 + rand() % 100);
                edgesAdded++;
            }
        }
    }

    void APUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, int& time) {
        struct Frame {
            int u, childIdx, children;
            Frame(int u) : u(u), childIdx(0), children(0) {}
        };
        vector<Frame> stack;
        stack.emplace_back(u);
        visited[u] = true;
        disc[u] = low[u] = ++time;
        vector<int> neighbors;
        for (const auto& edge : adjList[u]) {
            if (remainingNodes[edge.first]) neighbors.push_back(edge.first);
        }
        vector<vector<int>> allNeighbors(V);
        allNeighbors[u] = neighbors;
        while (!stack.empty()) {
            Frame& frame = stack.back();
            int curr = frame.u;
            if (frame.childIdx == 0 && curr != u) {
                disc[curr] = low[curr] = ++time;
            }
            neighbors = allNeighbors[curr];
            bool advanced = false;
            for (; frame.childIdx < (int)neighbors.size(); ++frame.childIdx) {
                int v = neighbors[frame.childIdx];
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = curr;
                    frame.children++;
                    vector<int> nbs;
                    for (const auto& e : adjList[v]) if (remainingNodes[e.first]) nbs.push_back(e.first);
                    allNeighbors[v] = nbs;
                    stack.emplace_back(v);
                    advanced = true;
                    ++frame.childIdx;
                    break;
                } else if (v != parent[curr]) {
                    low[curr] = min(low[curr], disc[v]);
                }
            }
            if (advanced) continue;
            if (curr != u) {
                int p = parent[curr];
                low[p] = min(low[p], low[curr]);
                if (parent[p] != -1 && low[curr] >= disc[p]) ap[p] = true;
            } else {
                if (frame.children > 1) ap[curr] = true;
            }
            stack.pop_back();
        }
    }

    vector<bool> findArticulationPoints() {
        vector<bool> visited(V, false), ap(V, false);
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        for (int i = 0; i < V; ++i) {
            if (remainingNodes[i] && !visited[i]) {
                int time = 0;
                APUtil(i, visited, disc, low, parent, ap, time);
            }
        }
        return ap;
    }

    vector<int> deleteNodesKeepConnected() {
        vector<int> deletionOrder;
        int nodesLeft = 0;
        for (bool b : remainingNodes) if (b) nodesLeft++;
        vector<int> degree(V, 0);
        for (int i = 0; i < V; ++i) {
            if (!remainingNodes[i]) continue;
            for (const auto& e : adjList[i]) {
                if (remainingNodes[e.first]) degree[i]++;
            }
        }
        while (nodesLeft > 1) {
            bool foundLeaf = false;
            for (int i = 0; i < V; ++i) {
                if (remainingNodes[i] && degree[i] == 1) {
                    deletionOrder.push_back(i);
                    remainingNodes[i] = false;
                    nodesLeft--;
                    for (const auto& e : adjList[i]) {
                        int nb = e.first;
                        if (remainingNodes[nb]) degree[nb]--;
                    }
                    degree[i] = 0;
                    foundLeaf = true;
                    break;
                }
            }
            if (foundLeaf) continue;
            vector<bool> ap = findArticulationPoints();
            int nodeToDelete = -1;
            for (int i = 0; i < V; ++i) {
                if (remainingNodes[i] && !ap[i]) {
                    nodeToDelete = i;
                    break;
                }
            }
            if (nodeToDelete == -1) break;
            deletionOrder.push_back(nodeToDelete);
            remainingNodes[nodeToDelete] = false;
            nodesLeft--;
            for (const auto& e : adjList[nodeToDelete]) {
                int nb = e.first;
                if (remainingNodes[nb]) degree[nb]--;
            }
            degree[nodeToDelete] = 0;
        }
        for (int i = 0; i < V; ++i) {
            if (remainingNodes[i]) {
                deletionOrder.push_back(i);
                break;
            }
        }
        return deletionOrder;
    }

};