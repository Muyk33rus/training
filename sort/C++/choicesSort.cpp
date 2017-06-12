#include <iostream>
#include <functional>
#include <array>
using namespace std;
enum type {les, gre};

template <typename T,type t>
void choicesSort(T array[], int size){
    std::function<bool(T,T)> predicate;
    switch (t) {
            case les:
                predicate = [] (T x, T y) { return x<=y?true:false; };
            break;
            case gre:
                predicate = [] (T x, T y) { return x>=y?true:false; };
            break;
        }
    for (int repeat_counter = 0; repeat_counter < size; repeat_counter++)
    {
        T temp = array[0];
        for (int element_counter = repeat_counter + 1; element_counter < size; element_counter++)
        {
            if (predicate(array[repeat_counter], array[element_counter]))
            {
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                array[element_counter] = temp;
            }
        }
    }
}

int main(){

    array<int,7> arr = {1, 0, -1, 1, 54, 2, 3};
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
    choicesSort<int, gre> (arr.data(), arr.size());
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
}
