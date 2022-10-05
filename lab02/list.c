#include "list.h"
#include <stdlib.h>
#include <stdio.h>
/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
void append_node(node **ppHead, int new_data)
{
	/* First lets allocate memory for the new node and initialize its attributes */
	node *pNew = (node *)malloc(sizeof(node));
	pNew->val = new_data;
	pNew->next = NULL;
	/* If the list is empty, set the new node to be the head and return */
	if (*ppHead == NULL)
	{
		*ppHead = pNew;
		return;
	}
	node *pCurr = *ppHead;
	while (pCurr->next != NULL)
	{
		pCurr = pCurr->next;
	}
	/* Insert node at the end of the list */
	pCurr->next = pNew;
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list(node **ppHead)
{
	node *pPrev = NULL;
	node *pCurr = *ppHead;
	node *pNext = NULL;
	pNext = pCurr->next;
	while (pCurr != NULL)
	{
		pPrev = pCurr;
		pCurr = pNext;
		if (pNext == NULL)
		{
			pCurr = pPrev;
			break;
		}
		pNext = pCurr->next;
		pCurr->next = pPrev;
	}

	/* Set the new head to be what originally was the last node in the list */
	(*ppHead)->next = NULL;
	*ppHead = pCurr;
}

// int main()
//{
//	node *plist = NULL;
//	append_node(&plist, 0);
//     for (int i = 1; i < 2; i++)
//     {
//     	append_node(&plist, i);
//     }
//
//	reverse_list(&plist);
//
//	node *pCurr = plist;
//	while (pCurr != NULL)
//	{
//		printf("%d\n", pCurr->val);
//		pCurr = pCurr->next;
//	}
//	return 0;
// }