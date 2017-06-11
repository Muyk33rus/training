#include <iostream>
#include <functional>

enum type {less, greater};
template <typename T,type t>
void bubbleSort(T *array,int size){
    std::function<bool(T,T)> predicate;
    int count=0;
    bool swapped = false;
    switch (t) {
            case greater:
                predicate = [] (T x, T y) { return x>y?true:false; };
            break;
            case less:
                predicate = [] (T x, T y) { return x<y?true:false; };
            break;
        }
    for(int i=0;i<size-1;i++){
        swapped = false;
        for(int j=0;j<size-i-1;j++){
           if (predicate(array[j],array[j+1])){
               T temp=array[j];
               array[j]=array[j+1];
               array[j+1]=temp;
               swapped = true;
           }
           count++;
        }
        if (!swapped) break;
    }
    std::cout<<"The  number of passes :"<<count<<std::endl;
    for (int i = 0; i < size; i++){
        std::cout << array[i] << ", ";
    }
    std::cout<<std::endl;
}


int main(){

    int arr[] = {1, 0, 2, 1, 54, 2, 3};
    bubbleSort<int, greater> (arr, 7);
    bubbleSort<int, less> (arr, 7);


}
