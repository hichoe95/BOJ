#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct student{
  int kor,math,eng;
  string name;
};

  bool cmp(const student &v,const student &s){
    return make_tuple(-v.kor,v.eng,-v.math,v.name) < make_tuple(-s.kor,s.eng,-s.math,s.name);
  }

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  
  vector<student> stu(n);

  for(int i=0 ;i<n;i++)
    cin >> stu[i].name >> stu[i].kor >> stu[i].eng >> stu[i].math;

  sort(stu.begin(), stu.end(),cmp);

  for(auto &s : stu)
    cout << s.name << '\n';
  return 0;
}
