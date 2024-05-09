#include <stdio.h>
int combi(int n, int p){
    if (p == 0 || p==n) 
    return 1;
    else 
    return combi(n-1,p-1)+combi(n-1,p);
}
int main(){

    int p,n;
    printf("\nentrer le nombre:");
    scanf("%d",&n);
    printf("\nnentrez le nombre d'elements:");
    scanf("%d",&p);
    printf("le résultat de %d elements parmis %d est :%d",p,n,combi(n,p));
}