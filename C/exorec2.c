#include <stdio.h>
int puiss(int x,int n){
    if (n==0)
    return 1;
    else 
    return x*puiss(x,n-1);
}
int main(){
    int x,n;
    printf("entrer le nombre:");
    scanf("%d",&x);
    printf("\nnentrez la puissance:");
    scanf("%d",&n);
    printf("le résultat de %d à la puissance %d est :%d",x,n,puiss(x,n));
}