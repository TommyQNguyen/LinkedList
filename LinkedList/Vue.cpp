#include "Vue.h"
#include "LinkedList.h"
#include "C:\cvm.h"

using namespace std;

//extern int sizeOfLinkedList;

int showMenu(int sizeOfLinkedList) {
	int choice;

	cout << "\n\n" <<
		"Que voulez-vous faire?\n\n" <<
		"1 Ajouter un element a la liste?\n" <<
		"2 Retirer un element de la liste?\n" <<
		"3 Afficher un element de la liste?\n" <<
		"4 Quitter?\n\n\n" <<
		"Il y a presentement " << sizeOfLinkedList << " element(s) dans la liste\n\n\n\n" <<
		"Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}

void showNodeList(Node* head)
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

void showNodeAt(int position, int sizeOfLinkedList, Node* head)
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
			break;
		}
		temp = temp->next;
	}
}

void recursiveShowNodeAt(Node* nodePointer, int position, int sizeOfLinkedList)
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

	recursiveShowNodeAt(nodePointer->next, position - 1, sizeOfLinkedList);
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

void menu_SHOW_NODE(Node* head, int sizeOfLinkedList)
{
	int indexInput = 0;

	clrscr();
	cout << "\n\n\n\n\nQuelle est l'index? : ";
	cin >> indexInput;
	recursiveShowNodeAt(head, indexInput, sizeOfLinkedList);
	//showNodeAt(indexInput);
	_getch();
	clrscr();
}

void printErrorMessage(int position, int sizeOfLinkedList)
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