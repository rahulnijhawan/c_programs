/**
 *  find duplication in input data.
 */
#include <stdio.h>
#include <stdlib.h>

// data
struct int_node {
	int val;
	//struct int_node *parent;	
	struct int_node *left;
	struct int_node *right;
};


typedef struct int_node* pin_node; 
pin_node tree;
// data ends

// functions
pin_node createNode();
pin_node getNFillNode(int);
void setLeft(pin_node, int);
void setRight(pin_node, int);
int info(pin_node);
void buildBinaryTree(pin_node , int );
// functions ends

int main(int argc, char const *argv[])
{
	int val;
	scanf("%d", &val);
	tree = getNFillNode(val);
	pin_node q, p;
	while(1) {
		scanf("%d", &val);
		buildBinaryTree(tree, val);
		p = NULL;
	}	

	printf("%d\n", tree->val);

	
	return 0;
}

pin_node createNode()
{
	pin_node nd = (pin_node) malloc(sizeof(struct int_node));
	nd->parent = NULL;
	nd->left = NULL;
	nd->right = NULL;
}

pin_node getNFillNode(int i)
{
	pin_node nd = createNode();
	
	nd->val = i;
	return nd;
}

void buildBinaryTree(pin_node root, int i)
{
	int v;
	pin_node q, p;
	p = q = root;
	while (q) {
		p = q;
		v = info(p);
		if (v == i) {
			printf("duplicate\n");
			q = NULL;
		} else if (v < i) {
			q = q->left;

		} else {
			q = q->right;
		}
		

	}

	if (p) {
		int v = p->val;
		 if (v < i) {
		 	setLeft(p, i);
		} else {
			setRight(p, i);
		}
	}
	
}

void setLeft(pin_node n, int i)
{
	if (n == NULL) {
		printf("invalid node.\n");
	} else if (n->left != null) {
		printf("left node exists.\n");
	} else {
		pin_node newNode = getNFillNode(i);
		n->left = newNode;
	}

}

void setRight(pin_node n, int i)
{
	if (n == NULL) {
		printf("invalid node.\n");
	} else if (n->right != null) {
		printf("right node exists.\n");
	} else {
		pin_node newNode = getNFillNode(i);
		n->right = newNode;
	}
}

void info(pin_node pn)
{
	if (pn != NULL) {
		return pn->val;
	}	
}

