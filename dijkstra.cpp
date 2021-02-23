#include "graph_algs.h"
#include <queue>
#include <map>

using std::priority_queue;
using std::greater; 
using std::map; 

vector<Vertex> GraphAlgs::Dijkstra(Vertex a, Vertex b) {
  //Pseudocode: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Pseudocode 

  //Initialize min. priority queue which stores pairs for vertex and distances in ascending order. 
  //https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
  priority_queue< pair<Vertex, int>, vector <pair<Vertex, int>> , greater<pair<Vertex, int>> > min_pq; 

  //Initialize a map which stores the distance from 'a' to any other vertex.  
  map<Vertex, int> dist; 
  min_pq.push(make_pair(a, 0)); //Distance from 'a' to 'a' is 0

  //Keep track of the previous node from a node. 
  map<Vertex, Vertex> prev;

  //Set initial distances to infinity (max int value)
  for (auto v: g_.getVertices()) {
    dist[v] = INT_MAX;  
  }
  dist[a] = 0;

  //The main loop:
  while(!min_pq.empty()) {
    //Store and remove best vertex
    Vertex u = min_pq.top().first;
    min_pq.pop();

    //Go through every neighbor and save the shortest distance, vertex. 
    for (auto v : g_.getAdjacent(u)) {
      int weight = g_.getEdgeWeight(u, v); 
      int alt = dist[u] + weight;
      if (alt < dist[v]) {
        dist[v] = alt; 
        prev[v] = u;
        min_pq.push(make_pair(v, dist[v])); 
      }
    }
    //If we've reached and processed the end node, we can terminate early without traversing through the entire graph. 
    if (u == b) {
      break; 
    }
  }

  //Store the path to the shortest node:
  //source: https://stackoverflow.com/questions/62096930/keeping-track-of-the-shortest-path-between-two-nodes-using-dijkstras-algorithm
  vector<Vertex> path;
  while (b != a) {
      path.emplace_back(b);
      b = prev[b];
  }
  path.emplace_back(b);
  std::reverse(path.begin(), path.end());

  return path; 
}