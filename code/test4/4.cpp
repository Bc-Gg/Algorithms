/*
皮卡丘，0
喵喵，  1
圆企鹅，2
巴大蝶  3
小火龙 4
*/


# include<iostream>
# include<vector>

using namespace std;

const long long N = 1e9+7;

long long num[5] = {1,1,1,1,1},st[5];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1 ; i < n ;i++){
            st[0] = num[1] + num[2] + num[4];
            st[1] = num[0] + num[2];
            st[2] = num[1] + num[3];
            st[3] = num[2];
            st[4] = num[2] + num[3];
            for(int j = 0 ; j < 5 ; j++) num[j] = st[j] % N;
        }
        long long sum = 0;
        for(int i = 0; i < 5 ;i++) {
            sum += num[i];
            num[i] = 1;
        }
        cout << sum % N << endl;

    }
    return 0;
}

/*
author ： jxgg

#include<iostream>
using namespace std;

const unsigned long long N=1e9+7;

unsigned long long a[5][5]={0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0};
unsigned long long b[5][5]={0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0};
unsigned long long c[5][5];
int i,j,k;
int nn;
int t;
unsigned long long sum=0;


int main()
{
	cin>>t;
	while(t--){
		cin>>nn;
		if(nn==1) cout<<"5"<<endl;
		else if(nn==2) cout<<"10"<<endl;
		else{
		nn-=2;
	while(nn--){
	for(i = 0; i < 5; ++i)//矩阵相乘
	{
		for(j = 0; j < 5; ++j)
		{
			c[i][j]=0;
			for(k = 0; k < 5; ++k)
			c[i][j] += (a[i][k] * b[k][j]) % N; 
		}	
	}
	for(int ii=0;ii<5;ii++)
		for(int jj=0;jj<5;jj++) a[ii][jj]=c[ii][jj];
	}
    sum=0;
	for(i = 0; i < 5; ++i)//输出相乘后的矩阵
	{
		for(j = 0; j < 5; ++j){
            sum+=c[i][j] % N;
        }
	}
    cout<<sum % N<<endl;
	for(int ii=0;ii<5;ii++)
		for(int jj=0;jj<5;jj++) a[ii][jj]=b[ii][jj];
	}
	}
	return 0;
 }

*/
