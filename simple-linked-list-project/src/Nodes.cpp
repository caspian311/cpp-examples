/*
 * Nodes.cpp
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */
#include <iostream>
#include "Nodes.h"

using namespace std;

Node *get_last_node(Node *node) {
	while (node->next_node != NULL) {
		node = node->next_node;
	}
	return node;
}

void add_node(Node *root, int value) {
	Node *last_node = get_last_node(root);

	Node *new_node = new Node;
	new_node->x = value;

	last_node->next_node = new_node;
}

Node *create_root_node(int value) {
	Node *new_node = new Node;
	new_node->x = value;

	return new_node;
}

void list_values(Node *current) {
	while (current != NULL) {
		cout << "X: " << current->x << "\n";
		current = current->next_node;
	}
}
