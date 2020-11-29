#define TAILLEAJOUT 50

int initTab(int* tab, int size)/*fonction qui remplit un tableau d’entiers de taille size avec des zéros*/
{
	if (tab == 0 || size < 0)/*Valeur de retour : -1 si tab est un pointeur NULL ou size < 0*/
	{
		return -1;
	}
	for (int i = 0; i < size; i++) {
		*(tab + i) = 0;
	}
	return size;
}


int afficheTab(int* tab, int size, int nbElts) /*fonction qui affiche les nbElts premièrs éléments du tableau tab s*/
{
	if (tab == 0 || size < 0 || size < nbElts) {
		return -1;
	}
	for (int i = 0; i < nbElts;i++)
	{
		printf(" | %d |",*(tab + i));

	}
	printf("\n");
	return 0;
	
	
}


int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) 
{
	if (*nbElts >= *size)/*Si le tableau est trop petit, il doit être agrandi de TAILLEAJOUT éléments.*/ 
	{
		int* tmp;
		tmp= (int*)realloc(tab,((TAILLEAJOUT+(*size ))* sizeof(int)));
		if (tmp == 0)
		{ return NULL; }
		tab = tmp;
		*(tab + *nbElts) = element;
		*nbElts += 1;
		*size += TAILLEAJOUT;
	}
	*(tab + *nbElts) = element;/* ajout d' un nombre entier à la suite des valeurs déjà entrées et met à jour le nombre
d'éléments stockés ainsi que la capacité réelle du tableau*/
	*nbElts += 1;
	*size += TAILLEAJOUT;
	return tab + *(nbElts);

}

