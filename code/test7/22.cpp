# include<iostream>
#include<vector>
#include<algorithm>
# include<utility>
using namespace std;
const int N = 10010;
typedef pair<int ,int> PII;

int d[N],t[N],f[N];// decrease, time from i-1 to i, fish_output
int timee[N],maxtime[N];
int cmp(PII &a, PII &b){
    if (a.second != b.second) return (a.second > b.second);
    else return a.first < b.first;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF &&  n!= 0){
        PII pool[N];
        int time;
        int ans = 0;
        cin >> time;
        time *= 12;
        for(int i = 0 ; i < n ; i++) timee[i] = 0;
        for(int i = 0 ; i < n ; i++) cin >> f[i];
        for(int i = 0 ; i < n ; i++) cin >> d[i];
        for(int i = 1 ; i < n ; i++) cin >> t[i];
        for(int i = 0 ; i < n ; i++) pool[i] = {i,f[i]};
        for(int i = 0 ; i < n ;i++){
            PII tpool[N];
            for(int j = 0 ; j < n ; j++) tpool[j] = pool[j];
            time -= t[i];
            int maxfish = 0;
            int temp_time = time;
            while(temp_time > 0){
                sort(tpool,tpool+i,cmp);
                if(tpool[0].second <= 0) break;
                printf("{%d ,%d}\t",tpool[0].first+1,tpool[0].second);
                maxfish += tpool[0].second;
                temp_time --;
                timee[tpool[0].first]++;
                tpool[0].second -= d[tpool[0].first];
            }
            printf("maxfish = %d\t",maxfish);
            if(maxfish > ans || i == 0){
                ans = maxfish;
                for(int i = 0 ; i < n ; i++){
                    maxtime[i] = timee[i];
                }
                maxtime[0] = time;
                for(int i = 1 ; i < n ; i++) maxtime[0] -= timee[i];
            }   
            cout << endl ;
        }
        for(int i=0;i<n-1;i++) cout<<maxtime[i]*5<<", ";
        cout<<maxtime[n-1]*5 <<endl;
        cout<<"Number of fish expected: "<<ans<<endl<<endl;
    }

    return 0;
}
/*
for(int j = 0 ; j < i ; i++){
                    cout << " " <<'{' << tpool[j].first << " " << tpool[j].second<<'}';
                }
                */