#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*multichar(char*s,int n){
	int l=strlen(s);
	char *c=(char*)malloc((l*n)*sizeof(char));
	int aux,k,j;
	//on renverse la chaine 
	for(int i=0;i<l/2;i++){
	 	 aux=*(s+i);
	 	*(s+i)=*(s+l-1-i);
	 	*(s+l-1-i)=aux;
	}
	//la repetition des lettres 
	for(int i=0,j=0;i<l,j<l*n;i++,j=j+n){
		for(k=0;k<n;k++){
			*(c+j+k)=*(s+i);
		}
	}
	return c;

}
//affichage de la chaine
void affichage(char*t){
	int n=strlen(t);
	for(int i=0;i<=n-1;i++){
		printf("%c",*(t+i));
	}
}
//fonction principale
int main(){
	char a[10]="ENSA";
	char*b;
	b=multichar(a,3);
    affichage(b);		
}
