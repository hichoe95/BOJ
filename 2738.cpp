#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int a[100][100]={0,},x,y;
  cin >> x >> y;
  for(int i=0 ;i<x ;i++)
    for(int j=0 ;j<y ;j++)
      cin >> a[i][j];
  for(int i=0 ;i<x; i++)
    for(int j=0 ; j<y ; j++){
      int k;
      cin >> k;
      a[i][j]+=k;
    }
  for(int i=0 ;i<x ;i++){
    for(int j=0 ;j<y ;j++)
      cout << a[i][j] << " ";
    cout << '\n';
  }
}
