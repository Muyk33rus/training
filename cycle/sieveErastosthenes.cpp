#include <iostream>
#include <vector>


using namespace std;

int main(){
    int n,ct=0;
    cin>>n;
    vector <long> a(n);
    for(long i=0;i<n;i++)
        a[i]=i;
    for(long p=2;p<n;p++){
        if(a[p]!=0){
            ct++;
            cout<<ct<<" "<<a[p]<<endl;

            for(unsigned long j =p*p;j<n;j+=p)
                a[j]=0;
        }
    }
    return 0;
}
