#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::pair;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

vector<vector<int>> get_table(int n) {
  vector<vector<int>> table;
  for(int i = 0; i < n; ++i) {
    table.push_back(vector<int>(n));
  }

  return table;
}

long long get_maximum_value(const string &exp) {
  //write your code here
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
