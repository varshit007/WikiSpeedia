
This project constructs a graph object initialized with vertex/edge data from an input file and a graph algorithms object which can perform a BFS traversal of the graph, as well as return the shortest path between two vertices through both Dijkstra's Algorithm and the Landmark Path Algorithm

## Data format:
The data set used (http://snap.stanford.edu/data/wikispeedia.html) stores a file of all edges connecting each of 4,592 wikipedia pages to others. The idea behind this is to see how quickly someone using Wikipedia can get from one article to another by following the hyperlinks to other articles. Each article is a vertex and an edge connects one article to another. All edges have a weight of 1, since the weight of a path is based on the number of articles that must be visited

The rules of the data format are:
- Each line should have two articles separated by a semicolon.
- There should be no spaces anywhere on the line.
- If an article name has a space in it it should be replaced with an underscore (_).
- No article names should have a semicolon in them.
- The first article is the source article, the second article is the article the source is linked to.

Here is an example of how the data file should be formatted:  
Article_1;Article_2  
Article_1;Article_3  
Article_2;Article_4  
Article_2;Article_3  
Article_3;Article_1  

This means that:  
Article 1 has a link that leads it to Article 2.  
Article 1 also has a link that leads it to Article 3.  
Article 2 has a link that leads it to Article 4.  
Article 2 also has a link that leads it to Article 3.  
Article 3 has a link that leads it (back) to Article 1.  


## How to Build and Run the Program:
Open this repository in any code editor that support Makefiles and enter the following commands in the terminal:
#### make
#### ./final_project

You will then be prompted to enter a path to a file storing the vertex/edge data, which should be formatted as described above. The path entered should be relative to the repository root. The main data set can be run by entering data/graph_data.txt

The file will then be parsed and the graph and graph algorithms objects will be constructed.

You will then be prompted to enter the vertices (article names) as listed in the data file to perform a Breadth First Search traversal of the graph from one article to another, and also to run Dijkstra's Algorithm and the Landmark Path Algorithm on the graph.

After each algorithm, the output will be printed to the console, which will be all of the vertices (articles) visited from first to last.


To run the unit tests for this project, enter the following commands in the terminal:
#### make test
#### ./test
