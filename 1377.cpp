#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int,int>> arr(N);

  for(int i=0 ;i<N;i++){
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr.begin(),arr.end());
  int M=0;
  for(int i=0 ;i<N;i++){
    int temp = arr[i].second - i;
    M = max(M,temp);
  }

  cout << M+1 << endl;

  return 0;
}
