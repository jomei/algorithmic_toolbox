#include <iostream>
#include <string>
#include <vector>

using std::string;


int edit_distance(const string &str1, const string &str2) {
  std::vector<char> s1(str1.begin(), str1.end());
  std::vector<char> s2(str2.begin(), str2.end());
  std::vector<std::vector<int>> matrix;

  int insertion, deletion, match, mismatch;
  for(int i = 0; i <= s1.size(); ++i) {
  	matrix.push_back({});
  	for(int j = 0; j <= s2.size(); ++j) {
  		if(i == 0) {
  			matrix[0].push_back(j);
  			continue;
  		}
  		if(j == 0) {
  			matrix[i].push_back(i);
  			continue;
  		}

  		insertion = matrix[i][j - 1] + 1;
  		deletion = matrix[i - 1][j] + 1;
  		match = matrix[i - 1][j - 1];
  		mismatch = matrix[i - 1][j - 1] + 1;
  		if(s1[i] == s2[j]) {
  			matrix[i].push_back(std::min(std::min(insertion, deletion), match));
  		} else {
  			matrix[i].push_back(std::min(std::min(insertion, deletion), mismatch));
  		}

  	}
  }
  return matrix[s1.size()][s2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
