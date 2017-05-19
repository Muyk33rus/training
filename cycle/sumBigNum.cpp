#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char* sum(const char*one,const char*two){
   short lenOne=strlen(one);
   short lenTwo=strlen(two);
   short size;
   char *rez;

   if(lenOne<lenTwo)
       size=lenTwo+1;
   else
       size=lenOne+1;
   rez=new char[size];
   for(int i=0;i<size;i++){
    rez[i]='0';
   }
   char buf1[lenOne],buf2[lenTwo];
   strcpy(buf1,one);
   strcpy(buf2,two);
   std::reverse(buf1,buf1+lenOne);
   std::reverse(buf2,buf2+lenTwo);
   for(int i=0;i<size;i++){
       if(i<lenOne&&i<lenTwo)
           rez[i]+=buf1[i]%48+buf2[i]%48;
       else if(i<lenOne&&i>lenTwo)
           rez[i]+=buf1[i]%48;
       else if(i>lenOne&&i<lenTwo)
           rez[i]+=buf2[i]%48;
       rez[i+1]+=rez[i]/58;
       if(rez[i+1]=='1'){
           if(0==rez[i]%58)
               rez[i]='0';
           else
               rez[i]=rez[i]-10;
       }
   }
   std::reverse(rez,rez+size);
   if (rez[0]=='0')
       return &rez[1];
   else
       return rez;
}

int main(){
    const unsigned long long SIZE=4*1024*1024;
    char * one=new char[SIZE];
    cin.getline(one,SIZE);
    char * two=new char[SIZE];
    cin.getline(two,SIZE);
    char *rez =sum(one,two);
    for(unsigned i=0;i<strlen(rez);i++)
        cout<<rez[i];
    delete[] rez;
    delete[] one;
    delete[] two;
}
