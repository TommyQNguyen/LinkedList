#include <iostream>
#include <Windows.h>
#include "C:\cvm.h"

using namespace std;

//Global variables
const int MENU_ADD = 1, MENU_DELETE = 2, MENU_SHOW_ELEMENT = 3, MENU_QUIT = 4;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;

//Function prototypes
int showMenu();
void createFirstNode(int value);
void showNodeList();
void insertNodeAtBeginning(int value);
void insertNodeAtEnd(int value);
void insertNodeAtGivenPosition(int position, int value);


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

	cout <<
		"Que voulez-vous faire?\n\n" <<
		"1 Ajouter un element à la liste?\n" <<
		"2 Retirer un element de la liste?\n" <<
		"3 Afficher un element de la liste?\n" <<
		"4 Quitter?\n\n\n" <<
		"Il y a présentement N element(s) dans la liste\n\n\n\n" <<
		"Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}


void createFirstNode(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next;
		tail = temp;
	}
}

void showNodeList()
{
	Node* temp = head;

	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}

void insertNodeAtBeginning(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

void insertNodeAtEnd(int value)
{
	createFirstNode(value);
}

void insertNodeAtGivenPosition(int position, int value)
{
	Node* temp = new Node;
	Node* previous = new Node;
	Node* current = head;

	for (int i = 0; i < position; i++)
	{
		previous = current;
		current = current->next;
	}

	temp->data = value;
	previous->next = temp;
	temp->next = current;
}