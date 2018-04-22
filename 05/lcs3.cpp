#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  vector<vector<vector<int>>> L;
 
    for (int i=0; i<=a.size(); ++i)
    {   
        L.push_back({});
        for (int j=0; j<=b.size(); ++j)
        {
            L[i].push_back({});
            for (int k=0; k<=c.size(); k++)
            {
                if (i == 0 || j == 0 || k==0)
                    L[i][j].push_back(0);
 
                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1])
                    L[i][j].push_back(L[i-1][j-1][k-1] + 1);
 
                else
                    L[i][j].push_back(std::max(std::max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]));
            }
        }
    }
 
    return L[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
