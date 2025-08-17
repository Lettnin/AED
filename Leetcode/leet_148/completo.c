// Dada a função head de uma lista encadeada, retorne a lista após classificá-la em ordem crescente .

#include <stdio.h>
#include <stdlib.h>

//   Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head);
struct ListNode *dividirnomeio(struct ListNode *head);
struct ListNode *mesclar(struct ListNode *lista1, struct ListNode *lista2);

struct ListNode *sortList(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	struct ListNode *segunda = dividirnomeio(head);

	struct ListNode *esquerda = sortList(head);
	struct ListNode *direita = sortList(segunda);

	return mesclar(esquerda, direita);
}

struct ListNode *dividirnomeio(struct ListNode *head)
{
	struct ListNode *rapido = head->next;
	struct ListNode *lento = head;

	while (rapido != NULL && rapido->next != NULL)
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
	struct ListNode resultado;
	struct ListNode *aux = &resultado;
	resultado.next = NULL;

	while (lista1 != NULL && lista2 != NULL)
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

	if (lista1 != NULL)
	{
		aux->next = lista1;
	}
	if (lista2 != NULL)
	{
		aux->next = lista2;
	}

	return resultado.next;
}
