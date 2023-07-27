#include "llinked.h"
#include <stdarg.h>

#include <stdio.h>

int insert_first(llist *self, void *data)
{
    if (self == NULL)
        return (-2);

    if (self->head == NULL)
    {
        self->head = malloc(sizeof(ll_node));
        if (self->head == NULL)
            return (-1);
        self->head->data = data;
        self->head->next = NULL;
        self->length++;
        return (0);
    }

    ll_node *head = malloc(sizeof(ll_node));

    if (head == NULL)
        return (-1);
    head->data = data;
    head->next = self->head;
    self->head = head;
    self->length++;

    return (0);
}

int insert_last(llist *self, void *data)
{
    if (self == NULL)
        return (-2);

    if (self->head == NULL)
        return (insert_first(self, data));

    ll_node *iterator = self->head;

    while (iterator->next != NULL)
        iterator = iterator->next;

    iterator->next = malloc(sizeof(ll_node));
    if (iterator->next == NULL)
        return (-1);
    iterator->next->data = data;
    iterator->next->next = NULL;
    self->length++;

    return (0);
}

int insert_index(llist *self, size_t index, void *data)
{
    if (self == NULL || index > self->length)
        return (-2);

    if (index == 0)
        return (insert_first(self, data));
    if (index == self->length)
        return (insert_last(self, data));

    ll_node *iterator = self->head;

    for (size_t i = 0; i < index - 1; i++)
        iterator = iterator->next;

    ll_node *save = iterator->next;

    iterator->next = malloc(sizeof(ll_node));
    if (iterator->next == NULL)
        return (-1);
    iterator->next->data = data;
    iterator->next->next = save;
    self->length++;

    return (0);
}

int insert_mult(llist *self, size_t size, ...)
{
    va_list valist;

    if (self == NULL || size <= 0)
        return (-2);

    va_start(valist, size);
    
    for (size_t index = 1; index <= size; index++) {
        int ret = self->insert_last(self, va_arg(valist, void *));
        if (ret < 0)
            return (ret);
    }
    va_end(valist);

    return (0);
}