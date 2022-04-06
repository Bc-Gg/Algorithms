#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ;i++){
        int t;
        cin >> t;
        q.push(t);
    }
    int sum = 0;
    while(q.size()>1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        sum += a+b;
        q.push(a+b);
    }
    cout << sum;
    return 0;
}