#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int r,cc;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<string> c;
bool check[27];

int go(int x,int y){
	int ans = 0;
	for(int i=0 ;i<4 ; i++){
		if(x+dx[i]>=0 && y+dy[i]>=0 && x+dx[i]<r && y+dy[i]<cc && check[c[x+dx[i]][y+dy[i]]-'A']==false){
			check[c[x+dx[i]][y+dy[i]]-'A'] = true;
			int ret = go(x+dx[i],y+dy[i]);
			check[c[x+dx[i]][y+dy[i]]-'A'] = false;
			ans = (ret > ans ? ret : ans);
		}
	}

	return ans+1;
}

int main(){

	scanf("%d %d",&r,&cc);

	c.resize(r);

	for(int i =0 ;i<r;i++)
		cin>>c[i];

	check[c[0][0]-'A'] = true;
	cout << go(0,0);

	return 0;
}