//The goal in this problem is to  nd the minimum number of coins needed to 
//change the input value (an integer) into coins with denominations 1, 5, and 10.

#include <iostream>

int get_fraction(int m) {
	int fractions[3] = {10, 5, 1};
	for(int i = 0; i < 3; ++i) {
		if(fractions[i] < m) { return fractions[i]; }
	}
	return 0;
}


int get_change(int m) {
  int n = 0;
  while(m != 0) {
  	m -= get_fraction(m);
  	++n;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
