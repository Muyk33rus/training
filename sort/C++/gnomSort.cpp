#include <iostream>
#include <functional>

enum type {less, greater};
template <typename T,type t>

template <typename T,type t>
void gnomSort(T *array,int size){
    std::function<bool(T,T)> predicate;
    int i=0,count=0;
    switch (t) {
            case greater:
                predicate = [] (T x, T y) { return x<=y?true:false; };
            break;
            case less:
                predicate = [] (T x, T y) { return x>=y?true:false; };
            break;
        }
    while(i<size){
        count++;
//        std::cout<<"iteration :"<<count<<" :";
        if(i==0||predicate(array[i-1],array[i]))
            i++;
        else{
            T temp=array[i-1];
            array[i-1]=array[i];
            array[i]=temp;
            i--;
        }
//        for (int i = 0; i < size; i++){
//            std::cout << array[i] << ", ";
//        }
//        std::cout <<std::endl;
    }
    std::cout<<"The  number of iterations :"<<count<<" :";
    for (int i = 0; i < size; i++){
        std::cout << array[i] << ", ";
    }
    std::cout <<std::endl;
}


int main(){

    int arr2[] = {1, 0, -1, 1, 54, 2, 3};
    gnomSort<int, greater> (arr2, 7);

}
