#include "../cs225/catch/catch.hpp"
#include "../graph_algs.h"
#include "../parse_data.h"

const string test_data_path = "tests/test_data.txt";

TEST_CASE("ParseData stores data in graph correctly") {
  SECTION("ParseData stores vertices in graph correctly") {
    Graph g(true, true);
    ParseData(g, test_data_path);

    vector<string> actual_vertices = g.getVertices();
    vector<string> expected_vertices = {"A", "B", "C", "D", "E", "F"};

    //Sort each vector first since graph uses an unordered map
    std::sort(actual_vertices.begin(), actual_vertices.end());
    std::sort(expected_vertices.begin(), expected_vertices.end());

    REQUIRE(actual_vertices == expected_vertices);
  }

  SECTION("ParseData stores edges in graph correctly") {
    Graph g(true, true);
    ParseData(g, test_data_path);

    vector<Edge> actual_edges = g.getEdges();

    vector<Edge> expected_edges;
    expected_edges.emplace_back(Edge("A", "B"));
    expected_edges.emplace_back(Edge("A", "C"));
    expected_edges.emplace_back(Edge("A", "D"));
    expected_edges.emplace_back(Edge("B", "E"));
    expected_edges.emplace_back(Edge("B", "C"));
    expected_edges.emplace_back(Edge("C", "E"));
    expected_edges.emplace_back(Edge("D", "A"));
    expected_edges.emplace_back(Edge("D", "F"));
    expected_edges.emplace_back(Edge("E", "F"));

    //Sort each vector first since graph uses an unordered map 
    std::sort(actual_edges.begin(), actual_edges.end());
    std::sort(expected_edges.begin(), expected_edges.end());

    //Both vectors should be the same size
    REQUIRE(actual_edges.size() == expected_edges.size());

    //Source and destination vertex of each edge should be the same
    for (size_t i = 0; i < actual_edges.size(); ++i) {
      REQUIRE(actual_edges[i].source == expected_edges[i].source);
      REQUIRE(actual_edges[i].dest == expected_edges[i].dest);
    }
  }

  SECTION("ParseData works on nonexistent file") {
    Graph g(true, true);
    ParseData(g, "File Doesn't Exist");

    REQUIRE(g.getVertices().size() == 0);
    REQUIRE(g.getEdges().size() == 0);
  }

  SECTION("ParseData works on empty file") {
    Graph g(true, true);
    ParseData(g, "tests/empty_file.txt");

    REQUIRE(g.getVertices().size() == 0);
    REQUIRE(g.getEdges().size() == 0);
  }

  SECTION("ParseData works on incorrectly formatted file") {
    Graph g(true, true);
    ParseData(g, "tests/incorrect_format.txt");

    //per our formatting, this file contains 11 vertices and 6 edges
    REQUIRE(g.getVertices().size() == 11);
    REQUIRE(g.getEdges().size() == 6);
  }
}

TEST_CASE("Graph Algorithms work correctly") {

  SECTION("BFS catches impossible traversals (Easy)") {
    Graph g_(true, true);
    g_.insertVertex("a"); 
    g_.insertVertex("b"); 

    g_.insertEdge("a", "b"); 

    GraphAlgs ga(g_);

    vector<Vertex> actual_breadth_first = ga.BFS("a", "b");
    vector<Vertex> expected_breadth_first = {"a", "b"};

    REQUIRE(actual_breadth_first == expected_breadth_first);
  }

  SECTION("BFS traverses graph correctly (Hard)") {
    Graph g_(true, true);
    g_.insertVertex("a"); 
    g_.insertVertex("b"); 
    g_.insertVertex("c"); 
    g_.insertVertex("d"); 
    g_.insertVertex("e");

    g_.insertEdge("a", "b"); 
    g_.insertEdge("a", "c"); 
    g_.insertEdge("b", "c"); 
    g_.insertEdge("b", "d");
    g_.insertEdge("c", "d");
    g_.insertEdge("d", "e");
    g_.insertEdge("c", "e");

    GraphAlgs ga(g_);

    vector<Vertex> actual_breadth_first = ga.BFS("a", "e");
    vector<Vertex> expected_breadth_first = {"a", "b", "c", "d", "e"};

    REQUIRE(actual_breadth_first == expected_breadth_first);
  }

  SECTION("BFS catches impossible traversals") {
    Graph g_(true, true);
    g_.insertVertex("a"); 
    g_.insertVertex("b"); 

    g_.insertEdge("a", "b"); 

    GraphAlgs ga(g_);

    vector<Vertex> actual_breadth_first = ga.BFS("b", "a");
    vector<Vertex> expected_breadth_first = {};

    REQUIRE(actual_breadth_first == expected_breadth_first);
  }

  SECTION("BFS on unconnected graph") {
    Graph g_(true, true);
    g_.insertVertex("a"); 
    g_.insertVertex("b"); 

    GraphAlgs ga(g_);

    vector<Vertex> actual_breadth_first = ga.BFS("a", "b");
    vector<Vertex> expected_breadth_first = {};

    REQUIRE(actual_breadth_first == expected_breadth_first);
  }

  SECTION("Dijkstra's algorithm returns shortest path from a to b") {
    Graph g_(true, true);
    g_.insertVertex("a"); 
    g_.insertVertex("b"); 
    g_.insertVertex("c"); 
    g_.insertVertex("d"); 
    g_.insertVertex("e");

    g_.insertEdge("a", "b"); 
    g_.insertEdge("a", "c"); 
    g_.insertEdge("b", "c"); 
    g_.insertEdge("b", "d");
    g_.insertEdge("c", "d");
    g_.insertEdge("d", "e");
    g_.insertEdge("c", "e");

    GraphAlgs ga(g_);

    vector<string> actual_shortest_path = ga.Dijkstra("a", "e");
    vector<string> expected_shortest_path = {"a", "c", "e"};

    REQUIRE(actual_shortest_path == expected_shortest_path);
  }

  SECTION("Landmark Path algorithm returns shortest path from a to b through c") {
    Graph g_(true, true);
    g_.insertVertex("a"); 
    g_.insertVertex("b"); 
    g_.insertVertex("c"); 
    g_.insertVertex("d"); 
    g_.insertVertex("e");

    g_.insertEdge("a", "b"); 
    g_.insertEdge("a", "c"); 
    g_.insertEdge("b", "c"); 
    g_.insertEdge("b", "d");
    g_.insertEdge("c", "b");
    g_.insertEdge("c", "d");
    g_.insertEdge("d", "e");
    g_.insertEdge("c", "e");

    GraphAlgs ga(g_);

    vector<string> actual_shortest_path = ga.LandmarkPath("a", "e", "c");
    vector<string> expected_shortest_path = {"a", "c", "e"};

    REQUIRE(actual_shortest_path == expected_shortest_path);
  }

  SECTION("Shortest path adjacent") {
    const string data_path = "data/graph_data.txt";
    Graph g(true, true);
    ParseData(g, data_path);
    GraphAlgs ga(g);
    vector<string> dijkstra = ga.Dijkstra("Fruit", "Mango");
    vector<string> expected = {"Fruit", "Mango"};
    REQUIRE(dijkstra == expected);
  }

  SECTION("Shortest path 1 step") {
    const string data_path = "data/graph_data.txt";
    Graph g(true, true);
    ParseData(g, data_path);
    GraphAlgs ga(g);
    vector<string> dijkstra = ga.Dijkstra("California", "Mango");
    vector<string> expected = {"California", "Fruit", "Mango"};
    REQUIRE(dijkstra == expected);
  }

  SECTION("Landmark path many steps") {
    const string data_path = "data/graph_data.txt";
    Graph g(true, true);
    ParseData(g, data_path);
    GraphAlgs ga(g);
    vector<string> landmark = ga.LandmarkPath("Dinosaur", "Currency", "Nitrogen");
    vector<string> expected = {"Dinosaur", "Argentina", "Agriculture", "Nitrogen", "Alchemy", 
    "Ancient_Egypt", "Currency"};
    REQUIRE(landmark == expected);
  }
}