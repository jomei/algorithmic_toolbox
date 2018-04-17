#include <iostream>
#include <vector>
#include <limits>

using std::vector;

int dp_change(int money, vector<int> coins, vector<int> storage) {
  int min, amount;
  for(int m = 1; m <= money; ++m) {
  	min = std::numeric_limits<int>::infinity();
  	for(int c = 0; c < coins.size(); ++c) {
  	  if(m >= coins[c]) {
  			amount = storage[m - coins[c]] + 1;
  			if(m < storage.size()) {
  			 	if( amount < storage[m]) {
  					storage[m] = amount;
  			 	}
  			} else {
  				storage.push_back(amount);
  			}
  		}
  	}
  }
  
  return storage[money];
}

int get_change(int m) {
  vector<int> storage = {0};
  return	dp_change(m, {1, 3, 4}, storage);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
