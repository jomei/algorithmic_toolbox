// Input: a sequence of non-negative numbers(length of sequence and sequence itself)
// Output: max pairwise product

#include <iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;

long long productFast(vector<int>& input) {
  int n = input.size();

  int i1 = -1;
  for (int i = 0; i < n; ++i)
    if ((i1 == -1) || (input[i] > input[i1]))
      i1 = i;

  int i2 = -1;
  for (int j = 0; j < n; ++j)
    if ((j != i1) && ((i2 == -1) || (input[j] > input[i2])))
      i2 = j;

  return ((long long)(input[i1])) * input[i2];
}

int productNaive(vector<int>& input) {
	int result = 0;
	int tmp;
	for (int i = 0; i < input.size() - 1; i++) {
		for(int j = i + 1; j < input.size(); j++) {
			tmp = input[i] * input[j];
			if(tmp > result) { result = tmp; }
		}
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> input(n);

	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}

	long long result = productFast(input);

	cout << result << "\n";

	return 0;
}