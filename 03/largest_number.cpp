#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<char> str_to_vector(string s) {
  return vector<char>(s.begin(), s.end());
}

int get_next(vector<char> v, int pos) {
  if(pos > v.size()) {
    return (int)v.back();
  } else {
    return (int)v[pos];
  }
}

bool comp(string a, string b) {
  vector<char> v1 = str_to_vector(a);
  vector<char> v2 = str_to_vector(b);
  int len = std::max(v1.size(), v2.size());

  int a_int, b_int;
  for (int i = 0; i < len; ++i) {
    a_int = get_next(v1, i);
    b_int = get_next(v2, i);
    if(a_int == b_int) { continue; }
    return a_int > b_int;
  }
  return true;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  std::sort(a.begin(), a.end(), comp);
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
