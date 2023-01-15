#include<stdio.h>
#include<stdlib.h>
//procedure insere
void insert(int Nb_max,int n,int i, int m,int*t){
	int j;
	for(j=n;j>i;j--){ //j=n car on ajoute 1case de tableau
        *(t+j)=*(t+(j-1));	    
	}
	*(t+i)=m;
	for(j=0;j<=n;j++){ //affichage du tbleau
		printf("%d \t",*(t+j));
	}
}

int main(){
	int tab[5]={1,12,5,66,3};
	insert(6,5,1,5,tab);
}
