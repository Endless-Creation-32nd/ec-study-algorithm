#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int dp[100001];

    cin>>n>>m;

    dp[0]=0;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        dp[i] = dp[i-1] + num;
    }

    for(int x=0;x<m;x++){
        int i,j;
        cin>>i>>j;
        cout<<dp[j]-dp[i-1]<<'\n';
    }


}

    // 처음 코드
//     int main(){
//     int n, m;
//     int dp[100001];

//     cin>>n>>m;

//     for(int i=0;i<n;i++){
//         cin>>dp[i+1];
//     }

//     for(int k=0;k<m;k++){
//         int i,j;
//         int max=0;
//         cin>>i>>j;

//         for(int x=i;x<=j;x++){
//             max += dp[x];
//         }
//         cout<<max<<'\n';
//     }

// }