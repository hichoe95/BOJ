#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int d[1001];

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  for(int i=0 ;i<n;i++)
    cin >> A[i];

  d[0] =  1;
  int M=1;
  for(int i=1 ; i<n;i++){
    for(int j=0 ; j<i;j++)
      if(A[j]<A[i])
        d[i] = max(d[i],d[j]+1);
    if(!d[i]) d[i] = 1;
    M = max(M,d[i]);
  }

  cout << M << endl;
  return 0;
}
