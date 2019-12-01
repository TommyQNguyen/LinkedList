#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "C:\cvm.h"

using namespace std;

//Global variables
const int MENU_ADD = 1, MENU_DELETE = 2, MENU_SHOW_ELEMENT = 3, MENU_QUIT = 4;

int sizeOfLinkedList = 0;

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
void recursiveShowNodeList(Node* nodePointer);
void showNodeAt(int position);
void recursiveShowNodeAt(Node* nodePointer, int position);
void insertNodeAtBeginning(int value);
void insertNodeAtEnd(int value);
void insertNodeAtGivenPosition(int position, int value);
void deleteFirstNode();
void deleteLastNode();
void deleteNodeAtGivenPosition(int pos);
void menu_ADD();
void menu_DELETE();
void menu_SHOW_NODE();


void init();


int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	init();

	int choice = 0;
	while (choice != MENU_QUIT) {
		choice = showMenu();

		switch (choice) {
		case MENU_ADD:
			menu_ADD();
			break;
		case MENU_DELETE:
			menu_DELETE();
			break;
		case MENU_SHOW_ELEMENT:
			menu_SHOW_NODE();
			break;
		case MENU_QUIT:
			break;
		}
	}
}

int showMenu() {
	int choice;
	recursiveShowNodeList(head);

	cout << "\n\n" <<
		"Que voulez-vous faire?\n\n" <<
		"1 Ajouter un element à la liste?\n" <<
		"2 Retirer un element de la liste?\n" <<
		"3 Afficher un element de la liste?\n" <<
		"4 Quitter?\n\n\n" <<
		"Il y a présentement " << sizeOfLinkedList << " element(s) dans la liste\n\n\n\n" <<
		"Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}

void createFirstNode(int value)
{
	Node* temp = new Node;	//Creation du pointeur de type Node appele temp 
	temp->data = value;		//Attribue au noeud pointe par temp la valeur donnee
	temp->next = NULL;		//Attribue au pointeur du noeud pointe par temp la valeur de rien

	if (head == NULL)		//Si le pointeur tete pointe vers rien (Liste n'est pas encore cree)
	{
		head = temp;		//Le pointeur tete pointe vers ce que le pointeur temporaire
		tail = temp;		//Le pointeur queue pointe vers ce que pointe la valeur temporaire
		temp = NULL;		//Le pointeur temp pointe vers rien 
	}
	else
	{
		tail->next = temp;	//Le noeud pointe par le pointeur queue, son pointeur a lui pointe vers ce que temp pointe	
		tail = temp;		//Pointeur queue pointe vers ce que pointeur temp pointe
	}
	sizeOfLinkedList++;
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

void recursiveShowNodeList(Node* nodePointer)
{
	if (nodePointer == NULL)
		return;

	cout << nodePointer->data << "\t";
	recursiveShowNodeList(nodePointer->next);
}

void insertNodeAtBeginning(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = head;
	head = temp;
	sizeOfLinkedList++;
}

void insertNodeAtEnd(int value)
{
	createFirstNode(value);
	//sizeOfLinkedList already incremented in function above
}

void insertNodeAtGivenPosition(int position, int value)
{
	if (position > sizeOfLinkedList) // case where position > size
		return;

	if (sizeOfLinkedList == 0 && position == 0) //Case where list is empty and insert at first position
	{
		createFirstNode(value);
		return;
	}

	if (sizeOfLinkedList != 0 && position == 0) //Case where list not empty but user wants to insert value at beginning (position 0)
	{
		insertNodeAtBeginning(value);
		return;
	}

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
	sizeOfLinkedList++;
}

void deleteFirstNode()
{
	if (sizeOfLinkedList == 0 && head == NULL && tail == NULL) // If the linked list is empty
		return;

	Node* temp = head;
	head = head->next;
	delete temp;
	sizeOfLinkedList--;
}

void deleteLastNode()
{
	if (sizeOfLinkedList == 0 && head == NULL && tail == NULL) 
		return;

	if (head->next == NULL) //If the first node is the last node AKA 1 node only
		deleteFirstNode();

	Node* current = head;
	Node* previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
	sizeOfLinkedList--;
}

void deleteNodeAtGivenPosition(int position)
{
	if (sizeOfLinkedList == 0 && head == NULL && tail == NULL)
		return;

	if (position >= sizeOfLinkedList)	//[] --> [] --> NULL		Greater-Equal because if position is 2,
		return;							//0       1      2			cannot delete NULL.

	if (position == 0)  //Case where there is only one node
	{	
		deleteFirstNode();
		return;
	}

	Node* current = head;
	Node* previous = new Node;

	for (int i = 0; i < position; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	sizeOfLinkedList--;
}

void menu_ADD()
{
	int dataInput = 0, indexInput = 0;

	clrscr();
	cout << "\n\n\n\n\nQuelle est la valeur ? : ";
	cin >> dataInput;

	clrscr();
	cout << "\n\n\n\n\nQuelle est l'index? : ";
	cin >> indexInput;
	if (indexInput >= 0) // Negative number cases
		insertNodeAtGivenPosition(indexInput, dataInput);
	clrscr();
}

void menu_DELETE()
{
	int indexInput = 0;

	clrscr();
	cout << "\n\n\n\n\nQuelle est l'index? : ";
	cin >> indexInput;
	if (indexInput >= 0)
		deleteNodeAtGivenPosition(indexInput);
	clrscr();
}

void menu_SHOW_NODE()
{
	int indexInput = 0;
	
	clrscr();
	cout << "\n\n\n\n\nQuelle est l'index? : ";
	cin >> indexInput;
	recursiveShowNodeAt(head, indexInput);
	//showNodeAt(indexInput);
	_getch();
	clrscr();
}

void showNodeAt(int position)
{
	if (position < 0)
	{
		clrscr();
		cout << "Position ne peut pas etre negative!";
		return;
	}
	if (position > sizeOfLinkedList)
	{
		clrscr();
		cout << "Position ne peut pas etre plus grande que la taille de la liste!";
		return;
	}
	
	Node* temp = head;

	for (int i = 0; i <= position; i++)
	{
		if (i == position)
		{
			cout << temp->data;
			return;
		}
		temp = temp->next;
	}
}

void recursiveShowNodeAt(Node* nodePointer, int position)
{
	if (position < 0)
	{
		clrscr();
		cout << "Position ne peut pas etre negative!";
		return;
	}
	if (position > sizeOfLinkedList)
	{
		clrscr();
		cout << "Position ne peut pas etre plus grande que la taille de la liste!";
		return;
	}

	if (position == 0)
	{
		cout << nodePointer->data << "\t";
		return;
	}

	recursiveShowNodeAt(nodePointer->next, position - 1);
}

void init() {
	insertNodeAtBeginning(1);
	insertNodeAtBeginning(2);
	insertNodeAtBeginning(3);
}

void printErrorMessage(int position)
{
	if (position < 0)
	{
		clrscr();
		cout << "Position ne peut pas etre negative!";
		return;
	}
	if (position > sizeOfLinkedList)
	{
		clrscr();
		cout << "Position ne peut pas etre plus grande que la taille de la liste!";
		return;
	}

}