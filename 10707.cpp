#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d,p;
	cin >> a >> b >> c >> d >> p;
	cout << min(p*a, p<=c ? b : b + (p-c) * d);
}
