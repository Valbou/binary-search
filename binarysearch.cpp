# include <iostream>

using namespace std;

void afficheTableau(int taille, int tab[])
{
	// AFfiche les elements du tableau separes par des espaces
	for (size_t i = 0; i < taille; ++i)
	{
		cout << i << " -> " << tab[i] << endl;
	}
}

int recherche_dichotomique(int i_min, int i_max, int &iter, int &recherche, int tab[])
{
    int ecart = i_max - i_min;
    int index = i_min + (ecart/2);
    if(tab[index] < recherche)
    {
        index = recherche_dichotomique(index, i_max, iter, recherche, tab);
    }
    else if(recherche < tab[index])
    {
        index = recherche_dichotomique(i_min, index, iter, recherche, tab);
    }

    ++iter;
    return index;
}

main()
{
    // Algorithme intervenant sur un tableau prealablement trie
    int tab[40] = { -99,-89,-36,-23,-17,-10,-8,-3,-2,1,2,2,4,5,5,6,8,9,10,12,14,15,18,20,20,21,45,54,63,65,74,77,82,97,98,100,125,134,165,185 }; // Tableau a trier
	int taille = 40;
	int nbIter = 0; // Nombre d'itérations realisees
    int recherche = 54;
    int position = -1;

    cout << "--- Binary Search ---" << endl << endl << "Tableau d'origine " << taille << " :" << endl;
	afficheTableau(taille, tab);

    position = recherche_dichotomique(0, taille-1, nbIter, recherche, tab);

    cout << endl << "Nombre : " << recherche << " trouve apres " << nbIter << " iterations en position : " << position << endl;

    // La pause est necessaire pour voir le resultat sous Windows avant la fermeture de la console
	system("pause");
    return 0;
}
