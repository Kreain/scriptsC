#include "llinked.h"
#include <stdio.h>

int swap_first(llist *self, size_t index)
{
    if (self == NULL || self->head == NULL ||
        index >= self->length)
        return (-2);

    ll_node *iterator = self->head;
    for (size_t i = 0; i < index; i++)
        iterator = iterator->next;

    void *savedData = iterator->data;
    iterator->data = self->head->data;
    self->head->data = savedData;

    return (0);
}

int swap_last(llist *self, size_t index)
{
    if (self == NULL || self->head == NULL ||
        index >= self->length)
        return (-2);

    ll_node *last = self->head;
    while (last->next != NULL)
        last = last->next;

    ll_node *iterator = self->head;
    for (size_t i = 0; i < index; i++)
        iterator = iterator->next;
        
    void *savedData =  iterator->data;
    iterator->data = last->data;
    last->data = savedData;

    return (0);
}

int swap_index(llist *self, size_t firstIndex, size_t secondIndex)
{
    if (self == NULL || self->head == NULL ||
        firstIndex >= self->length || secondIndex >= self->length)
        return (-2);

    if (firstIndex == secondIndex)
        return (0);
    if (firstIndex == 0 || secondIndex == 0)
        return (swap_first(self, firstIndex == 0 ? secondIndex : firstIndex));
    if (firstIndex == self->length - 1 || secondIndex == self->length - 1)
        return (swap_last(self, firstIndex == self->length  - 1 ? secondIndex : firstIndex));

    ll_node *firstIterator;
    ll_node *secondIterator;
    for (size_t i = 0; i < (firstIndex > secondIndex ? firstIndex : secondIndex); i++) {
        if (i < firstIndex)
            firstIterator = firstIterator->next;
        if (i < secondIndex)
            secondIterator = secondIterator->next;
    }
        
    void *savedData =  firstIterator->data;
    firstIterator->data = secondIterator->data;
    secondIterator->data = savedData;

    return (0);
}
