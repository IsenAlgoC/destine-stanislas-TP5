#include <stdio.h>
#include<stdlib.h>
#define TAILLEINITIALE 100
#include "tab.h"

int main() {
	int noctetajout;/*nombre d'octet à ajouter*/
	int pos;/*position de l'élément à inserer*/
	int element;/*element à insérer*/
	int startpos, endpos;/* intervalle à sélectionner pour l'affichage       */
	int startpos2, endpos2;/* intervalle selectionner pour la compression*/
	
	TABLEAU tableau = newArray();/*création d'un nouveau TABLEAU en allouant une taille initiale pour les données.*/
	printf("combien d'octet voulez vous ajouter :");
	scanf_s("%d", &noctetajout);
    incrementArraySize(&tableau,noctetajout);/*modifie la taille du tableau on ajoutant noctectajout  */
	printf("entrer la position pos et l'element element \n"); 
	scanf_s("%i %i", &pos, &element);/* l'utilisateur entre la position et la valeur de l'element ajouter                     */
	setElement(&tableau, pos, element);/*insère l'element à la position pos*/
	printf("choisissez l'intervalle [startpos , endpos] à afficher ");
	scanf_s("%d %d", &startpos, &endpos);/*l'utilisateur entre l'intervalle du tableau à afficher */
	displayElements(&tableau, startpos, endpos);/* affiche le tableau selon l'intervalle selectionné */
	printf("l'ancienne taille du tableau est %d ", tableau.size);
	printf("donner l'intervalle à supprimmer [startpos2 , endpos2]  ");
	scanf_s("%d %d", &startpos2, &endpos2);/*l'utilisateur entre l'intervalle du tableau à supprimer */
	printf("la nouvelle taille du tableau est %d",deleteElements(&tableau,startpos2,endpos2));
	return 0;
	



   




}