#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int ii=0 ;ii<T;ii++){
    int n;
    int arr[200002]={0};
    int dp[200002]={0};
    cin >> n;
    n*=2;
    for(int i=1 ;i<=n ;i++)
      cin >> arr[i];

    dp[1] = arr[1],dp[1+n/2] = arr[1+n/2];
    dp[2] = arr[1+n/2] + arr[2];
    dp[2+n/2] = arr[1] + arr[2+n/2];

    for(int i=3;i<=n/2;i++){
      dp[i] = max(dp[i+n/2-2],dp[i+n/2-1]) + arr[i];
      dp[i+n/2] = max(dp[i-2],dp[i-1]) + arr[i+n/2];
    }
    cout << max(dp[n/2],dp[n]) << '\n';
  }
  return 0;
}
