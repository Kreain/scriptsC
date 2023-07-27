#include "llinked.h"

int set_first(llist *self, void *data)
{
    if (self == NULL || self->head == NULL)
        return (-2);
        
    self->head->data = data;

    return (0);
}

int set_last(llist *self, void *data)
{
    if (self == NULL || self->head == NULL)
        return (-2);

    ll_node *iterator = self->head;

    while (iterator->next != NULL)
        iterator = iterator->next;
    iterator->data = data;
    
    return (0);
}

int set_index(llist *self, size_t index, void *data)
{
    if (self == NULL || self->head == NULL ||
        index >= self->length)
        return (-2);

    ll_node *iterator = self->head;

    for (size_t i = 0; i < index; i++)
        iterator = iterator->next;
    iterator->data = data;
    
    return (0);
}
