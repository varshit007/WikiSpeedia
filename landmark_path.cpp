#include "graph_algs.h"

vector<Vertex> GraphAlgs::LandmarkPath(Vertex a, Vertex b, Vertex c) {
    vector<Vertex> AtoC = Dijkstra(a, c);
    vector<Vertex> CtoB = Dijkstra(c, b);
    AtoC.insert(AtoC.end(), CtoB.begin() + 1, CtoB.end());
    return AtoC;
}