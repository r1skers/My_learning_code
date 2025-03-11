//输入五个数字，冒泡排序
#include<stdio.h>
int main(int argc, char *argv[])
{
	int a[5];
	for(int i = 0; i < 5; i++) {
scanf("%d", &a[i]);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if(a[i]<a[i+1]){
				int b;
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
			}	
	}
}