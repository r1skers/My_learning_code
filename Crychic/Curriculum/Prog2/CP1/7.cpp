#include <stdio.h> 
 
int addSquare(int n, int sum) 
{ 
    sum += n * n; 
    return sum;
} 
  
int main() 
{ 
    int sum = 0; 
    for (int i = 1; i <= 10; ++i) 
    {
        sum=addSquare(i, sum);
    }
    printf("%d\n", sum); 
    return 0; 
} 
