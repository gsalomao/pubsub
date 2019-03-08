/******************************************************************************
 * @brief Linked List module.
 *****************************************************************************/

#include "lklist.h"

static inline lkitem_t * find_item(const lklist_t *list, const lkitem_t *item);

/**
 * Initialize the linked list.
 *
 * @param   list  Linked list to be initialized.
 */
void lklist_init(lklist_t *list)
{
    if (list)
    {
        list->num_item = 0;
        list->first_item = NULL;
    }
}

/**
 * Initialize the linked list item.
 *
 * @param   item  Linked list item to be initialized.
 */
void lklist_init_item(lkitem_t *item)
{
    item->last = NULL;
    item->next = NULL;
}

/**
 * Add a item to the linked list.
 *
 * @param   list    Linked list where the item will be added.
 * @param   item    Item to be added in the linked list.
 */
void lklist_add(lklist_t *list, lkitem_t *item)
{
    if (list && item)
    {
        if (list->first_item)
        {
            lkitem_t *last = list->first_item;

            while (last->next)
            {
                last = last->next;
            }

            last->next = item;
            item->last = last;
        }
        else
        {
            list->first_item = item;
        }

        list->num_item++;
    }
}

/**
 * Remove a item from the linked list.
 *
 * @param   list    Linked list where the item will be removed.
 * @param   item    Item to be removed in the linked list.
 */
void lklist_remove(lklist_t *list, lkitem_t *item)
{
    if (list && item)
    {
        lkitem_t *item_to_remove = find_item(list, item);

        if (item_to_remove)
        {
            lkitem_t *last = item_to_remove->last;
            lkitem_t *next = item_to_remove->next;

            if (last)
            {
                last->next = next;
            }
            else
            {
                list->first_item = next;
            }

            list->num_item--;
        }
    }
}

/**
 * Get the first item of the linked list.
 *
 * @param   list    Linked list to get the first item.
 * @return  First item of the linked list. If the linked list is empty, so this
 *          function returns 'NULL'.
 */
lkitem_t * lklist_first(const lklist_t *list)
{
    lkitem_t *item = NULL;

    if (list)
    {
        item = list->first_item;
    }

    return item;
}

/**
 * Get the next item of the linked list.
 *
 * @param   current     The current item in the linked list.
 * @return  The next item of the current item in the linked list. If there is
 *          no next item, so this function returns 'NULL'.
 */
lkitem_t * lklist_next(const lkitem_t *current)
{
    lkitem_t *item = NULL;

    if (current)
    {
        item = current->next;
    }

    return item;
}

/**
 * Find item in the linked list.
 *
 * @param   list    Linked list to find the item.
 * @param   item    Item to be found.
 * @return  If the item exists in linked list, it returns a pointer to the
 *          item. If the item does not exists, it returns NULL.
 */
static inline lkitem_t * find_item(const lklist_t *list, const lkitem_t *item)
{
    lkitem_t *item_to_remove = NULL;
    lkitem_t *current = lklist_first(list);

    while (current)
    {
        if (current == item)
        {
            item_to_remove = current;
            break;
        }

        current = lklist_next(current);
    }

    return item_to_remove;
}
