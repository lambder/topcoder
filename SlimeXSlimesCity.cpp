// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE
using namespace std;
class SlimeXSlimesCity {
  public:
  int merge(vector <int> population) {
    int ret = 0;
    int i, j;
    sort(population.begin(), population.end());

    for (i=0; i<population.size(); i++) {
      long long cur = 0;
      bool is_ok = true;
      for (j=0; j<population.size(); j++) {
        cur += population[j];
        if (j < i) continue;
        if (population[j+1] > cur) {
          is_ok = false;
          break;
        }
      }
      if (is_ok) {
        ret = population.size() - i;
        break;
      }
    }

    return ret;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { 
	if ((Case == -1) || (Case == 0)) test_case_0();
	if ((Case == -1) || (Case == 1)) test_case_1();
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 3)) test_case_3();
	if ((Case == -1) || (Case == 4)) test_case_4();
	if ((Case == -1) || (Case == 5)) test_case_5();
	if ((Case == -1) || (Case == 6)) test_case_6();
	if ((Case == -1) || (Case == 7)) test_case_7();
}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
	int Arr0[] = {2, 3, 4}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	verify_case(0, Arg1, merge(Arg0)); }
	void test_case_1() { 
	int Arr0[] = {1, 2, 3}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	verify_case(1, Arg1, merge(Arg0)); }
	void test_case_2() { 
	int Arr0[] = {8,2,3,8}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	verify_case(2, Arg1, merge(Arg0)); }
	void test_case_3() { 
	int Arr0[] = {1000000000, 999999999, 999999998, 999999997}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(3, Arg1, merge(Arg0)); }
	void test_case_4() { 
	int Arr0[] = {1,1,1}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(4, Arg1, merge(Arg0)); }
	void test_case_5() { 
	int Arr0[] = {1, 2, 4, 6, 14, 16, 20}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 3; 
	verify_case(5, Arg1, merge(Arg0)); }
	void test_case_6() { 
    int Arr0[] = {1, 1, 1, 10}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 1; 
	verify_case(6, Arg1, merge(Arg0)); }
	void test_case_7() { 
	int Arr0[] = {2, 3, 4}; 
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arg1 = 2; 
	verify_case(7, Arg1, merge(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SlimeXSlimesCity ___test;
___test.run_test(-1);
}
// END CUT HERE 
