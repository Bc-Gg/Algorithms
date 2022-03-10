#include<iostream>
#include<cmath>
using namespace std;
const int N  = 1e5+10;
double mid,le, ri,b[N];
int n;

double ff(double x){
    int ss = 0;
    for(int i = 0 ;i < n;i++)
        ss += int(b[i] / x);
    return ss;
}

int main(){
    int f,t;
    double sum = 0;
    cin >> n >> f;
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        b[i] = t * t;
        sum += t * t;
    }
    sum /= f;
    le = 0, ri = sum;
    while(fabs(ri-le) > 1e-6){
        mid = (le + ri) / 2 ;
        if((ff(mid)) >= f){
            le = mid;
        }
        else ri = mid;
    }
    printf("%.4lf",le);
    return 0;
}