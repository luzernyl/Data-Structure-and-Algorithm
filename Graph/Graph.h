/**
 * @file   Graph.h
 * @author Luzern Yuven Luis <student@student>
 * @date   Sun Jan  3 19:48:56 2021
 * 
 * @brief  Finding Shortest Path in an Undirected Unweighted Graph
 *         using Modified Breadth-First Search.
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <limits>

#define MAX (std::numeric_limits<TYPE>::max())
#define MIN (std::numeric_limits<TYPE>::min())

template <class TYPE>
class Graph
{
 private:
  int v; // number of vertices
  std::vector<TYPE> *adj; // array for adjacency list
  bool** mat; // array for adjacency matrix
  TYPE *pred; // stores the predecessor of vertex
  int *dist; // stores the distance from source to vertex
  
 public:
  Graph(int v);
  void add_edge(TYPE source, TYPE dest);
  bool BFS(TYPE source, TYPE dest);
  void ShortestPath(TYPE source, TYPE dest);
  void AdjList();
  void AdjMatrix();
};

/** 
 * Constructor. Creates an array for adjacency list
 * and a 2D array for adjacency matrix
 * 
 * @param v number of vertices
 * 
 * @return NULL
 */
template <class TYPE>
Graph<TYPE>::Graph(int v)
{
   this->v = v;
   adj = new std::vector<TYPE>[v];
   mat = new bool*[v];
   // Initialize the matrix to 0
   for (int i = 0; i < v; i++)
     {
       mat[i] = new bool[v];
       for (int j = 0; j < v; j++)
	 mat[i][j] = false;
     }
   pred = new TYPE[v];
   dist = new int[v];
};

/** 
 * Add an edge to the graph
 * 
 * @param source source of the edge
 * @param dest destination of the edge
 */
template <class TYPE>
void Graph<TYPE>::add_edge(TYPE source, TYPE dest)
{
  adj[source].push_back(dest);
  adj[dest].push_back(source);
  // Set to true if adjacent
  mat[source][dest] = true;
  mat[dest][source] = true;   
};

/** 
 * A function to print the adjacency list
 * 
 */
template <class TYPE>
void Graph<TYPE>::AdjList()
{
  for (int i = 0; i < v; i++)
    {
      std::cout << i << " : ";
      // iterate every adjacent vertex
      for (auto j : adj[i])
	{
	  std::cout << j << " ";
	}
      std::cout << std::endl;
    }
};

/** 
 * A function to print the adjacency matrix
 * 
 */
template <class TYPE>
void Graph<TYPE>::AdjMatrix()
{
  std::cout << "\\ ";
  for (int i = 0; i < v; i++)
    {
      std:: cout << i << " ";
    }
  std::cout << std::endl;
  for (int i = 0; i < v; i++)
    {
      std::cout << i << " ";
      for (int j = 0; j < v; j++)
	std::cout << mat[i][j] << " ";
      std::cout << std::endl;
    }       
};

/** 
 * Modified Breadth-First Search Algorithm 
 * 
 * @param source source vertex
 * @param dest destination vertex
 * @param pred array to store predecessors
 * @param dist array to store distance from a vertex
 *             to source
 * 
 * @return True if destination is in the graph and connected. 
 *         False if destianation is not in the graph or unconnected
 *         to the source
 */
template <class TYPE>
bool Graph<TYPE>::BFS(TYPE source, TYPE dest)
{
  std::list<TYPE> queue; // First In First Out (FIFO) queue
  
  // boolean array to store information whether a vertex has been visited
  bool visited[v];

  // initialization
  for (int i = 0; i < v; i++)
    {
      visited[i] = false; //every vertex is not visited yet
      dist[i] = MAX; // distance from source to every vertex is infinity

      // pred[i] represents the immediate predecessor in the BFS
      // starting from the source
      pred[i] = MIN;
    }

  visited[source] = true; //source is first visited
  dist[source] = 0; // distance from source to itself is 0
  queue.push_back(source); // enqueue source

  // Start BFS
  while(!queue.empty())
    {
      TYPE u = queue.front();
      queue.pop_front(); // dequeue
      for (int i = 0; i < adj[u].size(); i++) // for every adjacent vertex
	{
	  if (visited[adj[u][i]] == false) // vertex is never visited
	    {
	      visited[adj[u][i]] = true; // vertex is visited
	      dist[adj[u][i]] = dist[u] + 1; // distance from source increases by 1
	      pred[adj[u][i]] = u;  // record the predecessor for shortest path
	      queue.push_back(adj[u][i]); // enqueue adjacent vertex

	      // Stop BFS if destination is reached
	      if (adj[u][i] == dest)
		return true;
	    }
	}
    }
  return false;
};

/** 
 * A function to find a shortest path 
 * using Modified Breadth-First Search
 * 
 * @param source source vertex
 * @param dest destination vertex
 */
template <class TYPE>
void Graph<TYPE>::ShortestPath(TYPE source, TYPE dest)
{
  // TYPE pred[v]; // stores predecessor of i
  //int dist[v]; // stores distance of i to source

  // destination is not in the graph or not connected
  if (BFS(source, dest) == false)
  {
    std::cout << "Source and destination is not connected" << std::endl;
    return;
  }

  std::vector<TYPE> path; // stores the shortest path
  TYPE crawl = dest;
  path.push_back(crawl); // enqueue destination
  // records the vertices in the shortest path
  while (pred[crawl] != MIN) // traverse the graph back to the source.
                            // predecessor of source is null.
    {
      path.push_back(pred[crawl]); 
      crawl = pred[crawl];
    }

  // distance from source to destination is in dist array
  std::cout << "Shortest Path length : " << dist[dest] << std::endl;
  std::cout << "Path : ";
  for (int i = path.size()-1; i>=0; i--)
    {
      std::cout << path[i] << " ";
    }
  std::cout << std::endl;
};
