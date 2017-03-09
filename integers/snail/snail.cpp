#include <stdio.h>
int main()
  {
  int h,a,b,t=0,i=0;
  scanf("%d%d%d",&h,&a,&b);
// t=(h-b)/(a-b)+((h-b)%(a-b)? 1:0);
//  printf("%d\n", t);
	while(t<=h){
		i++;
		t+=a;
		if(t>=h){
			printf("%d\n", i);
			break;
		}
		t-=b;
	}

  return 0;
  }
