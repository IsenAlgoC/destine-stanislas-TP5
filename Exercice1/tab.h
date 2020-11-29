#define TAILLEAJOUT 50

int initTab(int* tab, int size)/*fonction qui remplit un tableau d�entiers de taille size avec des z�ros*/
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


int afficheTab(int* tab, int size, int nbElts) /*fonction qui affiche les nbElts premi�rs �l�ments du tableau tab s*/
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
	if (*nbElts >= *size)/*Si le tableau est trop petit, il doit �tre agrandi de TAILLEAJOUT �l�ments.*/ 
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
	*(tab + *nbElts) = element;/* ajout d' un nombre entier � la suite des valeurs d�j� entr�es et met � jour le nombre
d'�l�ments stock�s ainsi que la capacit� r�elle du tableau*/
	*nbElts += 1;
	*size += TAILLEAJOUT;
	return tab + *(nbElts);

}

