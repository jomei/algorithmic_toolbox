#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  int sum = 0;
  for(int i = 0; i < A.size(); ++i) { sum += A[i];}
  if(sum % 3 != 0) {return 0;}
  sum = sum / 3;
  bool table[A.size() +1][sum + 1][sum + 1];

  for (int i =0; i <=A.size(); ++i) {
  	for(int j = 0;j <=sum; ++j) {
  		for(int k = 0; k <=sum; ++k) {
  			table[i][j][k]= false;
  		}
  	}
  }
  for (int i = 0; i <= A.size(); ++i) {
    table[i][0][0] = true;
  }

  for (int i = 1; i <= sum; ++i) {
      table[0][i][0] = false;
      table[0][0][i] = false;
  }

  table[0][0][0] = true;

  for (int k = 1; k <= A.size(); ++k) {
      for (int i = 0; i <= sum; ++i) {
          for (int j = 0; j <= sum; ++j) {
              table[k][i][j] = table[k - 1][i][j] ||
                      (i >= A[k - 1] && table[k - 1][i - A[k - 1]][j]) ||
                      (j >= A[k - 1] && table[k - 1][i][j - A[k - 1]]);
          }
      }
  }
  if(table[A.size()][sum][sum]) {
  	return 1;
  } else{
  	return 0;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  int a =  partition3(A);
  std::cout << a << '\n';
}
