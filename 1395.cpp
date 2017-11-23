#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdio>
using namespace std;

int N,M;
vector<int> tree;
vector<int> lazy;

void update(int node, int st, int e){
  if(lazy[node]){
    if(lazy[node] & 1) tree[node] = e-st+1 - tree[node];
    if(st!=e){
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void input(int node,int st, int e, int i, int j){
  update(node,st,e);
  if(i<=st && j>=e){
    tree[node] = e-st+1 - tree[node];
    if(st!=e){
      lazy[node*2] += 1;
      lazy[node*2+1] += 1;
    }
    return;
  }
  else if(i>e || j<st) return;
  input(node*2,st,(st+e)/2,i,j);
  input(node*2+1,(st+e)/2 +1,e,i,j);
  tree[node] = tree[node*2] + tree[node*2+1];
}

int output(int node,int st, int e, int i, int j){
  update(node,st,e);
  if(i<=st && j>=e) return tree[node];
  if(i>e || j<st) return 0;
  return output(node*2, st , (st+e)/2, i,j) + output(node*2+1,(st+e)/2+1,e,i,j);
}


int main(){
  scanf("%d %d",&N,&M);
  int h = (int)ceil(log2(N));
  int sz = (1 << (h+1));
  tree.resize(sz);
  lazy.resize(sz);

  for(int i=0 ;i<M ; i++){
    int O,S,T;
    scanf("%d %d %d",&O,&S,&T);
    if(O) printf("%d\n",output(1,0,N-1,S-1,T-1));
    else input(1,0,N-1,S-1,T-1);
  }

  return 0;
}
