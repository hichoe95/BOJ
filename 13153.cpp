#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double dist(pair<int,int> a, pair<int,int> b){
  return (double)sqrt((double)((a.first - b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second)));
}

int main(){

  double r;
  vector<pair<int,int> > v;

  for(int i=0 ;i<3 ;i++){
    int x,y;
    cin >> x >> y;
    v.push_back(pair<int,int>(x,y));
  }
  cin >> r;

  double a,b,c;

  a = dist(v[0],v[1]);
  b = dist(v[0],v[2]);
  c = dist(v[1],v[2]);

  double tri = sqrt((double)(4*a*a*b*b - (a*a+b*b-c*c)*(a*a+b*b-c*c)))/4.0;

  double timr = (tri*2.0)/(a+b+c);
  cout.precision(6);

  if(r==timr) cout << 0.0 << endl;
  else cout << ((timr-r)/r*100.0) << '\n';

  return 0;
}
