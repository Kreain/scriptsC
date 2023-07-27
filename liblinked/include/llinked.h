/**
 * @file llinked.h
 * @author kreain
 * @brief header file for the llinked library
 * @version 1.2
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LLINKED_H_
#define LLINKED_H_

#include "llinked_data.h"

/**
 * @brief Create (malloc) a new llist object
 * 
 * @return a pointer to the newly created list or NULL on failure
 */
llist *create_llist();


/**
 * @brief Destroy (free) a llist object
 * 
 * @param self A pointer to the llist that will be destroyed
 */
void destroy_llist(llist *self);


/**
 * @brief Create (malloc) a new node holding the data,
 * and sets it as the first element of the list
 * 
 * @param self the pointer to the llist 
 * @param data a void pointer to the data the node will hold
 * @return 0 on success, 
 * -1 on malloc failure, 
 * -2 if llist is NULL 
 */
int insert_first(llist *self, void *data);


/**
 * @brief Create (malloc) a new node holding the data,
 * and sets it at the index position in the list
 * 
 * @param self the pointer to the llist
 * @param index the index to which add the node
 * @param data a void pointer to the data the node will hold
 * @return 0 on success, 
 * -1 on malloc failure, 
 * -2 if llist is NULL or index > llist.length
 */
int insert_index(llist *self, size_t index, void *data);


/**
 * @brief Create (malloc) a new node holding the data,
 * and sets it as the last element of the list
 * 
 * @param self the pointer to the llist
 * @param data a void pointer to the data the node will hold
 * @return 0 on success, 
 * -1 on malloc failure, 
 * -2 if llist is NULL
 */
int insert_last(llist *self, void *data);


/**
 * @brief Create (malloc) a node for each data passed
 * and inserts it in the order they were passed by
 * 
 * @param self the pointer to the llist
 * @param size the number of nodes that will be inserted
 * @param ... the data for each node that will be made (Cannot be NULL)
 * @return int 0 on success,
 * -1 on malloc failure,
 * -2 if llist is NULL or size <= 0
 */
int insert_mult(llist *self, size_t size, ...);


/**
 * @brief Get the first node of the llist
 * 
 * @param self the pointer to the llist
 * @return a void pointer to the data the first node holds
 */
void *get_first(llist *self);


/**
 * @brief Get the node at the index position of the llist
 * 
 * @param self the pointer to the llist
 * @param index the index to which get the node
 * @return a void pointer to the data the node holds
 */
void *get_index(llist *self, size_t index);


/**
 * @brief Get the last node of the llist
 * 
 * @param self the pointer to the llist
 * @return a void pointer to the data the last node holds
 */
void *get_last(llist *self);


/**
 * @brief Set the data of the first node
 * 
 * @param self the pointer to the llist
 * @param data the data to set to the first node
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is zero
 */
int set_first(llist *self, void *data);


/**
 * @brief Set the data of the node at the index postition
 * 
 * @param self the pointer to the llist
 * @param index the index to which set the data
 * @param data the data to set to the node at the index position
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0 or inferior to index
 */
int set_index(llist *self, size_t index, void *data);


/**
 * @brief Set the data of the last node
 * 
 * @param self the pointer to the llist
 * @param data the data to set to the last node
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0
 */
int set_last(llist *self, void *data);


/**
 * @brief Remove (free) the first node of the llist
 * 
 * @param self the pointer to the llist
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0 
 */
int remove_first(llist *self);


/**
 * @brief Remove (free) the node at the index positions
 * 
 * @param self the pointer to the llist
 * @param index the index to which remove the node
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0 or inferior to index 
 */
int remove_index(llist *self, size_t index);


/**
 * @brief Remove (free) the last node of the llist
 * 
 * @param self the pointer to the llist
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0
 */
int remove_last(llist *self);


/**
 * @brief Swap the first node with the index position
 *
 * @param self the pointer to the llist
 * @param index the index with which swap the node
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0
 */
int swap_first(llist *self, size_t index);


/**
 * @brief Swap the last node with the index position
 *
 * @param self the pointer to the llist
 * @param index the index with which swap the node
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0
 */
int swap_last(llist *self, size_t index);


/**
 * @brief Swap the nodes at the indexed positions
 *
 * @param self the pointer to the llist
 * @param index the first index with which swap data
 * @param secondIndex the second index with which swap data
 * @return 0 on success,
 * -2 if llist is NULL or llist.length is 0
 */
int swap_index(llist *self, size_t firstIndex, size_t secondIndex);


/**
 * @brief Check if the llist is empty or not
 * 
 * @param self the pointer to the llist
 * @return true if the llist is empty, false otherwise
 */
bool is_empty(llist *self);


/**
 * @brief Check if the llist contains the requested data
 * 
 * @param self the pointer to the llist
 * @param data the requested data
 * @return true if the data is found in a node,
 * false otherwise
 */
bool contains_data(llist *self, void *data);


/**
 * @brief Remove (free) every nodes in the llist
 * 
 * @param self the pointer to the llist
 */
void clear(llist *self);


#endif /* LLINKED_H_ */
