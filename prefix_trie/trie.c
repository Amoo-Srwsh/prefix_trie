#include <stdio.c>
#include <assert.h>

typedef struct Node Node;
struct Node {
	Node *children[256];
};

#define Node_pool_cap 1024
Node node_pool[Node_pool_cap];
size_t node_pool_count = 0;

int main()
{
	// TODO
	return 0;
}
