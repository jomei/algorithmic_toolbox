#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_max(vector<int> &a) {
  if(a.size() == 1) {return 1;}
  int max_count = 1;
  int current_count = 1;
  int prev = a[0];
  for(int i = 1; i < a.size(); ++i ) {
    if(a[i] == prev) {
      ++current_count;
    }else {
      if(current_count > max_count) {max_count = current_count;}
      prev = a[i];
      current_count = 0;
    }
  }
 
  return max_count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  std::sort(a.begin(), a.end());
  if(get_max(a) > (a.size() / 2)) { return 1; }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
