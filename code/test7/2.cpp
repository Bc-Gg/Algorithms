# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

const int N=10005;
int dis[N],n,h,Time[N],maxtime[N];

struct Node {
    int Fish,Dec,index;
}a[N];

bool cmp(Node p1,Node p2){
    if(p1.Fish!=p2.Fish) return p1.Fish>=p2.Fish;
    return p1.index<p2.index;
}

int main()
{
    while(cin>>n&&n!=0){
        cin>>h;
        for(int i=1;i<=n;i++) scanf("%d",&a[i].Fish);
        for(int i=1;i<=n;i++) scanf("%d",&a[i].Dec);
        for(int i=2;i<=n;i++) scanf("%d",&dis[i]);
        for(int i=1;i<=n;i++) a[i].index=i;
        h*=12;
        int sum=0,ans=0;
        Node b[n];
        for(int i=1;i<=n;i++) b[i]=a[i];
        for(int i=1;i<=n;i++){
            h-=dis[i];
            sum=0;
            int time=h;
            while (time>0){
                sort(a+1,a+1+i,cmp);
                // for(int j = 1 ; j <= i ;j++) printf("{%d %d}",a[j].index, a[j].Fish);
                // printf("\n");
                if(a[1].Fish<=0) break;
                sum+=a[1].Fish;
                Time[a[1].index]++;
                time--;
                a[1].Fish-=a[1].Dec;
            }
            for(int i=1;i<=n;i++) a[i]=b[i];
            if(sum>ans){
                ans=sum;
                for(int j=1;j<=n;j++) maxtime[j]=Time[j];
                maxtime[1]=h;
                for(int j=2;j<=n;j++) maxtime[1]-=maxtime[j];
            }
            for(int j=1;j<=n;j++) Time[j]=0;
        }
        for(int i=1;i<n;i++) cout<<maxtime[i]*5<<", ";
        cout<<maxtime[n]*5<<endl;
        cout<<"Number of fish expected: "<<ans<<endl<<endl;
    }
    return 0;
}