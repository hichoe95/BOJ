#include <iostream>
#include <cstring>
using namespace std;
const char fan[6] = ":fan:";

int main(){

	char name[22];
	cin >> name;
	int len = strlen(name);

	for(int i=0 ;i< 3 ; i++) cout << fan;
	cout << '\n';
	cout << fan << ':' << name << ':' << fan;
	cout << '\n';
	for(int i=0 ;i< 3 ; i++) cout << fan;

	return 0;
}