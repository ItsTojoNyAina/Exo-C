#include <stdio.h>
int prim(int n){
    if(n == 1) 
    return 1;
    else return n+prim(n-1);
}
int main(){
    int n;
    printf("entrer le nombre :\n");
    scanf("%d",&n);
    printf("\nla somme des nombres premiers de %d est: %d",n,prim(n));
}