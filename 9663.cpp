#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int c[21];
int cnt,n;

void BT(int r){
	int i,j;
    for(i=1 ;i<=n;i++){
		for(j=1 ; j<=r ; j++)
			if(c[j]==i || abs(c[j]-i)==abs(j-r)) break;
		
		if(j==r+1){
			if(r == n){
				for(int k=1 ; k<n;k++)
					cout << c[k] << " ";
				cout << i;
				puts("");
				exit(0);
				//cnt++;
				return;
			}
			c[r] = i;
			BT(r+1);
			c[r] = 0;
		}
    }
}

int main(){
    cin >> n;
	if(n==1){cout << 1 << '\n';return 0;}
	for(int i=1 ;i<=n;i++){
		c[1] = i;
		BT(2);
	}
	cout << cnt << endl;
	
    return 0;
}
