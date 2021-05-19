#include <stdio.h>

int main(void){
    int n;
    if(scanf("%d", &n) == 1){
    int cntPositive = 0;
    int temp;
    int i;
    for (i = 1; i <= n; i++)
    {
        if(scanf("%d", &temp) == 1 && temp > 0){
            cntPositive = cntPositive + 1;
        }
    }   
    printf("%d", cntPositive);
    }
    else{
    	printf("Ошибка ввода...");
    }
    return 0;
}
