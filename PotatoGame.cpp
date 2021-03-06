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
class PotatoGame {
public:
  vector <int> fourSquares;
  map <pair<int, bool>, bool> memo;

  bool search(int n, bool turn) {
    if (memo.find(make_pair(n, turn)) != memo.end())
      return memo[make_pair(n, turn)];

    bool ret = !turn;
    int i, N = fourSquares.size();

    if (n == 0)
      return !turn;
    
    for (i=0; i<N; i++)
      if (fourSquares[i] <= n) {
        ret = search(n - fourSquares[i], !turn);
        if (ret == turn)
          break;
      }

    return memo[make_pair(n, turn)] = ret;
  }

  string theWinner(int n) {
    string ret = "Taro";
//     int i;
    
//     for (i=13; i>=0; i--)
//       fourSquares.push_back((int)pow(4.0, i));

//     bool res = search(n, true);
//     if (!res)
//       ret = "Hanako";

    ret = (n%5 == 0 || n%5 == 2) ? "Hanako" : "Taro";

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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arg0 = 1; 
    string Arg1 = "Taro"; 
    verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { 
    int Arg0 = 2; 
    string Arg1 = "Hanako"; 
    verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { 
    int Arg0 = 3; 
    string Arg1 = "Taro"; 
    verify_case(2, Arg1, theWinner(Arg0)); }
	void test_case_3() { 
    int Arg0 = 5; 
    string Arg1 = "Hanako"; 
    verify_case(3, Arg1, theWinner(Arg0)); }
	void test_case_4() { 
    int Arg0 = 100000000; 
    string Arg1 = "Taro"; 
    verify_case(4, Arg1, theWinner(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
PotatoGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
