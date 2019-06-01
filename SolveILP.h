#pragma once
#include "SolveILP.h"
#include "gurobi_c++.h"
class SolveILP
{
public:
	SolveILP(int ** blocksInFile, int fileSize, int blockSize, int *sizes, int deleted);
	~SolveILP();
	double * solveProblem();
	SolveILP();
	int ** blocksInFile;
	int fileSize, blockSize, maxDeletedFIles;
	int *sizes;
	GRBVar *files;
	GRBVar *blocks;
	GRBLinExpr Obj = 0;
	GRBLinExpr LHS = 0;
};



