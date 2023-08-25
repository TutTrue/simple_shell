#ifndef COMMANDS_SEPARATOR_H
#define COMMANDS_SEPARATOR_H
/**
 * struct nodecmd_s - node that contains cmd
 * @cmd: command
 * @next: points to the next node
 * Description: singly linked list node structure
 */
typedef struct nodecmd_s
{
	char *cmd;
	struct nodecmd_s *next;
} node_cmd;

/**
 * struct listcmd_s - singly linked list
 * @head: points to the head node
 * @cur: points to the cur node
 * @tail: points to the tail node
 * Description: singly linked list node structure
 */
typedef struct listcmd_s
{
	node_cmd *head;
	node_cmd *cur;
	node_cmd *tail;
} list_cmd;
void add_node(list_cmd *my_list, char *cmd);
void print_list(list_cmd *my_list);
void free_list(list_cmd *my_list);
list_cmd *commands_separator(char *line);

#endif
