#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;
//нахождение простых множестелей сложность O(N)
vector<int> FindFactors(long num){
    vector<int> factors;
    long i=2;
    while(i<num){
        while (num%i==0) {
            factors.emplace_back(i);
            num/=i;
        }
        i++;
    }
    if(num>1){
        factors.emplace_back(num);
    }
    return factors;
}

//нахождение простых множестелей сложность O(sqrt(N))
vector<int> FindFactors1(long num){
    vector<int> factors;
    // Проверяем делимость на 2
    while(num%2==0){
        factors.emplace_back(2);
        num/=2;
    }
    // Ищем нечетные множители
    int i =3;
    int max_fac=sqrt(num);
    while(i<=max_fac){
        // Проверяем делимость на i
        while(num%i==0){
            // i является множителем. Добавляем его
            factors.emplace_back(i);
            // Делим число на i
            num/=i;
            // Устанавливаем новую верхнюю границу
            max_fac=sqrt(num);
        }
        // Проверяем следующий возможный нечетный множитель
        i+=2;
    }
    if(num>1){
        factors.emplace_back(num);
    }
    return factors;
}

int main(){
    clock_t t=clock();
  auto vec=FindFactors(376839371);
  t=clock()-t;
  cout<<float(t)/CLOCKS_PER_SEC<<endl;
  for(auto i:vec){
      cout<<i<<" ";
  }
  cout<<endl;
  vec.clear();
  t=clock();
  vec=FindFactors1(376839371);
  t=clock()-t;
  cout<<float(t)/CLOCKS_PER_SEC<<endl;
  for(auto i:vec){
      cout<<i<<" ";
  }
}
