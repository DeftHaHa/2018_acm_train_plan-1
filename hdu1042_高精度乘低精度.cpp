/**
# N!
## Problem Description
Given an integer N(0 ¡Ü N ¡Ü 10000), your task is to calculate N!
## Input
One N in one line, process to the end of file.
## Output
For each N, output N! in one line.
## Sample Input
1
2
3
## Sample Output
1
2
6
**/
#include<iostream>
#include<cstring>
using namespace std;
int ans[40000];
int n;
int len;
int main(){
    while(cin>>n){
        memset(ans,0,sizeof(ans));
        ans[0]=1;
        len=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<len;j++)
                ans[j]*=i;
            for(int j=0;j<len;j++){
                ans[j+1]+=ans[j]/10;
                ans[j]%=10;
            }
            while(ans[len]){
                ans[len+1]+=ans[len]/10;
                ans[len++]%=10;
            }
        }
        for(int i=len-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
