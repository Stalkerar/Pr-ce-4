/*
Část první:
Co je to dynamické programování ?
- Dynamické programování je metoda pro efektivní řešení určitých optimalizačních úloh. Lze jej použít pro řešení úloh, 
  které lze rozdělit na podúlohy, jejichž optimální řešení lze použít při řešení původní úlohy.
  Princip dynamického programování spočívá v rekurzivním dělení úlohy na menší části, které se řeší ve vhodném pořadí, 
  jejich výsledky se zaznamenávají a jsou použity pro řešení složitějších podúloh včetně původní úlohy.

Optimální binární vyhledávací strom:
- Lze aplikovat pokud víme, že se neplánují změny vyhledávacího stromu a přesně víme, 
  jak často bude ke každému uzlu přistupováno. I v případě, že známe jen odhad ceny vyhledávání, 
  může takový systém v průměru podstatně zrychlit vyhledání. Například pokud máme BST českých slov použitých v 
  korektoru chyb, je možné vyvážit strom podle frekvence použití slov v textu přemístěním slov jako jsou „a“ a „nebo“ 
  blíže ke kořeni a slova jako „chřástal“ k listům.
*/
// Část druhá:
#include <iostream>
#include <stdio.h>

using namespace std;

// Počet vrcholů v grafu  
#define V 4  
/*
Definice Inf jako velkou hodnotu,
která bude představovat, že vrcholy nejsou spojené.
*/
#define INF 99999

// Funkce pro tisk řešení
void printSolution(int dist[][V])
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				cout << "INF" << "     ";
			else
				cout << dist[i][j] << "     ";
		}
		cout << endl;
	}
}

// Imlementace Floydova–Warshallova algoritmu
void floydWarshall(int graph[][V])
{
	/*
	Funkce na výstupu ukáže nejkratší vzdálenost mezi, každým
	párem vrcholů.
	*/
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];
		}
	}

	/* Přidání všech vrcholů do
	pole mezilehlých vrcholů.
	---> Před startem iterace,
	máme nejkratší vzdálenost mezi všemi
	páry vrcholů, jako nejkratší vzdálenost
	se považuje pouze vrchol v poli {0, 1, 2, .. k-1}
	jako mezilehlý vrchol
	*/
	for (k = 0; k < V; k++)
	{ 
		for (i = 0; i < V; i++)
		{
			// Vyjmutí vrcholů jako destinaci pro výše vybrané vstupy
			for (j = 0; j < V; j++)
			{
				// Pokud vrchol 'k' je na nejkratší cestě 'i' ke 'j'  
				// potom uprvím hodnotu dist[i][j]  
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

int main()
{
	// Vstupní graf je vyvážený
	int graph[V][V] = { {0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
	};

	// Původní matice
	printSolution(graph);
	putchar('\n');
	putchar('\n');
	// Tisk řešení
	floydWarshall(graph);

	return 0;
}

