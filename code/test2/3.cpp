#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> vec;

void reload(string str){
    for(int i = 0 ; i < str.size(); i++){
        if(!isdigit(str[i])) vec.push_back(str.substr(i,1));
        else{
            int k = i;
            while(k < str.size() && isdigit(str[k])){
                k++;
            }
            vec.push_back(str.substr(i,k-i));
            i = k - 1;
        }
    }
}

vector<int> conquer(int le,int ri){
    if(le == ri){
        vector<int> ret;
        ret.push_back(stoi(vec[le]));
        return ret;
    }
    vector<int> ret;
    for(auto i = le + 1; i < ri; i+=2){
        auto ans_le = conquer(le,i - 1);
        auto ans_ri = conquer(i + 1, ri);
        // i is '+' || '-' || '*'
        for(auto l :ans_le){
            for (auto r :ans_ri){
                if(vec[i] == "+") ret.push_back(l+r);
                else if (vec[i] == "-") ret.push_back(l-r);
                else if (vec[i] == "*") ret.push_back(l*r);
            }
        }
    }
    return ret;
}

int main(){
    string str;
    cin >> str;
    reload(str);
    auto ret = conquer(0,vec.size()-1);
    sort(ret.begin(),ret.end());
    for(auto re : ret){
        cout << re << endl;
    }
    return 0;
}