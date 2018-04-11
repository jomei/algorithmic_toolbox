#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int step(const vector<int> &a, int x, int left, int right) {
  if(right < left) { return - 1; }
  int i = left + (right - left) / 2;
  if(a[i] == x) { return i;}
  if(a[i] > x) { return step(a, x, left, i - 1);}
  return step(a, x, i + 1, right);
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  return step(a, x, left, right);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
