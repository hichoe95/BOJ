#include <iostream>
using namespace std;

bool s[1000001];

int main(){
  ios_base::sync_with_stdio(false);

  int n,m;
  cin >> m >> n;

  s[1] = true;
  for(int i=2;i<=n;i++)
    if(!s[i])
      for(int j=i+i;j<=n;j+=i)
        s[j]=true;

  for(int i=m;i<=n;i++)
    if(!s[i])
      cout << i <<'\n';


  return 0;
}
