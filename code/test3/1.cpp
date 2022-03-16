# include<iostream> 
# include<cstring>
using namespace std;
char str[500500];
int len = 0;
int ans = 0;
void load(int attack[]){
    int cnt = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        if (isdigit(c))
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            i = j - 1;
            attack[cnt++] = x;
        }
    }
    len = cnt;
}
int b[50050];
void Merge(int a[], int low, int mid, int high) {
    int k, i, j;
    for (k = low; k <= high; k++) {
        b[k] = a[k];
    }
    for (i = low, j = mid+1, k = i; i <= mid && j <= high; k++) {
        if(b[i] <= b[j])
        {
            a[k] = b[i++];
        }else {
            a[k] = b[j++];
            ans += mid + 1 - i; 
        }
    }
    while (i <= mid) {
        a[k++] = b[i++];
    }
    while (j <= high) {
        a[k++] = b[j++];
    }
}

void MergeSort(int a[], int low, int high){
    if(low < high) {
        int mid = (low + high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

int main(){
    int attack[500050] = {0};
    load(attack);
    MergeSort(attack ,0,len - 1);
    cout << ans;
    return 0;
}