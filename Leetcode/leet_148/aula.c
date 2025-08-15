// Dada a função head de uma lista encadeada, retorne a lista após classificá-la em ordem crescente .

#include <stddef.h>

//   Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
}

struct ListNode *dividirnomeio(struct ListNode *head)
{
	struct ListNode *rapido = head->next;
	struct ListNode *lento = head;

	while (rapido && rapido->next)
	{
		rapido = rapido->next->next;
		lento = lento->next;
	}

	struct ListNode *segundaMetade = lento->next;
	lento->next = NULL;

	return segundaMetade;
}

struct ListNode *mesclar(struct ListNode *lista1, struct ListNode *lista2)
{
	struct ListNode *resultado = NULL;
	struct ListNode *aux = NULL;

	while (lista1 && lista2)
	{
		if (lista1->val < lista2->val)
		{
			aux->next = lista1;
			lista1 = lista1->next;
		}
		else
		{
			aux->next = lista2;
			lista2 = lista2->next;
		}
		aux = aux->next;
	}
}