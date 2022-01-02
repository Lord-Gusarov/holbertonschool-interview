#include "lists.h"

/**
 * insert_node - node to be inserted into aa sorted singly linked list.
 * @head: pointer to the head
 * @number: number to add
 * Return: pointer to the new node or NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *temp = NULL;
	listint_t *new = NULL;

	if (!head)
		return (NULL);
	temp = *head;
	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;

	if (!temp)
	{
		*head = new;
		return (new);
	}
	if (number < temp->n)
	{
		new->next = temp;
		*head = new;
		return (new);
	}
	while (temp->next && temp->next->n <= number)
		temp = temp->next;
	new->next = temp->next;
	temp->next = new;
	return (new);
}
