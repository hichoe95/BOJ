#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
  int x,y;
  bool operator <(const point &v)const{
    if(y == v.y)
      return x < v.x;
    return y < v.y;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<point> coordi;
  for(int i=0 ;i<n;i++){
    int x,y;
    cin >> x >> y;
    struct point k;
    k.x = x;
    k.y = y;
    coordi.push_back(k);
  }
  sort(coordi.begin(),coordi.end());

  for(struct point k : coordi){
    cout << k.x << " " << k.y << '\n';
  }
  return 0;
}
