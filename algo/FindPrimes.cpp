#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;
// Находим простые числа между 2 и max_number (включительно) сложность O(N log (log N))
vector<long> FindPrimes(long max_number){
    bool * is_composite= new bool[max_number+1];
    // Исключаем числа, кратные 2
    for(int i=4;i<max_number;i+=2){
        is_composite[i]=true;
    }
    // Исключаем числа, кратные найденным простым числам
    int next_prime=3, stop_at= sqrt(max_number);
    while(next_prime<=stop_at){
        // Исключаем числа, кратные данному простому числу
        for(int i=next_prime*2;i<max_number;i+=next_prime){
            is_composite[i]=true;
        }
        // Переходим к следующему простому числу, пропуская четные числа
        next_prime+=2;
        while(next_prime<=max_number&&is_composite[next_prime]){
            next_prime+=2;
        }
    }
    vector<long> primes;
    // Заносим простые числа в список
    for(int i=2;i<max_number;i++){
        if(!is_composite[i]){
            primes.emplace_back(i);
        }
    }
    return primes;
}

vector<long> FindPrimes1(long max_number){
    vector <long> a(max_number);
    vector<long> primes;
    for(long i=0;i<max_number;i++)
        a[i]=i;
    for(long p=2;p<max_number;p++){
        if(a[p]!=0){
            primes.emplace_back(a[p]);
            for(unsigned long j =p*p;j<(unsigned long)max_number;j+=p)
                a[j]=0;
        }
    }
    return primes;
}


int main(){
    clock_t t=clock();
  auto vec=FindPrimes(37680);
  clock_t t1=clock();
  t=clock()-t;
  cout<<float(t)/CLOCKS_PER_SEC<<endl;
  int count=1;
  for(auto i:vec){
      cout<<count<<" "<<i<<endl;
      count++;
  }
  cout<<endl;
  t1=clock()-t1;
  cout<<float(t)/CLOCKS_PER_SEC<<endl;
  cout<<float(t1)/CLOCKS_PER_SEC<<endl;
  vec.clear();
}
