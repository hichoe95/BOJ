#include <iostream>
#include <algorithm>
using namespace std;

int sum(int a){
  int s=a;

  while(a){
    s+=a%10;
    a/=10;
  }
  return s;
}

int main(){
  ios_base::sync_with_stdio(false);
  bool arr[10001]={0};

  for(int j=1 ;j<=10000 ; j++)
    if(sum(j)<=10000)
      arr[sum(j)] = true;

  for(int i=1 ; i<= 10000 ; i++)
    if(!arr[i])
      cout << i << '\n';

  return 0;
}
