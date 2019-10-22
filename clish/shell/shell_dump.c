#ifdef DEBUG

/*
 * shell_dump.c
 */
#include "private.h"
#include "lub/dump.h"
#include "lub/list.h"

/*--------------------------------------------------------- */
void clish_shell_dump(clish_shell_t * this)
{
	clish_view_t *v;
	clish_ptype_t *t;
	clish_var_t *var;
	lub_list_node_t *node;
	lub_bintree_iterator_t iter;

	lub_dump_printf("shell(%p)\n", this);
	lub_dump_printf("OVERVIEW:\n%s\n", LUB_DUMP_STR(this->overview));
	lub_dump_indent();

	/* iterate the tree of views */
	for (node = lub_list_iterator_init(this->view_tree);
		node; node = lub_list_iterator_next(node)) {
		v = (clish_view_t *)lub_list_node__get_data(node);
		clish_view_dump(v);
	}

	/* iterate the tree of types */
	for (node = lub_list_iterator_init(this->ptype_tree);
		node; node = lub_list_iterator_next(node)) {
		t = (clish_ptype_t *)lub_list_node__get_data(node);
		clish_ptype_dump(t);
	}

	/* iterate the tree of vars */
	var = lub_bintree_findfirst(&this->var_tree);
	for (lub_bintree_iterator_init(&iter, &this->var_tree, var);
		var; var = lub_bintree_iterator_next(&iter)) {
		clish_var_dump(var);
	}

	lub_dump_undent();
}

/*--------------------------------------------------------- */

#endif /* DEBUG */
