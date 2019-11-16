#include <iostream>
#include <Windows.h>
#include "C:\cvm.h"

using namespace std;

const int MENU_ADD = 1, MENU_DELETE = 2, MENU_SHOW_ELEMENT = 3, MENU_QUIT = 4;

int showMenu();

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	int choice = 0;
	while (choice != MENU_QUIT) {
		//showStack(first);
		choice = showMenu();

		switch (choice) {
		case MENU_ADD:
			//Ajouter element liste chaine
			break;
		case MENU_DELETE:
			//Effacer element de liste a un index
			clrscr();
			break;
		case MENU_SHOW_ELEMENT:
			//Afficher element de la liste
			break;
		case MENU_QUIT:
			//Quitter
			break;
		}

	}
}

int showMenu() {
	int choice;
	cout << "A faire: Affichage de la liste au complet!\n\n";

	cout << endl << endl <<
		"Que voulez-vous faire?\n\n" <<
		"1 Ajouter un élément à la liste?\n" <<
		"2 Retirer un élément de la liste?\n" <<
		"3 Afficher un élément de la liste?\n" <<
		"4 Quitter?\n\n" <<
		"Il y a présentement N élément(s) dans la liste\n\n\n\n" <<
		"Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}