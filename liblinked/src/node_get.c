#include "llinked.h"

void *get_first(llist *self)
{
    if (self == NULL || self->head == NULL)
        return (NULL);
        
    return (self->head->data);
}

void *get_last(llist *self)
{
    if (self == NULL || self->head == NULL)
        return (NULL);

    ll_node *iterator = self->head;

    while (iterator->next != NULL)
        iterator = iterator->next;

    return (iterator->data);
}

void *get_index(llist *self, size_t index)
{
    if (self == NULL || self->head == NULL ||
        index >= self->length)
        return (NULL);

    ll_node *iterator = self->head;

    for (size_t i = 0; i < index; i++)
        iterator = iterator->next;
    
    return (iterator->data);
}
