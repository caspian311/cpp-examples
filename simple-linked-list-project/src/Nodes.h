/*
 * Nodes.h
 *
 *  Created on: Mar 22, 2010
 *      Author: mtodd
 */

#ifndef NODES_H_
#define NODES_H_

struct Node {
	int x;
	Node *next_node;
};

Node *get_last_node(Node *node);
void add_node(Node *root, int value);
Node *create_root_node(int value);
void list_values(Node *current);

#endif /* NODES_H_ */
