#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[5000001];
int n,k;

void swap(int low , int high){
  int temp;
  temp = arr[low];
  arr[low] = arr[high];
  arr[high] = temp;
}

void qsort(int low, int high){

  if(high<=low)
    return;

  int l = low,h = high+1;
  int pivot = arr[low];

  do{
    do l++; while(arr[l]<pivot);
    do h--; while(arr[h]>pivot);
    if(l<h) swap(l,h);
  }while(l<h);

  swap(low,h);
  if(h == k-1)
    return;
  else if(h > k-1)
    qsort(low,h-1);
  else if(h<k-1)
    qsort(h+1,high);
}


int main(){
  scanf("%d %d ",&n,&k);
  for(int i=0 ;i<n;i++)
    scanf("%d ",&arr[i]);

  qsort(0,n-1);

  printf("%d\n",arr[k-1]);

  return 0;
}
