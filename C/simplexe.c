#include<Stdio.h>
float A[20][20];
int Base[20];
int hors_base[20];
float b[20];
float c[20];
//int cb[20],cn[20];
int out,c_out,c_in;
int nbr_elm_base=1,nbr_elm_hors_base=1;


//-----------------------------------------------------------------------//
void creation_matrice_A(int nbr_contrainte,int nbr_variable){
    for(int i=1;i<=nbr_contrainte;i++){
        int k=1;
        for(int j=1;j<=nbr_variable+nbr_contrainte;j++){
            if(j<=nbr_variable){
                printf("a[%d][%d]= ",i,j);
                scanf("%f",&A[i][j]);
            }
            else{
              if(k==i)
                 A[i][j]=1;
              else
                 A[i][j]=0;
              k++;
            }
        }
    }
}
//-----------------------------------------------------------------------//
void Afficher_contrainte(int nbr_contrainte,int nbr_variable){
    for(int i=1;i<=nbr_contrainte;i++){
        for(int j=1;j<=nbr_variable;j++){
            printf("%.1f\t",A[i][j]);
        }
        printf("\n\n");
    }
}
//-----------------------------------------------------------------------//
void Afficher_matrice_A(int nbr_contrainte,int nbr_variable){
    for(int i=1;i<=nbr_variable+nbr_contrainte;i++){
        printf("%.1f\t",c[i]);
    }
    printf("\n\n");
    for(int i=1;i<=nbr_contrainte;i++){
        for(int j=1;j<=nbr_variable+nbr_contrainte;j++){
            printf("%.1f\t",A[i][j]);
        }
        printf("%.1f",b[i]);
        printf("\n\n");
    }
}
//-----------------------------------------------------------------------//
void init_coefficient(int nbr_contrainte,int nbr_variable){
    for(int i=1;i<=nbr_variable;i++){
            printf("c[%d]= ",i);
            scanf("%f",&c[i]);
    }
    for(int i=nbr_contrainte;i<=nbr_contrainte+nbr_variable;i++){
        c[i]=0;
    }
}
//-----------------------------------------------------------------------//
void Afficher_coef(int nbr_contrainte,int nbr_variable){
    printf("z=");
    for(int i=1;i<=nbr_variable+nbr_contrainte;i++){
        if(i!=nbr_variable+nbr_contrainte){
            printf(" %.1fx%d + ",c[i],i);
        }
        else printf("%.1fx%d",c[i],i);
    }
}
//-----------------------------------------------------------------------//
void init_base(int nbr_contrainte,int nbr_variable){
    for(int i=1;i<=nbr_contrainte+nbr_variable;i++){
            if(i<nbr_contrainte){
                hors_base[nbr_elm_hors_base]=i;
                nbr_elm_hors_base++;
            }
            else{
                Base[nbr_elm_base]=i;
                nbr_elm_base++;
            }
    }
}
//-----------------------------------------------------------------------//
void Afficher_base(int nbr_contrainte,int nbr_variable){
    for(int i=1;i<nbr_elm_base;i++){
        printf("%.1f\t",c[Base[i]]);
    }
    printf("\n\n");
    for(int i=1;i<=nbr_contrainte;i++){
        for(int j=1;j<nbr_elm_base;j++){
            printf("%.1f\t",A[i][Base[j]]);
        }
        printf("\n\n");
    }
}
//-----------------------------------------------------------------------//
void  init_matrice_b(int nbr_contrainte){
    for(int i=1;i<=nbr_contrainte;i++){
        printf("b[%d]=",i);
        scanf("%f",&b[i]);
    }
}

//-----------------------------------------------------------------------//
void  Afficher_matrice_b(int nbr_contrainte){
    for(int i=1;i<=nbr_contrainte;i++){
        printf("b[%d]= %.1f\t",i,b[i]);
    }
}

//-----------------------------------------------------------------------//
int Qui_entre(int nbr_variable){
    for(int i=1;i<=nbr_variable;i++){
        if(c[hors_base[i]]<0){
            c_in=i;
            return hors_base[i];
        }
    }
    return 0; // 0:fin du programme
}
//-----------------------------------------------------------------------//
int Qui_sort(int nbr_contrainte,int s){
    float Min;
    int j=1;
    for(int i=1;i<=nbr_contrainte;i++){
        if(A[i][s]<0)
            continue;
        else{
            if(j==1){
                Min=b[i]/A[i][s];
                out=Base[i];
                c_out=i;
                j++;
            }
            else if(Min>b[i]/A[i][s]){
                Min=b[i]/A[i][s];
                out=Base[i];
                c_out=i;
                j++;
            }
        }
    }
    return Min;
}
//-----------------------------------------------------------------------//
void echange(int *a,int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
//-----------------------------------------------------------------------//
void Pivot_de_Gauss(int nbr_contrainte,int nbr_variable,int pivot){
    float scalaire;
    scalaire=1/A[pivot][Base[pivot]];
    printf("Scalaire_pivot: %.1f\n\n",scalaire);
    //pour la ligne pivot
    for(int i=1;i<=nbr_contrainte+nbr_variable;i++){
        A[pivot][i]=(A[pivot][i])*scalaire;
    }
    float tmp=b[pivot];
    b[pivot]=b[pivot]*scalaire;


    //pour les autres lignes
    for(int i=1;i<=nbr_contrainte;i++){
        if(i!=pivot){
            scalaire=A[i][Base[pivot]]/A[pivot][Base[pivot]];
            b[i]=b[i]-scalaire*tmp;
            for(int j=1;j<=nbr_contrainte+nbr_variable;j++){
                A[i][j]=A[i][j]-scalaire*A[pivot][j];
            }
        }
    }
    scalaire=c[Base[pivot]]/A[pivot][Base[pivot]];
    for(int i=1;i<=nbr_contrainte+nbr_variable;i++){
        c[i]=c[i]-scalaire*A[pivot][i];
    }
}
//-----------------------------------------------------------------------//

int main(){
    int nbr_contrainte,nbr_variable;
    int encore=1;
    printf("Entrer le nombre de contrainte:");
    scanf("%d",&nbr_contrainte);
    printf("Entrer le nombre de variable:");
    scanf("%d",&nbr_variable);


    init_coefficient(nbr_contrainte,nbr_variable);
    creation_matrice_A(nbr_contrainte,nbr_variable);
    init_matrice_b(nbr_contrainte);
    init_base(nbr_contrainte,nbr_variable);

    Afficher_matrice_A(nbr_contrainte,nbr_variable);
    printf("\n\n");
    while(encore){
        int s=Qui_entre(nbr_variable);
        if(s!=0){
            printf("la colone %d entre dans la base\n",s);
            int min=Qui_sort(nbr_contrainte,s);

            printf("Min= %d\n",min);
            printf("la colone %d sort de la base\n",out);
            printf("Pivot : L%d\n",c_out);
            echange(&hors_base[c_in],&Base[c_out]);
            Pivot_de_Gauss(nbr_contrainte,nbr_variable,c_out);
            Afficher_matrice_A(nbr_contrainte,nbr_variable);
            printf("\n\n");
        }
        encore=s;

    }


    //Afficher_coef(nbr_contrainte,nbr_variable);
    //Afficher_contrainte(nbr_contrainte,nbr_variable);
    //Afficher_matrice_A(nbr_contrainte,nbr_variable);
    //Afficher_base(nbr_contrainte,nbr_variable);

    return 0;
}


