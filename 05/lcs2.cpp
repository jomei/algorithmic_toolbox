#include <iostream>
#include <vector>

using std::vector;

int step(vector<int> &s1, vector<int> &s2, int i, int j) {
  if(i == 0 || j == 0) { return 0; }
  if(s1[i] == s2[j]) { return step(s1, s2, i -1, j -1) + 1;}
  return std::max(step(s1, s2, i -1, j), step(s1, s2, i, j- 1));
}

int lcs2(vector<int> &s1, vector<int> &s2) {
    vector<vector<int>> L;
 
    for (int i=0; i<=s1.size(); ++i)
    {   
        L.push_back({});
        for (int j=0; j<=s2.size(); ++j)
        {

                if (i == 0 || j == 0)
                    L[i].push_back(0);
 
                else if (s1[i-1] == s2[j-1])
                    L[i].push_back(L[i-1][j-1] + 1);
 
                else
                    L[i].push_back(std::max(L[i-1][j],
                                         L[i][j-1]));
          
        }
    }
 
    return L[s1.size()][s2.size()];
}


// todo: probably bug for empty lcs
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
