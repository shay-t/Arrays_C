#include<stdio.h>
#include<stdlib.h>
//supprimer un element de la position i d'un tableau.
int* supprime(int*t,int i,int n){
	int j=0,l=0;
    int*tab=(int*)malloc((n-1)*sizeof(int*));
	for(j=0;j<=n-2;j++,l++){
		if(j!=i){
			*(tab+j)=*(t+l); /*retourner le tableau sans l'element i*/ 
		}
		else{
			*(tab+j)=*(t+l+1); /*i=j on translate a la case suivante pour écraser la valeur contenu*/
			l++;
		}
	}
	return tab;
	}
	
//affichage du tableau
void affichage(int*t,int n){
	for(int i=0;i<=n-1;i++){
		printf("la valeur de la position %d est %d \n",i,*(t+i));
	}
}
//inverser le contenu d'un tableau
int* inverse(int*t,int n){
	int *tab=(int*)malloc(n*sizeof(int*));
	for(int j=n-1,i=0;j<=0,i<=n-1;j--,i++){ //approche de youss
			*(tab+i)=*(t+j);	
		}
	return tab;
}
//fusionner deux tableaux triés de taille différente et resultat egalement trié
int* fusion(int*t1,int*t2,int n1,int n2){
	int *tab=(int*)malloc((n1+n2)*sizeof(int*));
	int i,j,aux;
	for( i=0;i<=n1;i++){
		*(tab+i)=*(t1+i);
	}
	for( j=0;j<=n2;j++){
		*(tab+j+n1)=*(t2+j);
	}
	i=0;
	j=0;
    while(i<(n1+n2)-1){
		j=(n1+n2)-1;
		while(j>i){
			if (tab[j]<tab[j-1])
			{
				aux=tab[j];
				tab[j]=tab[j-1];
				tab[j-1]=aux;
			}
		    j=j-1;
		}
		i=i+1;
	}
	return tab;
}
//creation de matrices avec des valeurs aléatoires
int** matrice_creation(int l,int c){
	int **mat=(int**)malloc(l*sizeof(int));
	for(int i=0;i<l;i++){
		mat[i]=(int*)malloc(c*sizeof(int));//une colone est un seul pointeur
		for(int j=0;j<c;j++){
			*(mat[i]+j)=rand()%100;
			
		}
	}
	return(mat);
}
//affichage de matrice
void matrice_affichage(int l,int c,int**mat){
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
		printf("%d |",*(mat[i]+j));
		}
		printf("\n");
	}
}
//addition de matrice
int** addition_matrice(int**mat1,int**mat2,int l,int c){
	int **mat=(int**)malloc(l*sizeof(int));
	for(int i=0;i<l;i++){
		mat[i]=(int*)malloc(c*sizeof(int));//une colone est un seul pointeur
        for(int j=0;j<c;j++){
        	*(mat[i]+j)=*(mat1[i]+j)+*(mat2[i]+j);
		}
	}
	return(mat);
	}
//Multiplication des matrices 
int**multiplication_matrice(int**mat1,int**mat2,int l1,int l2,int c1,int c2){
	if(c1!=l2)
		printf("erreur dimensions incompatibles");
	else{               
		int **mat=(int**)malloc(l1*sizeof(int));
        for(int i=0;i<l1;i++){
	
        	mat[i]=(int*)malloc(c2*sizeof(int));
        	for(int j=0;j<c2;j++){ 
        		*(mat[i]+j)=0;
        		for(int k=0;k<c1;k++){
        			*(mat[i]+j)=*(mat[i]+j)+(*(mat1[i]+k))*(*(mat2[k]+j));
				}
          }
		}
	return(mat);
	}
	
}

//fonction principale
int main(){
	int A[6]={1,-7,3,4,6,1};
	int *r;
	r=supprime(A,2,6);
	affichage(r,5);/*
	printf("inverse du contenu \n");
	r=inverse(A,6);
	affichage(r,6);
	printf("la fusion des parametres+tableau est trie\n");
	int K[3]={1,7,9};
	int D[5]={2,3,7,10,19};
	r=fusion(K,D,3,5);
	affichage(r,8);
	*/
	int **M,**m1,**m2;
	/*M=matrice_creation(3,4);
    matrice_affichage(3,4,M);
  m1=matrice_creation(2,2);
    m2=matrice_creation(2,2);
    M=addition_matrice(m1,m2,2,2);
	matrice_affichage(2,2,M);*/
	/*
	m1=matrice_creation(2,3);
    m2=matrice_creation(3,2);
    printf("matrice1\n");
    matrice_affichage(2,3,m1);
    printf("matrice2\n");
    matrice_affichage(3,2,m2);
    printf("matrice resultat \n");
    M=multiplication_matrice(m1,m2,2,3,3,2);
	matrice_affichage(2,2,M);
	*/
}
	
