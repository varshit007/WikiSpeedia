# CS225 Final Project Results

Broadly speaking, the result of our final project is that it was a success. We completed all of the goals that we outlined in GOALS.md and have a fully functional program with instructions for how to run it in the README.md. We worked well as a team, made improvements to certain aspects of the code based on feedback from each other, and all completed everything which we said we would complete.

More specifically, our implementation is able to fully parse the file, perform a BFS traversal from one point to another, perform Dijkstra's Algorithm, and perform the Landmark Path Algorithm in under 5 seconds, which means the code is implemented efficiently. This will vary slightly depending on how far apart the articles passed in as parameters are, but the code is written as efficiently as it can be. At some point the file parsing was taking nearly 3 full minutes, which goes to show the importance of big O runtime and what a drastic difference a more efficient approach can make.

The biggest takeaway from our project is how easy it is to get from one article to another through Wikipedia, even if the two articles are completely unrelated. For example, to get from Tupac_Shakur, who is a famous rapper, to Mango, which is a random fruit, only takes two intermediary articles per the result of running Dijkstra's Algorithm. This is due to the fact that each Wikipedia article has such a large number of hyperlinks, but Dijkstra's Algorithm really helps to put this into perspective. Our Landmark Path Algorithm simply calls Dijkstra's Algorithm twice, and thus also helps to demonstrate this point. To get from Dinosaur to Currency through Nitrogen, all 3 of which are completely unrelated topics, only takes 6 clicks total.

Overall, this project helped show the importance of big O runtime, how useful graphs can be as data stuctures, and the value of working on a team where everyone shares the same goals.