//0 と 1 のみからなるファイルに含まれる「0 の個数」と「１の個数」の差の絶対値を出力する実行ファイルdifference を作成せよ．さらに、WebClass で提示されるファイルについて、その差を解答せよ。




#include<stdio.h>
void count(int a)
{
  if(a<0)
    {
      printf("%d",-a);
    }
  else if(a>0)
    {
      printf("%d",a);
    }
  return;
}
int main(void){
  int a,sum0=0,sum1=0;
  char *filename="array.dat";

  FILE *file=fopen(filename,"r");
  while(fscanf(file,"%d",&a)==1)
    {
    if(a==0)
      {
	sum0++;
      }
    else if(a==1)
      {
	sum1++;
      }
  }
  fclose(file);
  count(sum0-sum1);
    return 0;
}
