#include <iostream>
#include "Graph.h"

int main(int argc, char* argv[])
{
  Graph<int> G(8);
  G.add_edge(0, 1);
  G.add_edge(0, 3);
  G.add_edge(1, 2);
  G.add_edge(3, 4);
  G.add_edge(3, 7);
  G.add_edge(4, 5);
  G.add_edge(4, 6);
  G.add_edge(4, 7);
  G.add_edge(5, 6);
  G.add_edge(6, 7);
  std::cout << "Adjacency List : " << std::endl;
  G.AdjList();
  std::cout << std::endl;
  std::cout << "Adjacency Matrix : " << std::endl;
  G.AdjMatrix();
  std::cout << std::endl;
  // Find shortest path from 2 to 6
  std::cout << "Shortest path from 2 to 6" << std::endl;
  G.ShortestPath(2,6);
  std::cout << std::endl;
  // Find shortest path from 3 to 5
  std::cout << "Shortest path from 3 to 5" << std::endl;
  G.ShortestPath(3,5);
  return 0;
};
