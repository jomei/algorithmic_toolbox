#include <iostream>
#include <vector>

using std::vector;

vector<int> step(vector<int> acc, int last, int remain) {
  last += 1;
  if (last >= remain - last) {
    acc.push_back(remain);
    return acc;
  }

  acc.push_back(last);
  remain -= last;
  return step(acc, last, remain);
}

vector<int> optimal_summands(int n) {
  vector<int> summands;
  return step(summands, 0, n);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
