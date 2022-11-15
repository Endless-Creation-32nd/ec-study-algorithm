#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    pair <int,int> p[100001];

    for(int i=0;i<n;i++){
        cin>>p[i].second>>p[i].first;
    }
    sort(p,p+n);

    int ans=0;
    int num=0;
    for(int i=0;i<n;i++){
        if(num>p[i].second) continue;
        ans++;
        num = p[i].first;
    }
    cout<<ans;

}