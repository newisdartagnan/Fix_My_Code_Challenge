#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete a node at a given index
 *
 * @head: A pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	dlistint_t *prev_node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current_node = *head;

	if (index == 0)
	{
		*head = current_node->next;
		if (current_node->next != NULL)
			current_node->next->prev = NULL;
		free(current_node);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		if (current_node == NULL)
			return (-1);
		prev_node = current_node;
		current_node = current_node->next;
	}

	prev_node->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = prev_node;
	free(current_node);

	return (1);
}

