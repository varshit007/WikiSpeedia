#include "parse_data.h"
#include <iostream>
using std::ifstream;

Graph& ParseData(Graph& g, string file_path) {
    if (g.getVertices().size() > 0) g.clear();

    //open stream for parsing file
    ifstream in(file_path); string line;

    while (getline(in, line)) {
        string vertex; //vertex string will be built twice for every line of file
        string prev_vertex; //used for creating edge

        //iterating over this line of the file
        for (size_t i = 0; i < line.size(); ++i) {
            //once you hit semicolon, add vertex to graph, store in prev_vertex and clear vertex
            if (line[i] == ';' && vertex.size() > 0) {
                g.insertVertex(vertex);

                //handles edge case for incorrect formatting
                if (prev_vertex.size() > 0) {
                    g.insertEdge(prev_vertex, vertex);
                }
                
                prev_vertex = vertex;
                vertex.clear();
            } else if (line[i] != ';') {
                vertex += line[i];
            }
        }
        //reached end of line, add second vertex and edge between prev_vertex and vertex
        if (vertex.size() > 0) {
            g.insertVertex(vertex);
            g.insertEdge(prev_vertex, vertex);
        }
    }
    
    return g;
}