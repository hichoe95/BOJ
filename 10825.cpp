#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct student{
  int kor,math,eng;
  string name;
  bool operator<(const student &s)const{
    if(kor > s.kor)
      return true;
    else if(kor == s.kor){
      if(eng<s.eng)
        return true;
      else if(eng == s.eng){
        if(math > s.math)
          return true;
        else if(math == s.math)
          return name < s.name;
      }
    }
    return false;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<student> stu(n);

  for(int i=0 ;i<n;i++)
    cin >> stu[i].name >> stu[i].kor >> stu[i].eng >> stu[i].math;

  sort(stu.begin(), stu.end());

  for(auto &s : stu)
    cout << s.name << '\n';
  return 0;
}
