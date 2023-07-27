#include "llinked.h"

int remove_first(llist *self)
{
    if (self == NULL || self->head == NULL)
        return (-2);
    
    ll_node *node = self->head;
    
    self->head = self->head->next;
    free(node);
    self->length--;

    return (0);
}

int remove_last(llist *self)
{
    if (self == NULL || self->head == NULL)
        return (-2);
    
    if (self->head->next == NULL)
        return (remove_first(self));
    
    ll_node *iterator = self->head;
    ll_node *last = self->head;

    while (iterator->next != NULL) {
        last = iterator;
        iterator = iterator->next;
    }
    last->next = NULL;
    free (iterator);
    self->length--;

    return (0);
}

int remove_index(llist *self, size_t index)
{
    if (self == NULL || self->head == NULL ||
        index >= self->length)
        return (-2);

    if (index == 0)
        return (remove_first(self));
    if (index == self->length - 1)
        return (remove_last(self));

    ll_node *iterator = self->head;
    ll_node *previous = NULL;

    for (size_t i = 0; i < index; i++) {
        previous = iterator;
        iterator = iterator->next;
    }
    previous->next = iterator->next;

    free(iterator);
    self->length--;

    return (0);
}