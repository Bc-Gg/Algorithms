# include<iostream>
# include<algorithm>
# include<cmath>
using namespace std;
const int maxn=1e4+100;
const int inf=0x3f3f3f3f;
int n;
double minlen,x[maxn],r[maxn],b[maxn];//排列的最短距离，圆的x坐标，圆的半径，圆最佳排列顺序。 
double center(int k){
    double t=0;
    for(int i=1;i<k;++i){
        t=max(t,x[i]+2.0*sqrt(r[i]*r[k]));
    }
    return t;
}
void compute(){
    double l=0,h=0;
    for(int i=1;i<=n;++i){
        if(x[i]-r[i]<l) {
            l=x[i]-r[i];
        }
        if(x[i]+r[i]>h){
            h=x[i]+r[i];
        }
    }
    if(h-l<minlen){
        minlen=h-l;
        printf("find minlen: %lf\n", minlen);
        for(int i=1;i<=n;++i){
            b[i]=r[i];
        }
    }
}
void dfs(int k){
    if(k>n)//排列结束，计算排列长度 
        compute();
    else{
        for(int i=k;i<=n;++i) {
            swap(r[k],r[i]);//排列 
            double xx=center(k);
            if(xx+r[1]+r[k]<minlen){//剪枝 
                x[k]=xx;
                dfs(k+1);
            }
            swap(r[k],r[i]);//复原，防止下一个排列缺少情况 
        }
    }
}
int main(){
	minlen=inf; 
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf",&r[i]);
    dfs(1);
    printf("最短距离:%f\n",minlen);
    for(int i=1;i<=n;++i){
        printf("%f%c",b[i],"\n "[i!=n]);
    }
    return 0;
}
