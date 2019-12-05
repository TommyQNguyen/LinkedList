#pragma once
#include <Windows.h>
#include <conio.h>


//Constantes
const int MENU_ADD = 1, MENU_DELETE = 2, MENU_SHOW_ELEMENT = 3, MENU_QUIT = 4;


struct Node
{
	int data;
	Node* next;
};

//Function prototypes
void createFirstNode(int value);
void insertNodeAtBeginning(int value);
void insertNodeAtEnd(int value);
void insertNodeAtGivenPosition(int position, int value);
void deleteFirstNode();
void deleteLastNode();
void deleteNodeAtGivenPosition(int pos);
void init();
