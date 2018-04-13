#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  std::cout<<"("<<left<<","<<right << ")\n";
  long long number_of_inversions = 0;
  if (right - left == 0) {
    b.push_back(a[left]);
    return number_of_inversions;
  }
  
  if (right <= left + 1) {
    if(a[left] > a[right]) {
    std::cout<< "left " << left << ": " << a[left] <<"\n";
    std::cout<< "right " << right << ": " << a[right] <<"\n";
      ++number_of_inversions;
      b.push_back(a[right]);
      b.push_back(a[left]);
    } else {
      b.push_back(a[left]);
      b.push_back(a[right]);
    }
    std::cout<<"======\n";
    return number_of_inversions;
  }
  
  size_t ave = left + (right - left) / 2;
  
  vector<int> l_vec;
  vector<int> r_vec;
  
  number_of_inversions += get_number_of_inversions(a, l_vec, left, ave);
  number_of_inversions += get_number_of_inversions(a, r_vec, ave + 1, right);
  std::cout<< "left vector:" <<"\n";
  for(int i = 0; i < l_vec.size(); ++i){
    std::cout<<l_vec[i]<<" ";
  }
  std::cout<<"\nright vector:\n";
    for(int i = 0; i < l_vec.size(); ++i){
    std::cout<<r_vec[i]<<" ";
  }
  std::cout<<"\n"
  while(!l_vec.empty() && !r_vec.empty()) {
      if(l_vec.back() > r_vec.back()) {
        std::cout<<"!!\n";
        std::cout<< "left " << left << ": " << a[left] <<"\n";
        std::cout<< "right " << right << ": " << a[right] <<"\n";
        b.push_back(l_vec.back());
        l_vec.pop_back();
        ++number_of_inversions;
      } else {
        b.push_back(r_vec.back());
        r_vec.pop_back();
      }
  }

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
