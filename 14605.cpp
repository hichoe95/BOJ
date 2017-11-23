#include <iostream>
#include <vector>
using namespace std;

int n;

int rec(int ord,int count){
  int sum = 0;
  if(ord >= n){
    if(count%3 == 0) return 1;
    else return 0;
  }

  for(int i=0 ;i<3 ; i++)
    sum+=rec(ord+1,count + i);

  return sum;
}

int main(){

  cin >> n;

  cout << rec(1,1) + rec(1,2) << '\n';

  return 0;
}
