/*
 * Main.cpp
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */
#include "Nodes.h"

int main(void) {
	Node *root = create_root_node(1);
	add_node(root, 2);
	add_node(root, 3);
	add_node(root, 4);
	add_node(root, 5);
	list_values(root);
}
