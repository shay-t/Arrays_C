#include<stdio.h>
#include<stdlib.h>

//fonction remplissage random 
int* remplissage_random(int n){
	int *t;
	t=(int*)malloc(n*sizeof(int*));
	int i;
	for(i=0;i<=n-1;i++){
	*(t+i)=rand();
	}
	return t;}
//remplissage tableau  
int* remplissage_tableau(int n){
	int *t;
	int i;
	t=(int*)malloc(n*sizeof(int*));
	for(i=0;i<=n-1;i++){
		printf("veuillez saisir l'element %d \n",i+1);
		scanf("%d",(t+i));
	}
	return t;
}	
//affichage du tableau
void affichage(int*t,int n){
	int i;
	for(i=0;i<=n-1;i++){
		printf("la valeur de la position %d est %d \n",i,*(t+i));
	}
}

//supprimer un element de la position i d'un tableau.
int* supprime(int*t,int i,int n){
	int j=0,l=0;
    int*tab=(int*)malloc((n-1)*sizeof(int));
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
//inverser le contenu d'un tableau
int* inverse(int*t,int n){
	int *tab=(int*)malloc(n*sizeof(int*));
	int i,j;
	for(j=n-1,i=0;j<=0,i<=n-1;j--,i++){ 
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
	return tab;}
//creation de matrice par des valeurs:
int** matrice_valeurs(int l,int c){
	int **mat=(int**)malloc(l*sizeof(int));
	int i,j;
	for(i=0;i<l;i++){
	    mat[i]=(int*)malloc(c*sizeof(int));//une colone est un seul pointeur
		for(j=0;j<c;j++){
		 printf("veuillez saisir l'element [%d] [%d] \n",i,j);
		  scanf("%d",(mat[i]+j));
		 }
	}
	return (mat);
}
//creation de matrices avec des valeurs aléatoires
int** matrice_creation(int l,int c){
	int **mat=(int**)malloc(l*sizeof(int));
	int i,j;
	for(i=0;i<l;i++){
		mat[i]=(int*)malloc(c*sizeof(int));//une colone est un seul pointeur
		for(j=0;j<c;j++){
			*(mat[i]+j)=rand()%100;	
		}
	}
	return(mat);
}
//affichage de matrice
void matrice_affichage(int l,int c,int**mat){
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
		printf("%d |",*(mat[i]+j));
		}
		printf("\n");
	}
}
//addition de matrice
int** addition_matrice(int**mat1,int**mat2,int l,int c){
	int **mat=(int**)malloc(l*sizeof(int));
	int i,j;
	for(i=0;i<l;i++){
		mat[i]=(int*)malloc(c*sizeof(int));//une colone est un seul pointeur
        for(j=0;j<c;j++){
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
		int i,j,k;
        for(i=0;i<l1;i++){
        	mat[i]=(int*)malloc(c2*sizeof(int));
        	for(j=0;j<c2;j++){ 
        		*(mat[i]+j)=0;
        		for(k=0;k<c1;k++){
        			*(mat[i]+j)=*(mat[i]+j)+(*(mat1[i]+k))*(*(mat2[k]+j));
				}
          }
		}
	return(mat);
	}	
}
//menu
int menu(){
	printf("\n 0-sortir\n");
	printf("\n 1-Supprimer un element de la position i d'un tableau\n");
	printf("\n 2-Inverser le contenu d'un tableau \n");
	printf("\n 3-Fusionner deux tableaux tries de taille differente\n");
	printf("\n 4-Creer une matrice avec des valeurs aleatoires\n");
	printf("\n 5-Afficher le contenu de la matrice\n");
	printf("\n 6-Additionner deux matrices m1 et m2\n");
	printf("\n 7-Multiplier deux matrices m1 et m2 \n");
	int choix;
	scanf("%d",&choix);
	printf("\n");
	return choix;
}
//fonction principale
int main(){
	int test=1;
	while(test){
		switch(menu()){
			case 0:{ test=0; break;}
			case 1:{  int n;
			          printf("Donnez la taille du tableau \n");
			          scanf("%d",&n);
			          printf("\n voici le contenu de ce tableau remplis aleatoirement \n");
			          int*A=remplissage_random(n);
			          affichage(A,n);
			          int i;
			          printf("saisisez la position dont vous souhaitez supprimer lelement\n");
			          scanf("%d",&i);
			          int*tab=supprime(A,i,n);
			          printf("voici le tableau apres suppresion\n");
			          int k=n-1;
			          affichage(tab,k); 
					  break;
					}
			case 2:{  int n;
			          printf("Donnez la taille du tableau \n");
			          scanf("%d",&n);
			          printf("\n voici le contenu de ce tableau remplis aleatoirement \n");
			          int*A=remplissage_random(n);
			          affichage(A,n);
			          printf("voici le tableau inverse\n");
			          int*tab=inverse(A,n);
			          affichage(tab,n);
			          break;
					}
			case 3:{ int n1,n2;
			        printf("Donnez la taille du 1er tableau");
			        scanf("%d",&n1);
			        printf("Veuillez remplir le 1er tableau d'une facon trie");
			        int*tab1=remplissage_tableau(n1);
			        printf("Donnez la taille du 2er tableau");
			        scanf("%d",&n2);
                 	printf("Veuillez remplir le 2eme tableau d'une facon trie");
                    int*tab2=remplissage_tableau(n2);
                 	int*tab=fusion(tab1,tab2,n1,n2);
                 	affichage(tab,n1+n2);
			              break;}
			case 4:{ 
			         int l,c;
			         printf("veuillez saisir le nombre de lignes");
			         scanf("%d",&l);
			         printf("veuillez saisir le nombre de colones");
			         scanf("%d",&c);
			         printf("voici la valeur d'une matrice aleatoire\n");
			         int**M=matrice_creation(l,c);
			         matrice_affichage(l,c,M);
			         break;}
			case 5:{ int l,c;
			         printf("veuillez saisir le nombre de lignes");
			         scanf("%d",&l);
			         printf("veuillez saisir le nombre de colones");
			         scanf("%d",&c);
			         int**mat=matrice_valeurs(l,c);
			         matrice_affichage(l,c,mat);
					}
			case 6:{  int l,c;
			         printf("veuillez saisir le nombre de lignes de la matrice1");
			         scanf("%d",&l);
			         printf("veuillez saisir le nombre de colones de la matrice1");
			         scanf("%d",&c);
			         printf("voici la valeur d'une matrice 1 aleatoire\n");
			         int**M1=matrice_creation(l,c);
			         matrice_affichage(l,c,M1);
			         printf("/n");
			         printf("voici la valeur d'une matrice 2 aleatoire\n");
			         int**M2=matrice_creation(l,c);
			         matrice_affichage(l,c,M2);
			         printf("voici la matrice résultante\n");
			         int**M3=addition_matrice(M1,M2,l,c);
			         matrice_affichage(l,c,M3);
			         break;}
			case 7:{ 
			         int l1,l2,c1,c2;
			         printf("veuillez saisir le nombre de lignes de la matrice1\t");
			         scanf("%d",&l1);
			         printf("veuillez saisir le nombre de colones de la matrice1\t");
			         scanf("%d",&c1);
			         printf("veuillez saisir le nombre de lignes de la matrice2\t");
			         scanf("%d",&l2);
			         printf("veuillez saisir le nombre de colones de la matrice2\t");
			         scanf("%d",&c2);
			         printf("voici la valeur d'une matrice 1 aleatoire\n");
			         int**M1=matrice_creation(l1,c1);
			         matrice_affichage(l1,c1,M1);
			         printf("voici la valeur d'une matrice 2 aleatoire\n");
			         int**M2=matrice_creation(l2,c2);
			         matrice_affichage(l2,c2,M2);
			         printf("voici la matrice resultante\n");
			         int**M3=multiplication_matrice(M1,M2,l1,l2,c1,c2);
			         matrice_affichage(l1,c2,M3);
			        break;}
		}}}

