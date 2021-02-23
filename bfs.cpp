#include "graph_algs.h"
#include <queue>
#include <set>

vector<Vertex> GraphAlgs::BFS(Vertex a, Vertex b) {
    // vector of vertex in order of traversal to b
    vector<Vertex> out = {};
    // all edges of this graph
    vector<Edge> edges = g_.getEdges();
    // set starting vertex
    Vertex curr = a;
    // visited vertices
    std::set<Vertex> seen = {};
    // queue for traversal
    std::queue<Vertex> q = {};
    // add first vertex to queue
    q.push(curr);

    while(!q.empty()) {

        curr = q.front();
        q.pop();

        vector<Vertex> adjacency = g_.getAdjacent(curr);

        // add unvisited vertices to queue
        for (unsigned int i = 0; i < adjacency.size(); ++i) {
            if (seen.count(adjacency[i]) != 1) {
                seen.insert(adjacency[i]);
                q.push(adjacency[i]);
            }
        }

        // add current vertex to traversal
        out.push_back(curr);

        // return vector of path if b is found
        if (curr == b) {
            return out;
        }
    }
    // return empty vector if no traversal from a to b is found
    return {};
}