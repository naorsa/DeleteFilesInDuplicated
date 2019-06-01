#include "gurobi_c++.h"
#include "SolveILP.h"
#include "ReadFromCSV.h"
using std::cout;
using std::endl;

int main(){
	ReadFromCSV *r = new ReadFromCSV();
	r->read_record();
	return 0;
}
