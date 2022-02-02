// https://en.wikipedia.org/wiki/Trie
#include <stdio.h>
#include <assert.h>
#include "fruits.h"

#define Node_pool_cap 1024
#define children_count 256

typedef struct Node Node;
struct Node {
	char c;
	Node *children[children_count];
};

Node node_pool[Node_pool_cap];
size_t node_pool_count = 0;

Node *alloc_node (void) // simple allocator function
{
	assert(node_pool_count < Node_pool_cap);
	return &node_pool[node_pool_count++];
}

void insert_text (Node *root, const char *text)
{
	if (*text == '\0') return;

	assert(text != NULL);

	size_t index = (size_t) *text;
	if (root->children[index] == NULL) {
		root->children[index] = alloc_node();
		root->children[index]->c = *text;
	}

	insert_text(root->children[index], text + 1);
}

void draw_mem(Node *root)
{
	for ( int i = 0; i < children_count; i++ ) {
		if (root->children[i] != NULL) {
			printf("%c\n", root->children[i]->c);
			draw_mem(root->children[i]);
		}
	}
	return;
}

int main(void)
{
	Node *root = alloc_node();
	for ( int i = 0; i < fruits_count; i++ )
		insert_text(root, fruits[i]);

	draw_mem(root);
	return 0;
}
