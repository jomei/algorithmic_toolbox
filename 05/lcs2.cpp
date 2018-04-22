#include <iostream>
#include <vector>

using std::vector;

int step(vector<int> &s1, vector<int> &s2, int i, int j) {
  if(i == 0 || j == 0) { return 0; }
  if(s1[i] == s2[j]) { return step(s1, s2, i -1, j -1) + 1;}
  return std::max(step(s1, s2, i -1, j), step(s1, s2, i, j- 1));
}

int lcs2(vector<int> &s1, vector<int> &s2) {
  return step(s1, s2, s1.size(), s2.size());
}


// todo: probably bug for empty lcs
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
