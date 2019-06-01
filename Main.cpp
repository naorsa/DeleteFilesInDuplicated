#include "gurobi_c++.h"
#include "SolveILP.h"
using namespace std;

int main(int argc, char *argv[])
{
	//try {
	//	int b[5][4] = { 
	//	{ 1,1,0,0 },
	//	{ 1,0,1,0 },
	//	{ 0,1,0,1 },
	//	{ 0,1,0,1 },
	//	{ 1,0,1,1 } };
	//	int size[5] = { 500,300,200,100,300 };
	//	//create from csv file size of f br and the matrix b
	//	// Create an environment
	//	GRBEnv env = GRBEnv(true);
	//	env.set("LogFile", "mip1.log");
	//	env.start();

	//	// Create an empty` model
	//	GRBModel model = GRBModel(env);
	//	GRBVar f[4];
	//	for (int i = 0; i<4; i++) {
	//		f[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY);
	//	}
	//	GRBVar br[5];
	//	for (int i = 0; i<5; i++) {
	//		br[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY);
	//	}
	//	model.set(GRB_IntAttr_ModelSense, -1);
	//	GRBLinExpr Obj = 0;
	//	for (int j = 0; j < 5; j++) {
	//		Obj += size[j] * br[j];
	//	}
	//	
	//	model.setObjective(Obj);
	//	// Add constraint: x + 2 y + 3 z <= 4
	//	GRBLinExpr LHS = 0;
	//	for (int i = 0; i<4; i++) {
	//		LHS += f[i];
	//	}
	//	model.addConstr(LHS, GRB_LESS_EQUAL, 2);
	//	
	//	for (int i = 0; i<4; i++) {
	//		for (int j = 0; j < 5; j++) {
	//			if (b[j][i]==1) {
	//				model.addConstr(br[j], GRB_LESS_EQUAL, f[i]);
	//			}
	//		}
	//	}
	//	// Optimize model
	//	model.write("debug.lp");
	//	model.optimize();

	//	for (int i = 0; i<4; i++) {
	//		cout << "x " << i << " =" << f[i].get(GRB_DoubleAttr_X) << endl;
	//	}

	//	cout << "Obj: " << model.get(GRB_DoubleAttr_ObjVal) << endl;
	//}
	//catch (GRBException e) {
	//	cout << "Error code = " << e.getErrorCode() << endl;
	//	cout << e.getMessage() << endl;
	//}
	//catch (...) {
	//	cout << "Exception during optimization" << endl;
	//}

	//return 0;

	int ** bl = (int **)malloc(5 * sizeof(int*));
	int * size = (int *)malloc(4 * sizeof(int));

	for (int i = 0; i < 5; i++)
		bl[i] = (int *)malloc(4 * sizeof(int));
	bl[0][0] = 1;
	bl[0][1] = 1;
	bl[0][2] = 0;
	bl[0][3] = 0;
	bl[1][0] = 1;
	bl[1][1] = 0;
	bl[1][2] = 1;
	bl[1][3] = 0;
	bl[2][0] = 0;
	bl[2][1] = 1;
	bl[2][2] = 0;
	bl[2][3] = 1;
	bl[3][0] = 0;
	bl[3][1] = 1;
	bl[3][2] = 0;
	bl[3][3] = 1;
	bl[4][0] = 1;
	bl[4][1] = 0;
	bl[4][2] = 1;
	bl[4][3] = 1;
	size[0] = 500;
	size[1] = 300;
	size[2] = 200;
	size[3] = 100;
	size[4] = 300;
	SolveILP *solver = new SolveILP(bl, 4, 5, size, 2);
	double* s = solver->solveProblem();
	for (int i = 0; i < 4; i++)
		cout << s[i];
	

	return 0; 
}