/******************************************************************************
 * @brief Linked List module.
 *****************************************************************************/

#ifndef LKLIST_H_
#define LKLIST_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/** List to implement the linked list. */
typedef struct
{
    size_t num_item;
    struct lkitem *first_item;

} lklist_t;

/** Item in the linked list. */
typedef struct lkitem
{
    struct lkitem *last;
    struct lkitem *next;

} lkitem_t;

/**
 * Get the length of the linked list.
 *
 * @param   list    Linked list to get its length.
 * @return  The number of elements in the linked list.
 */
static inline size_t lklist_len(const lklist_t *list)
{
    return list->num_item;
}

void lklist_init(lklist_t *list);
void lklist_init_item(lkitem_t *item);
void lklist_add(lklist_t *list, lkitem_t *item);
void lklist_remove(lklist_t *list, lkitem_t *item);
lkitem_t * lklist_first(const lklist_t *list);
lkitem_t * lklist_next(const lkitem_t *current);

#endif /* LKLIST_H_ */
