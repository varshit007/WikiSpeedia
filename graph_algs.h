#pragma once

#include "graph.h"

class GraphAlgs {
    public:
        /**
         * Constructor; initializes GraphAlgs with the given graph
         * @param Graph which algorithms will be performed on
         */
        GraphAlgs(Graph& g) : g_(g) {};

        /**
         * Performs a breadth first search on the graph starting from vertex
         * a ending on vertex b
         * @param a starting vertex
         * @param b target vertex
         * @return a vector of all vertices that were visited from first to last,
         * returns an empty vector of vertices if vector b cannot be found from a
         */
        vector<Vertex> BFS(Vertex a, Vertex b);

        /**
         * Dijkstra's algorithm: returns the shortest path in the graph from a to b
         * @return a vector of all vertices that were visited from a to b
         */
        vector<Vertex> Dijkstra(Vertex a, Vertex b);

        /**
         * Landmark Path algorithm: returns the shortest path in the graph from a to b through c
         * @return a vector of all vertices that were visited from a to b through c
         */
        vector<Vertex> LandmarkPath(Vertex a, Vertex b, Vertex c);

    private:
        Graph g_; /* Graph used for graph algorithms */
};