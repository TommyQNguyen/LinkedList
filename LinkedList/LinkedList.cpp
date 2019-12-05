#include "LinkedList.h"
#include "Vue.h"

using namespace std;

//extern int sizeOfLinkedList = 0;
int sizeOfLinkedList = 0;
Node* head = NULL;
Node* tail = NULL;


int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	init();

	int choice = 0;
	while (choice != MENU_QUIT) {
		recursiveShowNodeList(head);
		choice = showMenu(sizeOfLinkedList);

		switch (choice) {
		case MENU_ADD:
			menu_ADD();
			break;
		case MENU_DELETE:
			menu_DELETE();
			break;
		case MENU_SHOW_ELEMENT:
			menu_SHOW_NODE(head, sizeOfLinkedList);
			break;
		case MENU_QUIT:
			break;
		}
	}

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


void insertNodeAtBeginning(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = head;
	head = temp;
	sizeOfLinkedList++;
}

//TODO remove me?
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


void init() {
	insertNodeAtBeginning(1);
	insertNodeAtBeginning(2);
	insertNodeAtBeginning(3);
}

