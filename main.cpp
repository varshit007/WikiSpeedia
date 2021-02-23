#include "graph_algs.h"
#include "parse_data.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "CS225 Final Project Main Called" << endl;
    const string divider = "-----------------------------------------";
    cout << divider << endl;

    Graph g(true, true);

    string data_path;
    
    while (data_path.empty()) {
        cout << "Enter a valid path to a file of graph data: (data/graph_data.txt is our main data set)" << endl;
        cin >> data_path;
        ParseData(g, data_path);

        while (g.getVertices().size() < 3) {
            cout << "Invalid data file path entered, or file does not contain enough vertices." << endl;
            data_path = "";
            while (data_path.empty()) {
                cout << "Enter a valid path to the file of graph data: (data/graph_data.txt is our main data set)" << endl;
                cin >> data_path;
                ParseData(g, data_path);
            }
        }
    }

    /* File parsing stores data in graph object */
    cout << divider << endl;
    cout << "PARSING" << endl << endl;

    cout << "Number of vertices: " << g.getVertices().size() << endl;
    cout << "Number of edges: " << g.getEdges().size() << endl;

    cout << divider << endl;

    /* Creates GraphAlgs object using graph from above */
    GraphAlgs ga(g);
    
    string bfsStart;
    string bfsTarget;
    while (bfsStart.empty() || !g.vertexExists(bfsStart)) {
        cout << "BFS | Enter a valid starting vertex: " << endl;
        cin >> bfsStart;
    }

    cout << "\nBFS | Starting vertex set to " << bfsStart << endl << endl;

    while (bfsTarget.empty() || !g.vertexExists(bfsTarget)) {
        cout << "BFS | Enter a valid target vertex: " << endl;
        cin >> bfsTarget;
    }

    cout << "\nBFS | Target vertex set to: " << bfsTarget << endl << endl;

    // sample inputs:
    // "10th_century"
    // "Black_Death"

    /* BFS returns breadth first traversal from one article to another */
    vector<Vertex> bfs = ga.BFS(bfsStart, bfsTarget);

    cout << "BFS TRAVERSAL" << endl << endl;
    for (auto& v : bfs) cout << v << " -> "; cout << "Done.";

    cout << endl << divider << endl;

    string dkStart;
    string dkTarget;
    while (dkStart.empty() || !g.vertexExists(dkStart)) {
        cout << "Dijkstra | Enter a valid starting vertex: " << endl;
        cin >> dkStart;
    }

    cout << "\nDijkstra: Starting vertex set to " << dkStart << endl << endl;

    while (dkTarget.empty() || !g.vertexExists(dkTarget)) {
        cout << "Dijkstra | Enter a valid target vertex: " << endl;
        cin >> dkTarget;
    }

    cout << "\nDijkstra | Target vertex set to " << dkTarget << endl << endl;

    // sample inputs:
    // "Tupac_Shakur"
    // "Mango"

    /* Dijkstra's algorithm returns the shortest path from one article to another */
    vector<Vertex> dijkstra = ga.Dijkstra(dkStart, dkTarget);

    cout << "DIJKSTRA'S ALGORITHM (shortest path)" << endl;
    cout << "Start: " << dkStart << "   End: " << dkTarget << endl << endl;
    for (auto& v : dijkstra) cout << v << " -> "; cout << "Done.";

    cout << endl << divider << endl;

    string lmStart;
    string lmLandmark;
    string lmTarget;
    while (lmStart.empty() || !g.vertexExists(lmStart)) {
        cout << "Landmark | Enter a valid starting vertex: " << endl;
        cin >> lmStart;
    }

    cout << "\nLandmark: Starting vertex set to " << lmStart << endl << endl;

    while (lmLandmark.empty() || !g.vertexExists(lmLandmark)) {
        cout << "Landmark | Enter a valid landmark vertex: " << endl;
        cin >> lmLandmark;
    }

    cout << "\nLandmark | Landmark vertex set to " << lmLandmark << endl << endl;

    while (lmTarget.empty() || !g.vertexExists(lmTarget)) {
        cout << "Landmark | Enter a valid target vertex: " << endl;
        cin >> lmTarget;
    }

    cout << "\nLandmark | Target vertex set to " << lmTarget << endl << endl;

    // sample inputs
    // "Dinosaur"
    // "Currency"
    // "Nitrogen"

    /* Landmark Path algorithm returns the shortest path from one article to another through another */
    vector<Vertex> landmark = ga.LandmarkPath(lmStart, lmTarget, lmLandmark);

    cout << "LANDMARK PATH ALGORITHM" << endl;
    cout << "Start: " << lmStart << "    End: "<< lmTarget <<"   Landmark: " << lmLandmark << endl << endl;
    for (auto& v : landmark) cout << v << " -> "; cout << "Done.";

    cout << endl << divider << endl;

    return 0;
}