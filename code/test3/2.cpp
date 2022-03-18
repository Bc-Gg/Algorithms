/*
传送门：
http://poj.org/problem?id=3301
另一道：
http://blog.sina.com.cn/s/blog_77dc9e08010151f5.html
为什么要用三分：很明显在坐标轴旋转的过程中最小正方形的边长是先减后增的趋势，为单峰函数，因此可以用三分法来进行解决。
如果是二分的话，如果是类似拖尾的函数就寄了（没法陷入局部最优
*/
# include<iostream>
# include <iomanip>
# include<algorithm>
# include<cmath>
using namespace std;
const int N = 80;
const double inf = 1e20+1;
const double pi = acos(-1);
double x[N], y[N];
int num;
double cal_square(double alpha);
/*
下面这东西叫三分，其实就是三等分，比二分多了一分
 */ 
double find_min_square(double le, double ri){
    while(fabs(le - ri) > 1e-14){
        //这是三分的一种写法，其实也可以对 mmid = (mid + ri) / 2
        auto midr = (le + ri) /2 ; 
        auto midl = (midr + le) / 2;
        if(cal_square(midl) <= cal_square(midr)) ri = midr;
        else le = midl;
    }
    return cal_square(le);
}

double cal_square(double alpha){
    double x1 ,y1;
    double maxx = -inf , maxy = -inf, minx = inf, miny = inf;
    for(auto i = 0 ; i < num ; i++){
        //坐标变换
        x1 = x[i] * cos(alpha) - y[i] * sin(alpha);
        y1 = x[i] * sin(alpha) + y[i] * cos(alpha);
        maxx = max(maxx, x1), maxy = max(maxy, y1);
        minx = min(minx, x1), miny = min(miny, y1);
    }
    return max(maxx - minx, maxy - miny); // 返回长和宽中最长的那个
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> num;
        for(int i = 0 ; i < num ;i++)
            cin >> x[i] >> y[i];
        double min_square = find_min_square(0,pi);
        printf("%.2lf\n",pow(min_square,2));
    }
    return 0;
}