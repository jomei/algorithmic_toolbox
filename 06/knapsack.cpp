#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> get_storage(int W, int n) {
  vector<vector<int>>s;
  for(int i = 0; i <= n; ++ i) {
    s.push_back({0});
  }
  for(int i = 1; i <= W; ++i) {
    s[0].push_back(0);
  }

  return s;
}

int optimal_weight(int W, const vector<int> &items) {
  vector<vector<int>> storage = get_storage(W, items.size());
  int current, val;
  for(int i = 1; i <= items.size(); ++i) {
    for(int w = 1; w <= W; ++w) {
        current = items[i-1];
        storage[i].push_back(storage[i-1][w]);
        if(current <= w) {
            val = storage[i-1][w-current] + current;
            if(storage[i][w] < val) { storage[i][w] = val; } 
        }
    }
  }

  return storage[items.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
