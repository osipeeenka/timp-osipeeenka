#include <stdio.h>
#include <math.h>

int main(void){
    long int n;
    if(scanf("%ld", &n) == 1){
    long int temp;
    double sum = 0;
    long int i;
    double left, right;
    for(i = 1; i <= n; i++){
        if(scanf("%ld", &temp) == 1){
          left = pow((double)temp, 3);
          right = pow(-1, (double)(i + 1));
          sum += left * right;
        }
        else{
          printf("Ошибка ввода");
          break;
        }
    }
    printf("%.0lf", sum);
    }
    else{
      printf("Ошибка ввода");
    }
    return 0;
}
