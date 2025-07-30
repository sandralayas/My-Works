# Q11: a) Create an adjacency list representation for a given undirected graph
# b) Implement a function to add an edge between two vertices in the graph.
# c) Write an R function to perform DFS traversal on a graph starting from a specific vertex.

install.packages("igraph")

library(igraph)
 
users <- data.frame(UserID = 1:10, 
                    Name = c("User1", "User2", "User3", "User4", "User5",
                             "User6",
                             "User7", "User8", "User9", "User10"), 
                    Gender = c("M", "F", "M", "M", "F", "F", "M", "F", 
                               "M", "M"))
 
friendships <- data.frame(UserID1 = c(1, 1, 2, 2, 3, 3, 4, 5, 6, 7), 
                          UserID2 = c(2, 3, 4, 5, 4, 6, 5, 8, 8, 9))
graph <- graph.data.frame(friendships, directed = FALSE, vertices = users)
V(graph)$color <- ifelse(V(graph)$Gender == "M", "blue", "pink")
node_sizes <- degree(graph, mode = "all")
# Choose a layout (Fruchterman-Reingold)
layout <- layout_with_fr(graph)
plot(graph, layout = layout, vertex.label.dist = 2, vertex.label.cex = 1.2, 
     vertex.size = node_sizes)
