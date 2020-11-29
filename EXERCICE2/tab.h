
typedef struct Tableau {
	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau
} TABLEAU;




TABLEAU newArray() /* creation de la fonction new array*/
{
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));/*allocation d'une memoire de  TAILLEINITIALE case de sizeof(int ) octet            */
	if (tab.elt == NULL)/*si l'allocation � �chouer*/ {
		return tab;
	}
	for (int i = 0; i < TAILLEINITIALE; i++)
	{
		*((tab.elt) + i) = 0;/* Le tableau elt sera initialis� avec des z�ros*/
	}
	tab.eltsCount = 0;/*champ eltsCount initialis� � z�ro*/
	tab.size = TAILLEINITIALE;/* Taille initialle affect� � size   */
	return tab;
}

int incrementArraySize(TABLEAU* tab, int  incrementValue)
{
	int* tmp;
	tmp = (int*)realloc((*tab).elt, ((*tab).size+ incrementValue) * sizeof(int));/* on assigne le r�sultat de la fonction de r�allocation � un temporaire, puis on remplace le pointeur d�origine apr�s une r�allocation r�ussie.*/
	if (tmp == 0)
	{
		return -1;/* renvoie -1 si erreur */
	}
	(*tab).elt = tmp;
	(*tab).size += incrementValue;/*calcul de la nouvelle taille*/
	return (*tab).size;/*renvoie la nouvelle taille*/

}


int setElement(TABLEAU *tab, int pos, int element)/*Ecrit un �l�ment � une position donn�e sans insertion*/
{
	if (pos <= 0)/* si la position entr�e est n�gative  on renvoie zero car c'est une erreur*/
		return 0;
	if ((tab->size)<=pos)/*si la position entr�e est sup�rieur ou �gal � la taille du tableau*/
	{
		incrementArraySize(tab, pos - tab->size );/*on augmente la taille du tableau de pos -tab */
		for (int i = tab->size; i < pos - tab->size; i++)
		{
			*((tab->elt) + i) = 0;/*on rempli � zero les cases interm�diares*/
		}
           *((tab->elt) + pos - 1) = element;/* �criture de l'element � pos-1 du tableau*/
		   return ((tab->elt) + pos - 1) ;/*retour du pointeur pointant sur la case �crite*/

    }
	*((tab->elt) + pos - 1) = element;
	return ((tab->elt) + pos - 1) ;
}


int displayElements(TABLEAU* tab, int startPos, int endPos)/*Affiche une portion du tableau de l�indice d�but � l�indice fin*/
{
	if ((tab->elt) == NULL || startPos >=(tab->size) || endPos>=(tab->size) || startPos <0 || endPos >= (tab->size)<0)/*conditions d'erreur*/
	{
		return -1;
	}
	if (startPos >= endPos)/*si la fin est sup�tieur au d�but on echange*/
	{
		int tmp= startPos ;
		startPos = endPos ;
		endPos = tmp;

	}
	for (int i = startPos; i <= endPos; i++)/*boucle d'affichage du tableau*/
	{
		printf("|%d|", *((tab->elt) + i));

	}
	printf("\n");
	return 0;
}



int deleteElements(TABLEAU* tab, int startPos, int endPos) 
{
	    int j = 0; /*  indice du nouveau tableau*/
		int* ntab = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int));/* allocation de la memoire restreinte dans le nouveau tableau */
		if (ntab == NULL)
		{ return(-1); }
		for (int i = 0; i <= tab->size - 1; i++) {
			if ((i < startPos) || (i > endPos)) {
				*(ntab + j) = *(tab->elt + i);  /*on copie chaque element du tableau dans la copie lorsque son indice correspond aux conditions */
				j++;/*quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et � mesure*/
			}
		}
		tab->size -= (endPos - startPos) + 1;
		tab->eltsCount -= (endPos - startPos) + 1;
		tab->elt = ntab;
		return(tab->size);
	



}
