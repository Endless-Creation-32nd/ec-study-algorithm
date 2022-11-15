#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    
    for(int i=n-1;i>=0;i--){
        ans += k/arr[i];
        k %= arr[i];
    }
    cout<<ans;
}