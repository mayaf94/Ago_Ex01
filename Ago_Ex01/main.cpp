#include <iostream>
#include <ostream>
#include <stdlib.h>
#include "InputTest.h"
#include "Graph.h"
#include "FordFulkersonAlgorithm.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int n;
	int m;
	int s;
	int t;
	int i;
	int j;
	int c;
	vector<Edge> edges;
	int max_flow;
	FordFulkersonAlgorithm algo;
	

	n = InputTest::getNumberOfPointsOrArchery();
	m = InputTest::getNumberOfPointsOrArchery();
	s = InputTest::getNumberOfPointsOrArchery();
	t = InputTest::getNumberOfPointsOrArchery();
	string* strings;

	for (int w = 0; w < m; w++)
	{
		strings = InputTest::GettingParams(3, false);
		i = atoi(strings[0].c_str());
		j = atoi(strings[1].c_str());
		c = atoi(strings[2].c_str());
		InputTest::CheckIfNumberInBorder(i, n, true);
		InputTest::CheckIfNumberInBorder(j, n, true);
		InputTest::CheckIfNumberInBorder(c, n, false);
		edges.push_back(Graph::makeEdge(i - 1, j - 1, c));
	}
	
	Graph graph(edges, n);

	max_flow = algo.fordFulkerson(graph, s - 1, t - 1, true);
	cout << "BFS Method:" << endl;
	cout << "Max flow =  " << max_flow << endl;
	cout << "Min cut: S = ";
	graph.PrintGroup(true);
	cout << " T = ";
	graph.PrintGroup(false);
	cout << endl;
	max_flow = algo.fordFulkerson(graph, s - 1, t - 1, false);
	cout << "Greedy Method:" << endl;
	cout << "Max flow =  " << max_flow << endl;
	cout << "Min cut: S = ";
	graph.PrintGroup(true);
	cout << " T = ";
	graph.PrintGroup(false);
}