#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 10010;
int a[N],b[N];
int cmp(int a, int b){
    return a < b;
}

int main(){
    int k;
    while(scanf("%d",&k)!=EOF && k!=0){
        int n;
        int sum = 0;
        cin >> n;
        for(int i = 0 ; i < k; i++) cin >> a[i];
        for(int i = 0 ; i < k; i++) cin >> b[i];
        sort(a,a+k);//gang
        sort(b,b+k);//zhi
        int ha = k-1, hb = k-1, ta = 0 , tb = 0;
        for(int i = 0 ; i < k ; i++){
            if(a[ha] < b[hb]) {sum += n;ha--;hb--;}//小智快马比小刚快马还快
            else if(a[ta] < b[tb]) {sum += n; ta++;tb++;} // 慢马相比
            else{
                if(a[ha] > b[tb]) {sum -= n;ha--;tb++;}//否则就把小刚的快马恶心掉
            }
        }
        // cout << "sum is ";
        cout << sum << endl;
    }
    return 0;
}