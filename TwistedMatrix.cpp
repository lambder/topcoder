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
using namespace std;

class TwistedMatrix {
public:
  vector <string> A, B;

  vector <string> rotate(int row, int col, int next) {
    // next is 3 if clockwise direction, 1 if counterclockwise direction
    //
    // rotate clockwise direction
    // next[row][col] = prev[row+1][col];
    // next[row][col+1] = prev[row][col];
    // next[row+1][col+1] = prev[row][col+1];
    // next[row+1][col] = prev[row+1][col+1];
    //
    // rotate counterclockwise direction
    // next[row][col] = prev[row][col+1];
    // next[row][col+1] = prev[row+1][col+1];
    // next[row+1][col+1] = prev[row+1][col];
    // next[row+1][col] = prev[row][col];

    vector <string> ret = A;
    int dir_row[4] = {0, 0, 1, 1};
    int dir_col[4] = {0, 1, 1, 0};

    for (int i=0; i<4; i++)
      ret[row+dir_row[i]][col+dir_col[i]] = A[row+dir_row[(i+next)%4]][col+dir_col[(i+next)%4]];

    return ret;
  }

  bool check(vector <string> &rotated) {
    for (int i=0; i<rotated.size(); i++)
      for (int j=0; j<rotated[0].size(); j++) {
        if (rotated[i][j] == '?')
          if (B[i][j] == '?')
            rotated[i][j] = '0';
          else
            rotated[i][j] = B[i][j];
        else if (B[i][j] == '?')
          continue;
        else if (rotated[i][j] != B[i][j])
          return false;
      }

    return true;
  }

  vector <string> solve(vector <string> _A, vector <string> _B) {
    A = _A, B = _B;
    vector <string> initial(A.size(), (string (A[0].size(), '2')));
    vector <string> ret = initial;
    vector <string> rotated;

    for (int row=0; row<A.size()-1; row++)
      for (int col=0; col<A[0].size()-1; col++) {
        rotated = rotate(row, col, 3);  // clockwise
        if (check(rotated) && rotated < ret) ret = rotated;
        rotated = rotate(row, col, 1);  // counterclockwise
        if (check(rotated) && rotated < ret) ret = rotated;
      }

    if (ret == initial) ret.clear();

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1000",
                                        "0000",
                                        "0000",
                                        "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000",
                                                                                                                                       "?000",
                                                                                                                                       "0000",
                                                                                                                                       "0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000", "1000", "0000", "0000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1?",
                                        "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11",
                                                                                                                                     "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"11", "11" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"000",
                                        "0?0",
                                        "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"111",
                                                                                                                                      "1?1",
                                                                                                                                      "111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"?1111",
                                        "11111",
                                        "11011",
                                        "10111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?1111",
                                                                                                                                        "11111",
                                                                                                                                        "1??11",
                                                                                                                                        "1??11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01111", "11111", "10011", "11111" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????",
                                        "??????????????????????????????"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????",
                                                                                          "??????????????????????????????"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"000000000000000000000000000000", 
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000",
                                                                                          "000000000000000000000000000000"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, solve(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
TwistedMatrix ___test;
___test.run_test(-1);
}
// END CUT HERE 