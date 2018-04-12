#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int, int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int start = -1;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      if(a[i] == x && start == -1) {
        start = i;
      }
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  if(start == -1) {
    start = j;
  }
  return {start, j};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  std::pair<int, int> p = partition3(a, l, r);

  randomized_quick_sort(a, l, p.first - 1);
  randomized_quick_sort(a, p.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
