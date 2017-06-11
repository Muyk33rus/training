#include <random>
#include <iostream>
#include <algorithm>
using namespace std;
//рандомизация массива сложность O(N)
template <typename T>
T RandomizeArray(T*array, int arraySize){
    T largest=array[0];
    for(int i=0;i<arraySize;i++){
        int j= 1+rand()%arraySize-1;
        swap(array[i],array[j]);
    }
    return largest;
}

int main(){
    float a[]={36.7893 ,373,36.66 ,3.55,36.7893 ,373,36.66 ,3.55,36.7893 ,373,36.66 ,3.55,36.7893 ,373,36.66 ,3.55};
    for(int i=0;i<16;i++){
        cout<<a[i]<<endl;
    }
    cout<<"RandomizeArray"<<endl;

    RandomizeArray(a,16);
    for(int i=0;i<16;i++){
        cout<<a[i]<<endl;
    }
}