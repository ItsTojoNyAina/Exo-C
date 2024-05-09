#include <stdio.h>
int factorielle(int n){
    if (n==0) 
    return 1;
    else
    return n*factorielle(n-1);
}
int main(){
    int n;
    printf("entrer le nombre:");
    scanf("%d",&n);
    printf ("la factoirelle de %d est :%d",n,factorielle(n));
}