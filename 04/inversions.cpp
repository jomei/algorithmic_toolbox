#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int> &result, vector<int> &left, vector<int> &right) {
  int l, r;
  while(!left.empty() || !right.empty()) {
    l = left[0];
    r = right[0];
    std::cout<< "l: " << l << " r:" << r <<std::endl;
    if(l <= r) {
      result.push_back(l);
      left.erase(left.begin());
    } else {
      result.push_back(r);
      right.erase(right.begin());
    }
  }

  for(int i = 0; i < left.size(); ++i) {
    result.push_back(left[i]);
  }


  for(int i = 0; i < right.size(); ++i) {
    result.push_back(right[i]);
  }
  std::cout << "---\n"; 
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if(left == right) {
     b.push_back(a[right]);
     return number_of_inversions;
  }
  
  size_t ave = left + (right - left) / 2;
  
  vector<int> l_vec;
  vector<int> r_vec;
  
  number_of_inversions += get_number_of_inversions(a, l_vec, left, ave);
  number_of_inversions += get_number_of_inversions(a, r_vec, ave + 1, right);
  merge(b, l_vec, r_vec);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b;
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

    std::cout<<"\nresult vector:\n";
  for(int i = 0; i < b.size(); ++i){
    std::cout<<b[i]<<" ";
  }
}
