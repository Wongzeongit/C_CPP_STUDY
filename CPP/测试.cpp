#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> vec;
  for(int i = 0; i < 5 ; i ++){
  	vec.push_back(i+1);
  }
  auto it2 = vec.begin()+ 2;
  auto it = vec.begin() + 3;
  vec.insert(it2,5);
  sort(vec.begin(),vec.end());
  cout << *(it2) << " " << *(it) << endl;
}