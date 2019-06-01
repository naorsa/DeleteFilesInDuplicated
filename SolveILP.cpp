#include "SolveILP.h"
#include "gurobi_c++.h"
#include <iostream>

using std::cout;
using std::endl;

SolveILP:: SolveILP(int ** blocksInFile, int fileSize, int blockSize, int *sizes, int deleted) {
	this->blocksInFile = blocksInFile;
	this->fileSize = fileSize;
	this->blockSize = blockSize;
	this->sizes = sizes;
	maxDeletedFIles = deleted;
	files = (GRBVar *)malloc(fileSize * sizeof(GRBVar));
	blocks = (GRBVar *)malloc(blockSize * sizeof(GRBVar));
}

double * SolveILP::solveProblem() {
	GRBEnv env = GRBEnv(true);
	env.set("LogFile", "mip1.log");
	env.start();
	GRBModel model = GRBModel(env);

		double * solutions = (double *)malloc(fileSize * sizeof(double));

		for (int i = 0; i < fileSize; i++) {
			files[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY);
		}
		for (int i = 0; i < blockSize; i++) {
			blocks[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY);
		}
		model.set(GRB_IntAttr_ModelSense, -1);
		for (int i = 0; i < 5; i++) {
			Obj += sizes[i] * blocks[i];
		}
		model.setObjective(Obj);
		for (int i = 0; i<4; i++) {
			LHS += files[i];
		}
		model.addConstr(LHS, GRB_LESS_EQUAL, 2);
		for (int i = 0; i< fileSize; i++) {
			for (int j = 0; j < blockSize; j++) {
				if (blocksInFile[i][j] == 1) {
					model.addConstr(blocks[j], GRB_LESS_EQUAL, files[i]);
				}
			}
		}
		model.write("debug.lp");
		model.optimize();
		for (int i = 0; i < fileSize; i++) {
			solutions[i] = files[i].get(GRB_DoubleAttr_X);
		}
		cout << "Obj: " << model.get(GRB_DoubleAttr_ObjVal) << endl;
		
		return solutions;
}

