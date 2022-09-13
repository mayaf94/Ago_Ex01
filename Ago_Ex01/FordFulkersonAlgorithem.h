#ifndef FORDFULKERSONALGORITHEM_H
#define FORDFULKERSONALGORITHEM_H
#include <vector>
#include <iostream>
#include "Edge.h"
#include "Graph.h"

using std::pair;
using std::vector;


typedef class FordFulkersonAlgorithem 
{
public:
	static int fordFulkerson(Graph graph, int s, int t);
};

#endif
