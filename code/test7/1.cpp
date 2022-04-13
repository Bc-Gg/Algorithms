# include<iostream>
# include<cstring>
using namespace std;
const int N = 10010;
char str[N],stk[N];
int main(){
    int k;
    cin >> k;
    scanf("%s",str);
    int top = 0;
    int len = strlen(str);
    for(int i = 0; i < len;i++){
        while(top > 0 && k > 0 && stk[top-1] > str[i]){
            top--;
            k--;
        }
        if(top != 0 || str[i]!='0'){
            stk[top++] = str[i];
        }
    }
    while(k > 0 && top > 0){
        top--;k--;
    }
    if(top == 0) cout << "0" <<endl;
    else {
        for(int i = 0 ; i < top ;i++) cout <<stk[i];
        cout << endl;
    }
    return 0;
}