#include <iostream>
#include <cstring>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  string a;
  getline(cin,a);
  int len = a.size();
  int cnt=0;
  for(int i=0 ;i<len;i++)
    if(a[i] != ' '){
      cnt++;
    int k=i;
      for(int j=1 ;k+j<len;j++){
        if(a[k+j] == ' ')
          break;
        i++;
      }
    }
  cout << cnt << endl;
  return 0;
}
