#pragma once
#include "Vertex.h"
struct VertexComparer {
	bool operator() (Vertex* a, Vertex* b) {
		//comparison code here
		//return true als a lagere effort heeft dan b
		return a->minEffort > b->minEffort;
	}
};
