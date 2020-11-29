#include <stdio.h>
#include<stdlib.h>
#include "tab.h"
#define TAILLEINITIALE 100
#define TAILLEAJOUT 50


int main() {
	int myTab1[10] = { 0 };
	int* MyTab2=NULL;
	int TAB2SIZE = TAILLEINITIALE;
	int nelement = 20;
	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));/*allocation dynamique du tableau à la taille  TAB2SIZE*/
	if (MyTab2 != NULL)
	{
		initTab(MyTab2, TAB2SIZE);
     }
	else 
	{
		printf("memoire insuffisante");/*retourne -1 si l'allocation à echouer */
		return -1;

	}
	for (int j = 0; j < nelement; j++)
	{
		*(MyTab2 + j) = j + 1;/*Remplit les 20 premières valeurs du tableau avec les nombres de 1 à 20*/

	}


	afficheTab(MyTab2, TAB2SIZE, nelement);/* Affichez les 20 premières valeurs du tableau*/

	free(MyTab2);/*liberation du tableau*/
}

