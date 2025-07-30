#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Dada uma árvore binária, determine se ela tem a altura equilibrada. */

typedef struct TreeNode
{
	int val;
	struct TreeNode *direita;
	struct TreeNode *esquerda;
} TreeNode;

int verificaAltura(struct TreeNode *filho)
{
	if (filho == NULL)
	{
		return 0;
	}

	int esquerda = verificaAltura(filho->esquerda);
	int direita = verificaAltura(filho->direita);
}

bool isBalanced(struct TreeNode *root)
{
}