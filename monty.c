#include "monty.h"

/**
 * exec_op - find and execute opcodes
 *
 * @args: arguments
 * @h: head node
 * @ltr: line number
 */
void exec_op(char **args, stack_t **h, int *ltr)
{
	int i, *p_id;
	instruction_t op[] = {
		{"pint", _pint}, {"pall", _pall},
		{"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"sub", _sub},
		{"mul", _mul}, {"div", _div},
		{"mod", _mod}, {"nop", _nop},
		{"pchar", _pchar}, {"pstr", _pstr},
		{"rotl", _rotl}, {"rotr", _rotr},
		{"stack", _stack}, {"queue", _queue},
		{NULL, NULL}};

	if (strcmp("push", args[0]) == 0)
	{
		_push(h, args, *ltr);
	}
	else if (check_instruction(op, args))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *ltr, args[0]);
		free_dlistint(h);
		p_id = &id;
		*p_id = -1;
		return;
	}
	else
	{
		for (i = 0; op[i].opcode; i++)
		{
			if (strcmp(op[i].opcode, args[0]) == 0)
			{
				(op[i].f)(h, *ltr);
				break;
			}
		}
	}
}
