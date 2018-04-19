#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence = {1};

  std::map<int, vector<int>> storage;
  storage[1] = {1};
  std::vector<int> results;
  int count = 1;
  int p1, x2, x3;
  while(storage.count(n) == 0) {
      p1 = count + 1;
      x2 = count * 2;
      x3 = count * 3;
      if(storage.count(p1) == 0) {
        std::vector<int> tmp = storage.find(count)->second;
        tmp.push_back(p1);
        storage[p1] = tmp;
      }
      if(storage.count(x2) == 0) {
        std::vector<int> tmp = storage.find(count)->second;
        tmp.push_back(x2);
        storage[x2] = tmp;
      }
      if(storage.count(x3) == 0) {
        std::vector<int> tmp = storage.find(count)->second;
        tmp.push_back(x3);
        storage[x3] = tmp;
      }

  }
  return storage.find(n)->second;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
