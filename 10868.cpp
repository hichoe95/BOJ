#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 1e9+7

vector<int> num,tree,tree2;
vector<pair<int,int> > v;

void init(int node, int st, int e){
  if(st == e) tree[node] = num[st];
  else{
    init(node*2,st,(st+e)/2);
    init(node*2+1,(st+e)/2+1,e);
    tree[node] = min(tree[node*2],tree[node*2+1]);
  }
}

int segment(int node, int st, int e , int i ,int j){
  if(i>e || j<st) return INF;
  if(i<=st && j>=e) return tree[node];
  return min(segment(node*2,st,(st+e)/2,i,j),segment(node*2+1,(st+e)/2+1,e,i,j));
}

void init2(int node, int st, int e){
  if(st == e) tree2[node] = num[st];
  else{
    init2(node*2,st,(st+e)/2);
    init2(node*2+1,(st+e)/2+1,e);
    tree2[node] = max(tree2[node*2],tree2[node*2+1]);
  }
}

int segment2(int node, int st, int e , int i ,int j){
  if(i>e || j<st) return 0;
  if(i<=st && j>=e) return tree2[node];
  return max(segment2(node*2,st,(st+e)/2,i,j),segment2(node*2+1,(st+e)/2+1,e,i,j));
}

int main(){
  ios_base::sync_with_stdio(0);

  int n,m;
  cin >> n >> m;

  num.resize(n);
  v.resize(m);
  tree.resize(4*n);
  tree2.resize(4*n);

  for(int i=0 ;i<n;i++) cin >> num[i];
  for(int i=0 ;i<m;i++) cin >> v[i].first >> v[i].second;

  init(1,0,num.size()-1);
  init2(1,0,num.size()-1);
  for(auto i : v) cout << segment(1,0,num.size()-1,i.first-1,i.second-1) << " " << segment2(1,0,num.size()-1,i.first-1,i.second-1) << '\n';

  return 0;
}
