#include <iostream>
#include <cmath>
using namespace std;

int rec(int n,int r,int c){
	if(n==1) return 0;

	int d = n/2;

	if(r/d==0 && c/d==0)
		return rec(d,r,c);
	else if(r/d==0 && c/d==1)
		return d*d + rec(d,r,c-d);
	else if(r/d==1 && c/d==0)
		return 2*d*d + rec(d,r-d,c);
	else
		return 3*d*d + rec(d,r-d,c-d);

}

int main(){
	int n,r,c;
	cin >> n >> r >> c;
	n = (int)pow(2,n);

	cout << rec(n,r,c) << '\n';

	return 0;
}