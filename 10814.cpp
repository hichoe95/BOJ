#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Person{
  int age;
  string name;
  int join;
};

int main(){

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<Person> people(n);

  for(int i=0 ;i<n;i++){
    cin >> people[i].age >> people[i].name;
    people[i].join = i;
  }

  sort(people.begin(),people.end(), [](Person u, Person v) {
    return (u.age < v.age) || (u.age==v.age && u.join<v.join);
  });

  for(auto &p : people)
    cout << p.age << " " << p.name << '\n';


  return 0;
}
