#include <iostream>
#include <vector>


using namespace std;

int main(){
    int n,ct=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        a[i]=i;
    for(int p=2;p<n;p++){
        if(a[p]!=0){
            ct++;
            cout<<ct<<" "<<a[p]<<endl;
            for(int j =p*p;j<n;j+=p)
                a[j]=0;
        }
    }
    return 0;
}
