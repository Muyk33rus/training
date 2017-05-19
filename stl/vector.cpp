#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int temp=-1;
    string str="none";
    vector<string> books;
    while(temp!=0){
        cout<<"Select\n"<<"1-add item\n"<<"2-delete item\n"<<"3-show item\n"<<"0-exit"<<endl;
        cin>>temp;
        switch (temp) {
         case 1:
            cout<<"add item:";
            cin>>str;
            if(books.end()==find(books.begin(),books.end(),str))
                books.emplace_back(str);
             else
                cout<<"This element is present"<<endl;
            break;
         case 2:{
            int count=0;
            cout<<"delete item:";
            cin>>str;
            for(auto it=books.begin();it!=books.end();it++){
                if(!str.compare(*it))
                    count++;
                else{
                 *(it-count)=*it;
                }
            }
            books.resize(books.size()-count);
            break;
        }
         case 3:{
            cout<<"show items:";
            if(!books.empty()){
                int count =0;
                for(auto i:books){
                    cout<<++count<<" "<<i<<endl;
                }
            }
            break;
        }
         case 0:
            break;
         default:
            temp=0;
            break;
        }
    }
    return 0;
}
