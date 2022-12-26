#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first <= b.first;
}

int main(){
    int n;
    cin>>n;
    
    vector<pair<int, int>> meetings;
    while(n--){
        int start, end;
        cin>>start>>end;
        meetings.push_back({start, end});
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    sort(meetings.begin(), meetings.end(), compare);
    n = meetings.size();

    for(int i=0; i<n; i++){
        if(!minHeap.empty()){
            if(meetings[i].first >= minHeap.top())
            {
                minHeap.pop();
            }
            minHeap.push(meetings[i].second);
        }else{
            minHeap.push(meetings[i].second);   
        }
    }
    
    cout<<minHeap.size()<<endl;
}