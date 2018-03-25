// Input: a sequence of non-negative numbers(length of sequence and sequence itself)
// Output: max pairwise product

#include <iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;

int productFast(vector<int>& input) {
	int i1 = 0;
	int i2 = 1;

	for (int i = 1; i < input.size(); i++) {
		if(input[i1] < input[i]) { i1 = i; }
	}

	for (int i = 2; i < input.size(); i++) {
		if((input[i2] < input[i]) && (i != i1)) { i2 = i; }
	}

	return input[i1] * input[i2];
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

	int result = productFast(input);

	cout << result << "\n";

	return 0;
}