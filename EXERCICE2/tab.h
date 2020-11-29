
typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;




TABLEAU newArray() /* creation de la fonction new array*/
{
	TABLEAU tab;
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));/*allocation d'une memoire de  TAILLEINITIALE case de sizeof(int ) octet            */
	if (tab.elt == NULL)/*si l'allocation à échouer*/ {
		return tab;
	}
	for (int i = 0; i < TAILLEINITIALE; i++)
	{
		*((tab.elt) + i) = 0;/* Le tableau elt sera initialisé avec des zéros*/
	}
	tab.eltsCount = 0;/*champ eltsCount initialisé à zéro*/
	tab.size = TAILLEINITIALE;/* Taille initialle affecté à size   */
	return tab;
}

int incrementArraySize(TABLEAU* tab, int  incrementValue)
{
	int* tmp;
	tmp = (int*)realloc((*tab).elt, ((*tab).size+ incrementValue) * sizeof(int));/* on assigne le résultat de la fonction de réallocation à un temporaire, puis on remplace le pointeur d’origine après une réallocation réussie.*/
	if (tmp == 0)
	{
		return -1;/* renvoie -1 si erreur */
	}
	(*tab).elt = tmp;
	(*tab).size += incrementValue;/*calcul de la nouvelle taille*/
	return (*tab).size;/*renvoie la nouvelle taille*/

}


int setElement(TABLEAU *tab, int pos, int element)/*Ecrit un élément à une position donnée sans insertion*/
{
	if (pos <= 0)/* si la position entrée est négative  on renvoie zero car c'est une erreur*/
		return 0;
	if ((tab->size)<=pos)/*si la position entrée est supérieur ou égal à la taille du tableau*/
	{
		incrementArraySize(tab, pos - tab->size );/*on augmente la taille du tableau de pos -tab */
		for (int i = tab->size; i < pos - tab->size; i++)
		{
			*((tab->elt) + i) = 0;/*on rempli à zero les cases intermédiares*/
		}
           *((tab->elt) + pos - 1) = element;/* écriture de l'element à pos-1 du tableau*/
		   return ((tab->elt) + pos - 1) ;/*retour du pointeur pointant sur la case écrite*/

    }
	*((tab->elt) + pos - 1) = element;
	return ((tab->elt) + pos - 1) ;
}


int displayElements(TABLEAU* tab, int startPos, int endPos)/*Affiche une portion du tableau de l’indice début à l’indice fin*/
{
	if ((tab->elt) == NULL || startPos >=(tab->size) || endPos>=(tab->size) || startPos <0 || endPos >= (tab->size)<0)/*conditions d'erreur*/
	{
		return -1;
	}
	if (startPos >= endPos)/*si la fin est supétieur au début on echange*/
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
				j++;/*quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et à mesure*/
			}
		}
		tab->size -= (endPos - startPos) + 1;
		tab->eltsCount -= (endPos - startPos) + 1;
		tab->elt = ntab;
		return(tab->size);
	



}
