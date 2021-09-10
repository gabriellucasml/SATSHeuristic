#include <sstream>
#include "TSPData.h"
#include "SATSHeuristic.h"

using namespace std;

int main() {

    TSPData tspdata1(R"(D:\Files\UFRN\EPOIP\TSP\dataset\a280.tsp)");
    TSPData tspdata2(R"(D:\Files\UFRN\EPOIP\TSP\dataset\berlin52.tsp)");
    TSPData tspdata3(R"(D:\Files\UFRN\EPOIP\TSP\dataset\bier127.tsp)");
    TSPData tspdata4(R"(D:\Files\UFRN\EPOIP\TSP\dataset\brd14051.tsp)");
    TSPData tspdata5(R"(D:\Files\UFRN\EPOIP\TSP\dataset\ch130.tsp)");
    TSPData tspdata6(R"(D:\Files\UFRN\EPOIP\TSP\dataset\ch150.tsp)");
    TSPData tspdata7(R"(D:\Files\UFRN\EPOIP\TSP\dataset\d198.tsp)");
    TSPData tspdata8(R"(D:\Files\UFRN\EPOIP\TSP\dataset\d493.tsp)");
    TSPData tspdata9(R"(D:\Files\UFRN\EPOIP\TSP\dataset\d657.tsp)");
    TSPData tspdata10(R"(D:\Files\UFRN\EPOIP\TSP\dataset\a5.tsp)");

    SATSHeuristic sats1(tspdata1);
    //SATSHeuristic sats2(tspdata2);
    //SATSHeuristic sats3(tspdata3);
    //SATSHeuristic sats4(tspdata4);
    //SATSHeuristic sats5(tspdata5);
    //SATSHeuristic sats6(tspdata6);
    //SATSHeuristic sats7(tspdata7);
    //SATSHeuristic sats8(tspdata8);
    //SATSHeuristic sats9(tspdata9);
    //SATSHeuristic sats10(tspdata10);


    cout << sats1.solve(sats1.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats2.solve(sats2.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats3.solve(sats3.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats4.solve(sats4.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats5.solve(sats5.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats6.solve(sats6.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats7.solve(sats7.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats8.solve(sats8.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats9.solve(sats9.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;
    //cout << sats10.solve(sats10.nnHeuristic(),50,0.99,0.15,1000,100,100) << endl;

    /*cout << endl << sats1.eval(sats1.getTour()) << endl;
    cout << sats2.eval(sats2.getTour()) << endl;
    cout << sats3.eval(sats3.getTour()) << endl;
    cout << sats4.eval(sats4.getTour()) << endl;
    cout << sats5.eval(sats5.getTour()) << endl;
    cout << sats6.eval(sats6.getTour()) << endl;
    cout << sats7.eval(sats7.getTour()) << endl;
    cout << sats8.eval(sats8.getTour()) << endl;
    cout << sats9.eval(sats9.getTour()) << endl;
    cout << sats10.eval(sats10.getTour()) << endl;*/



    return 0;
}
