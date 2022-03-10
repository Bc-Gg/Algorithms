//
//  main.cpp
//  test1
//
//  Created by 刘本宸 on 2022/3/2.
//
# include<math.h>
#include <iostream>
using namespace std;
unsigned long long s[310];
unsigned long long inf = 100000000;
void four(){
    s[1] = 1;
    s[2] = 3;
    for(int i = 3 ; i < 301 ; i++){
        s[i] = inf;
        for(int j = 1 ; j < i ;j++){
            if(2 * s[j] + (int)pow(2, i-j) -1 < s[i])
                s[i] =2 * s[j] + (int)pow(2, i-j) -1;
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    four();
    printf("%lld",s[n]);
    return 0;
}
