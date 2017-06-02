#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//int* sort(int* a){
//        for (int i = 0;i<3;i++){
//            int min =a[i];
//            int imin=i;
//            for (int j = i+1;j<3;j++){
//                if(a[j]<min){
//                    min =a[j];
//                    imin =j;
//                }
//            }
//            if(i!= imin ){
//                int temp =a[i];
//                a[i]=a[imin];
//                a[imin]=temp;
//            }
//        }
//        return a;
//    }

int main() {
    int *a,*b,c=0,f=0,s=0;
    a=new int[3];
    b=new int[3];
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
//    sort(a);
//    sort(b);
    sort(a, a + 3);
    sort(b, b + 3);
    for (int i = 0;i < 3;i++) {
        if (a[i] == b[i])c++;
        else if (a[i] > b[i])f++;
        else if (a[i] < b[i])s++;
    }
    if (c == 3)
        cout << "Boxes are equal";
    else if (!f&&s)
        cout << "The first box is smaller than the second one";
    else if (f&&!s)
        cout << "The first box is larger than the second one";
    else
        cout << "Boxes are incomparable";
    delete []a;
    delete []b;
    return 0;
}