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
    for(int i = 0; i < len; i++){
        //栈非空，而且还可以移走数字，而且栈顶元素大于当前元素
        while(top > 0 && k > 0 && stk[top-1] > str[i]){
            top--;// 寻找更小的数字，每一次pop相当于移走一位数字
            k--;
        }
        if(top != 0 || str[i]!='0'){// 栈不空或者当前元素不是0的时候，压栈
            stk[top++] = str[i];
        }
    }
    while(k > 0 && top > 0){ //收尾工作把能pop的都pop掉
        top--;k--;
    }
    if(top == 0) cout << "0" <<endl;
    else {
        for(int i = 0 ; i < top ;i++) cout <<stk[i];
        cout << endl;
    }
    return 0;
}