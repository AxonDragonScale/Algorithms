// https://www.geeksforgeeks.org/shortest-paths-from-all-vertices-to-a-destination/

// Given a Weighted Directed Graph and a destination vertex in the graph, find the shortest distance from all vertex to
// the destination vertex.

// Basic idea is to reverse all edges of the graph and run a djikstra from the destination and find shortest to all
// vertices.