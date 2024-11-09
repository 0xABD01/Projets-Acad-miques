#include<stdio.h>

void permutation (int *i, int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
main(){
    int num1,num2;
    printf("saisir deux entier a permuter\n");
    printf("num1 :");
    scanf("%d",&num1);
    printf("num2 :");
    scanf("%d",&num2);
    printf("avant :\nnum1 = %d || num2 = %d\n",num1,num2);
    permutation(&num1,&num2);
    printf("apree :\nnum1 = %d || num2 = %d\n",num1,num2);
}