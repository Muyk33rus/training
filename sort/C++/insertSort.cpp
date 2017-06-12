#include <iostream>
#include <array>
#include <functional>

using namespace std;

enum type {les, gre};

template <typename T,type t>
void InsertSort(T array[],size_t size){
    std::function<bool(T,T)> predicate;
    switch (t) {
            case gre:
                predicate = [] (T x, T y) { return x>=y?true:false; };
            break;
            case les:
                predicate = [] (T x, T y) { return x<=y?true:false; };
            break;
        }
    T temp=0;
    int item=0;
        for (auto counter = 1; counter < (int)size; counter++)
        {
            temp = array[counter]; // инициализируем временную переменную текущим значением элемента массива
            item = counter-1; // запоминаем индекс предыдущего элемента массива
            while(item >= 0 && predicate(array[item],temp)) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
            {
                array[item+1] = array[item]; // перестановка элементов массива
                array[item] = temp;
                item--;
            }
        }
}


int main(){
    array<int,8> arrayInt={3,2,13,4,43,2,33,4};
    for(auto i: arrayInt){
        cout<<i<<" ";
    }cout<<endl;
    InsertSort<int,les>(arrayInt.data(),arrayInt.size());
    for(auto i: arrayInt){
        cout<<i<<" ";
    }cout<<endl;
}
