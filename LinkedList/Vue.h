#pragma once
#include <iostream>
#include <conio.h>
#include "LinkedList.h"

//extern int sizeOfLinkedList;


int showMenu(int sizeOfLinkedList);
void showNodeList(Node* head);
void recursiveShowNodeList(Node* nodePointer);
void showNodeAt(int position, int sizeOfLinkedList, Node* head);
void recursiveShowNodeAt(Node* nodePointer, int position, int sizeOfLinkedList);
void menu_ADD();
void menu_DELETE();
void menu_SHOW_NODE(Node* head, int sizeOfLinkedList);
void printErrorMessage(int position, int sizeOfLinkedList);


