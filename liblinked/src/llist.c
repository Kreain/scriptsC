#include "llinked.h"

llist *create_llist(void)
{
    llist *new_llist = malloc(sizeof(llist));

    if (new_llist != NULL) {
        new_llist->insert_first = &insert_first;
        new_llist->insert_index = &insert_index;
        new_llist->insert_last = &insert_last;
        new_llist->insert_mult = &insert_mult;

        new_llist->get_first = &get_first;
        new_llist->get_index = &get_index;
        new_llist->get_last = &get_last;

        new_llist->set_first = &set_first;
        new_llist->set_index = &set_index;
        new_llist->set_last = &set_last;

        new_llist->remove_first = &remove_first;
        new_llist->remove_index = &remove_index;
        new_llist->remove_last = &remove_last;

        new_llist->swap_first = &swap_first;
        new_llist->swap_last = &swap_last;
        new_llist->swap_index = &swap_index;

        new_llist->is_empty = &is_empty;
        new_llist->contains_data = &contains_data;
        new_llist->clear = &clear;

        new_llist->head = NULL;
        new_llist->length = 0;
    }

    return (new_llist);
}

void destroy_llist(llist *self)
{
    self->clear(self);

    free(self);
}
