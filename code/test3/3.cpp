# include<iostream>
using namespace std;
long long len[100];
long long sumb(long long pos){
    printf("calcing :%lld\n", pos);
    if(!pos) return 0;
    for(int i = 1 ; i < 100 ;i++){
        if(pos == len[i])
            return len[i-1] + 1;
        else if(pos < len[i]){
            return pos - len[i-1] + sumb(len[i] - pos);
        }
    }
}

void load(){
    len[0] = 0;
    for(int i = 1 ; i < 100;i++)
        len[i] = 2 * len[i-1] + 1;
}

int main(){
    load();
    int t;
    cin >> t;
    while(t--){
        long long le, ri;
        cin >> le >> ri;
        cout << sumb(ri) - sumb(le-1) << endl;
    }
    return 0;
}