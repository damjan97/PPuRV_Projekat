/*
 * singlyLinkedList.c
 *
 *  Креирано 21.10.2018.
 *      Аутор: Дамјан Гламочић RA65/2015
 */

#include "singlyLinkedList.h"

bool push_end(Node* head, uint_least32_t n)
{
	Node* current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = (Node*) malloc(sizeof(Node));
	if (current->next == NULL)
	{
		fprintf(stderr, "No enough memory!\n");
		return (bool) false;
	}
	current->next->number = n;
	current->next->next = (struct node*) NULL;
	return (bool) true;
}

bool push_begin(Node** head, uint_least32_t n)
{
	Node* new_node = (Node*) malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "No enough memory!\n");
		return (bool) false;
	}
	new_node->number = n;
	new_node->next = *head;
	*head = new_node;
	return (bool) true;
}

void print_list(Node* const head)
{
	Node* current = head;
	while (current != NULL)
	{
		printf("[0%"PRIoLEAST32"\t%"PRIuLEAST32"\t0x%"PRIxLEAST32"]\n", current->number, current->number, current->number);
		current = current->next;
	}
}

void print_list_to_number(Node* const head, uint_least32_t n)
{
	uint_least32_t last_element = get_last(head);
	if (last_element <= n)
	{
		print_list(head);
	}
	else
	{
		Node* current = head;
		while (current != NULL)
		{
			if (n <= current->number)
			{
				break;
			}
			printf("[O%"PRIoLEAST32"\t%"PRIuLEAST32"\t0x%"PRIxLEAST32"]\n", current->number, current->number, current->number);
			current = current->next;
		}
	}
}

uint_least32_t remove_last(Node* head)
{
	uint_least32_t ret;

	if (head->next == NULL)
	{
		ret = head->number;
		free(head);
		return ret;
	}

	Node* current = head;
	while (current->next->next != NULL)
	{
		current = current->next;
	}

	ret = current->next->number;
	free(current->next);
	current->next = (struct node*) NULL;
	return ret;
}

uint_least32_t get_last(Node* const head)
{
	if (head->next == NULL)
	{
		return head->number;
	}

	Node* current = head;
	while (current->next->next != NULL)
	{
		current = current->next;
	}

	return current->next->number;
}

void clear_list(Node** head)
{
	Node* current = *head;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = (Node*) NULL;
}
