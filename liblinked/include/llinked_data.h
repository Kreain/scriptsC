/**
 * @file llinked_data.h
 * @author kreain
 * @brief header file conataining the structures for the llinked library
 * @version 1.0
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LLINKED_DATA_H_
#define LLINKED_DATA_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct llist_s llist;
typedef struct ll_node_s ll_node;

struct ll_node_s {
    void *data;
    
    ll_node *next;
};

struct llist_s {
    ll_node *head;
    size_t length;

    int (*insert_first)(llist *, void *);
    int (*insert_index)(llist *, size_t, void *);
    int (*insert_last)(llist *, void *);
    int (*insert_mult)(llist *, size_t, ...);

    void *(*get_first)(llist *);
    void *(*get_index)(llist *, size_t);
    void *(*get_last)(llist *);

    int (*set_first)(llist *, void *);
    int (*set_index)(llist *, size_t, void *);
    int (*set_last)(llist *, void *);

    int (*remove_first)(llist *);
    int (*remove_index)(llist *, size_t);
    int (*remove_last)(llist *);

    int (*swap_first)(llist *, size_t);
    int (*swap_last)(llist *, size_t);
    int (*swap_index)(llist *, size_t, size_t);

    bool (*is_empty)(llist *);
    bool (*contains_data)(llist *, void *);
    void (*clear)(llist *);
};

#endif /* LLINKED_DATA_H_ */