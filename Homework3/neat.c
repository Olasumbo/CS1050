#include "Homework3.h"


void Free(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Free(root->left);
	Free(root->right);
	free(root);
}

