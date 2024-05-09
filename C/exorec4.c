#include <stdio.h>

int pgcd(int a, int b){
    if (b==0) return a; 
    else return pgcd(b,a%b);
}
int main(){
    int a, b;
    printf("\nentrer : ");
    scanf("%d",&a);
    printf("entrer :");
    scanf("%d", &b);
    printf ("pgcd(%d,%d)= %d\n", a ,b  ,pgcd(a,b));
}