#include <iostream>

using namespace std;
//наибольший элемент в массиве сложность O(N)
template <typename T>
T FindLargest(T*array, int arraySize){
    T largest=array[0];
    for(int i=1;i<arraySize;i++){
        if(array[i]>largest)
            largest=array[i];
    }
    return largest;
}

int main(){
    float a[]={36.7893 ,373,36.66 ,3.55};
    cout<<FindLargest(a,4)<<endl;
}
