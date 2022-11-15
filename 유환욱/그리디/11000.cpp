#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector <pair<int,int>> v;
    priority_queue <int, vector<int>, greater<int>> q;      // 우선순위 큐 생성

    cin>>n;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());        // 시작하는 시간 순으로 정렬

    q.push(v[0].second);            // 가장 먼저 시작하는 강의의 끝나는 시간을 우선순위 큐에 집어넣음

    for(int i=1;i<n;i++){           
        if(v[i].first>=q.top()){    // 두번째로 먼저 시작하는 강의부터 우선순위 큐 안에 있는 끝나는 시간 값과 비교
            q.pop();                // 만약 들을 수 있다면 우선순위 큐 안에 있는 끝나는 시간을 지우고
            q.push(v[i].second);    // 이어 들을 수 있는 강의의 끝나는 시간을 우선순위 큐에 저장
        }
        else {                      // 만약 이어 들을 수 없다면 ex) 1,3 -> 2,5
            q.push(v[i].second);    // 강의의 끝나는 시간을 우선순위 큐에 집어넣는다.
        }
    }   
    cout<<q.size();                 // 우선순위 큐의 크기가 필요한 강의실의 수가 된다.
}