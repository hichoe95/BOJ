#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int g[1001][1001];

int main(){

	ios_base::sync_with_stdio(false);

	int n,m;
	int x=0 ,y=0;
	cin >> n >> m;
	for(int i=0 ;i<=n;i++){
		for(int j=0 ; j<=m ; j++)
			g[i][j] = 1e9;
	}
	for(int i=1 ;i<=n;i++)
		for(int j=1  ; j<=m ; j++){
			cin >> g[i][j];
			if(((i-1)+j-1)%2 == 1)
				if(g[i][j]<g[x][y])
					x = i,y=j;
		}

	if(n%2==1){
		for(int i=0 ; i<n-1;i++){
			if(i%2){
				for(int j=0 ;j<m-1;j++)
					cout << "L";
				cout << "D";
			}
			else{
				for(int j=0 ;j<m-1 ; j++)
					cout << "R";
				cout << "D";
			}
		}
		for(int j=0 ;j<m-1 ; j++)
			cout << "R";
		return 0;
	}
	else if(m%2==1){
		for(int i=0 ; i<m-1 ; i++){
			if(i%2){
				for(int j=0 ; j<n-1 ; j++)
					cout << "U";
				cout << "R";
			}
			else{
				for(int j=0 ;j<n-1 ; j++)
					cout << "D";
				cout << "R";
			}
		}
		for(int j=0 ; j<n-1 ; j++)
			cout << "D";
		return 0;
	}
	else{
		int a=1;
		while(x-a>1){
			for(int i=0 ;i<m-1; i++) cout << "R";
			cout <<"D";
			for(int i=0 ;i<m-1; i++) cout << "L";
			cout <<"D";
		 	a+=2;
		}
		int b = n;
		string s = "";
		while(b-x>1){
			for(int i=0 ; i<m-1; i++) s+='R';
			s+='D';
			for(int i=0 ;i<m-1; i++) s+='L';
			s+='D';
			b-=2;
		}

		reverse(s.begin(),s.end());

		a=1,b=m;

		while(y-a>1){
			cout << "DRUR";
			a+=2;
		}
		while(b-y>1){
			s = "RURD" + s;
			b-=2;
		}

		if(a==y) cout << "RD";
		else cout << "DR";
		cout << s;
		return 0;

	}

	return 0;
}