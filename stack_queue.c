#include "monty.h"

/**
 * add_node - add a new node to a circular linked list
 * @stack: double pointer to the beginning of the circular linked list
 * @n: value to add to the new node
 *
 * Description: the function will add the node to the begining if in
 * stack mode and the end if in queue mode
 *
 * Return: pointer to the new node, or NULL on failure
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.queue == STACK || var.stack_len == 0)
		*stack = new;
	return (new);
}

/**
 * m_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void m_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = STACK;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = QUEUE;
}
