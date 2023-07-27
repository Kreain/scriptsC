#include "llinked.h"

bool is_empty(llist *this)
{
    if (this == NULL || this->head == NULL)
        return (true);
    
    return (false);
}

bool contains_data(llist *this, void *data)
{
    if (this == NULL || this->head == NULL)
        return (false);
    
    ll_node *iterator = this->head;

    while (iterator != NULL && iterator->data != data)
        iterator = iterator->next;

    return (iterator != NULL);
}

void clear(llist *self)
{
    if (self == NULL || self->head == NULL)
        return;

    ll_node *current = self->head;

    while (self->head != NULL) {
        current = self->head;
        self->head = self->head->next;
        free(current);
    }
}
