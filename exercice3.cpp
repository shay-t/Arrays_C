#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//methode récursive
int suiter(int n){
	if(n==0){
		return 1;
	}else{
		return 3*pow(suiter(n-1),2)+2*suiter(n-1)+1;
	}
}

//methode en utilisant un tableau
int*suite(int n){
	int *tab=(int*)malloc((n+1)*sizeof(int));
	*(tab)=1;
	for(int i=1;i<=n;i++){
		*(tab+i)=3*pow(*(tab+(i-1)),2)+2*(*(tab+(i-1)))+1;
	}
return tab;
}
//affichage du tableau
void affichage(int*t,int n){
	for(int i=0;i<=n-1;i++){
		printf("la contenu %d  de la suite est %d \n",i,*(t+i));
	}
}
//fonction principale
int main(){
	int *tab;
    tab=suite(6);
	affichage(tab,6);
}
	//for(int i=0;i<5;i++){
		//printf("\n %d",suiter(i));	
	//}
  	
