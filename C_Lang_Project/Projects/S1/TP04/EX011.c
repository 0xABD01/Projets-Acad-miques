#include<stdio.h>

void permutation(int *num1, int *num2);

int main(){
    int A,B;
    printf("veillez saisir A et B :\n");
    printf("A : ");
    scanf("%d",&A);
    printf("B : ");
    scanf("%d",&B);
    permutation(&A,&B);
    printf("Apree la permutation :\n");
    printf("A : %d\nB : %d",A,B); 
    return 0;
}
void permutation(int *num1, int *num2){
    int num3 = *num1;
    *num1 = *num2;
    *num2 = num3; 
}


