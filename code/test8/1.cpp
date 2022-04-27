#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N=10;
int g[N][N];
bool row[N][N+1],col[N][N+1],b[3][3][N+1];

bool dfs(int x,int y)
{
    if(y==9) x++,y=0;
    if(x==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) cout<<g[i][j];
            cout<<endl;
        }
        return true;
    }
    if(g[x][y]!=0) return dfs(x,y+1);
    for(int t=1;t<=9;t++)
    {
        if(!row[x][t]&&!col[y][t]&&!b[x/3][y/3][t])
        {
            row[x][t]=col[y][t]=b[x/3][y/3][t]=true;
            g[x][y]=t;
            if(dfs(x,y+1)) return true;
            g[x][y]=0;
            row[x][t]=col[y][t]=b[x/3][y/3][t]=false;
        }
    }
    return false;
}

int main()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            char ch;
            cin >> ch;
            int t=ch-'0';
            if(ch == '.') t = 0;
            g[i][j]=t;
            if(t!= 0)
                row[i][t]=col[j][t]=b[i/3][j/3][t]=true;
        }
    dfs(0,0);
    return 0;
}