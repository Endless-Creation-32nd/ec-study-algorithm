#include <iostream>
#include <math.h>
using namespace std;

int d[1000005];
int arr[1000005];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  d[1] = 0;
  arr[1] = 0;

  for(int i = 2; i <= n; i++){
    d[i] = d[i-1]+1;
    arr[i] = i-1;

    if(i%2 == 0 && d[i] > d[i/2] + 1) {
        d[i] = d[i/2]+1;
        arr[i] = i/2;
    }
    if(i%3 == 0 && d[i] > d[i/3] + 1) {
        d[i] = d[i/3]+1;
        arr[i] = i/3;
    }
  }
  
  cout << d[n] << '\n';
  while(n!=0){
    cout<<n<<' ';
    n = arr[n];
  }
}