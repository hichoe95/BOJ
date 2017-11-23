#include <iostream>
using namespace std;

int a[100][100],b[100][100],c[100][100];

int main(){

  int n,m;
  cin >> n >> m;

  for(int i=0 ;i<n ; i++)
    for(int j=0 ;j<m ;j++)
      cin >> a[i][j];
  int k;
  cin >> m >> k;
  for(int i=0 ;i<m ;i++)
    for(int j=0 ;j<k ; j++)
      cin >> b[i][j];

  for (int i=0; i<n; i++) {
    for (int j=0; j<k; j++) {
        for (int l=0; l<m; l++) {
            c[i][j] += a[i][l]*b[l][j];
        }
    }
  }
  for(int i=0 ;i<n; i++){
    for(int j=0 ;j<k ;j++)
      cout << c[i][j] << " ";
    cout << '\n';
  }
  return 0;
}
