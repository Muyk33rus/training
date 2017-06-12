#include <iostream>
#include <functional>
#include <array>
using namespace std;
enum type {les, gre};

template <typename T,type t>
void gnomSort(T array[],int size){
    std::function<bool(T,T)> predicate;
    int i=0;
    switch (t) {
            case gre:
                predicate = [] (T x, T y) { return x<=y?true:false; };
            break;
            case les:
                predicate = [] (T x, T y) { return x>=y?true:false; };
            break;
        }
    while(i<size){
        if(i==0||predicate(array[i-1],array[i]))
            i++;
        else{
            T temp=array[i-1];
            array[i-1]=array[i];
            array[i]=temp;
            i--;
        }
    }
}


int main(){

    array<int,7> arr = {1, 0, -1, 1, 54, 2, 3};
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
    gnomSort<int, gre> (arr.data(), arr.size());
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
}
