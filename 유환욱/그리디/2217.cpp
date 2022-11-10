#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int arr[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, arr[n-i]*i);
    }
    cout<<ans;
}