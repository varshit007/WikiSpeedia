# PROJECT GOALS

### Link to dataset: [http://snap.stanford.edu/data/wikispeedia.html](http://snap.stanford.edu/data/wikispeedia.html)

Our dataset is taken from the Stanford Large Network Dataset Collection, and is called Wikispeedia navigation paths. This dataset stores a list of 4,604 articles from Wikipedia, which is an unweighted directed graph in which each article is a node consisting of other articles as edges. We will parse this file of data and build a directed and unweighted graph in C++. We will implement algorithms (BFS, Dijkstra’s, and Landmark) which will allow us to get from one article (node) to another article (node) through the shortest number of connections as possible.

The format of the data file is tab-separated values (.TSV), where the first column is the source of the link and the second column is the article that is being linked to. 

For the traversal, we will implement Breadth First-Search, since if we want to get from one random article to another, it would make more sense to avoid going down a “rabbit-hole” of unrelated articles which might happen with DFS.

For the covered algorithm, we will implement Dijkstra’s Algorithm in order to find the shortest path between two randomly selected articles. Since our edges are unweighted, we will implement Dijkstra’s Algorithm with a constant weight of 1 for all edges.

For the complex or uncovered option, we will implement Landmark Path, in order to see what the shortest path is from one article to another if we want to look at a third article on the way. For the implementation of Landmark Path, ideally we will use the code we already wrote for Dijkstra’s Algorithm which will allow us to find the shortest path from a to b, then from c to b, and then simply connect the two paths.
