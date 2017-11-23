#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  string a;
  vector<string> vec;

  map<string,int> name;

  for(int i=0 ;i<n;i++){
    cin >> a;
    name[a]++;
  }
  for(int i=0 ;i<m;i++){
    cin >> a;
    name[a]++;
  }

  for(auto &p : name){
    if(p.second==2)
      vec.push_back(p.first);
  }

  sort(vec.begin(),vec.end());

  cout << vec.size() << '\n';

  for(int i=0 ; i<vec.size() ; i++)
    cout << vec[i] << '\n';

  return 0;
}
