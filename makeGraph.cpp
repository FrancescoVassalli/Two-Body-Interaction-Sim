#include <iostream>                  // for std::cout
#include <fstream>
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

int main(int,char*[])
{
	// create a typedef for the Graph type
	typedef adjacency_matrix<vecS, vecS, bidirectionalS> Graph;
	
	// Make convenient labels for the vertices
	const int num_vertices = 32375;
	const char* name = "ABCDE";
	
	// writing out the edges in the graph
	typedef std::pair<int, int> Edge;
	
	// declare a graph object
	Graph myg(num_vertices);
	// add the edges to the graph object
	std::ifstream infile("socfb-MSU24.mtx");
	getline(infile);getline(infile);//skip first two lines
	int v1,v2;
	while(infile>>v1>>v2){
		add_edge(v2,v1,myg);
	}
	return 0;
}
