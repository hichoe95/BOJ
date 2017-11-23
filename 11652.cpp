#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[1000001];
int cnt[1000001];
int main(){
  ios_base::sync_with_stdio(false);
  int n,temp=0,max=-1;
  cin >> n;

  for(int i=0 ; i<n ; i++)
    cin >> arr[i];

  sort(arr,arr+n);

  for(int i=1 ;i<n;i++)
    if(arr[i] == arr[i-1]){
      cnt[i] = cnt[i-1]+1;
    }

  for(int i=0 ;i<n;i++){
    if(max<cnt[i]){
      max = cnt[i];
      temp = arr[i];
    }
  }
  // for(int i=0;i<n;i++)
  //   cout << arr[i];
  // puts("");
  //
  // for(int i=0 ;i<n;i++)
  //   cout << cnt[i];
  // puts("");


  cout << temp << '\n';
  return 0;
}
