// https://en.wikipedia.org/wiki/Trie
#include <stdio.h>
#include <assert.h>

#include "fruits.h"

typedef struct Node Node;
struct Node {
	char c;
	Node *children[256];
};

#define Node_pool_cap 1024
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
	if (root->children[index] == NULL ) {
		root->children[index] = alloc_node();
		root->children[index]->c = *text;
	}

	insert_text(root->children[index], text + 1);
}

int main(void)
{
	Node *root = alloc_node();
	insert_text(root, "hello");
	return 0;
}
