/******************************************************************************
 * @brief Module which implements the publisher/subscriber pattern.
 *****************************************************************************/

#ifndef PUBSUB_H_
#define PUBSUB_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "lklist.h"

/** Callback pointer. */
typedef void (*callback_t)(void);

/** Publisher which will notify all subscribers. */
typedef struct
{
    lklist_t parent;

} publisher_t;

/** Subscriber which will be notified by the publisher. */
typedef struct
{
    lkitem_t parent;
    callback_t callback;
    void *data;

} subscriber_t;

/**
 * Get the number of subscribers of a given publisher.
 *
 * @param   publisher   Publisher to get the number of subscribers.
 * @return  The number of subscribers.
 */
static inline size_t pubsub_num_subscribers(const publisher_t *publisher)
{
    return lklist_len((const lklist_t *) publisher);
}

void pubsub_pub_init(publisher_t *publisher);
void pubsub_sub_init(subscriber_t *subscriber, callback_t callback);
void pubsub_add(publisher_t *publisher, subscriber_t *subscriber);
void pubsub_remove(publisher_t *publisher, subscriber_t *subscriber);
void pubsub_notify(const publisher_t *publisher);
subscriber_t * pubsub_get_first(const publisher_t *publisher);
subscriber_t * pubsub_get_next(const subscriber_t *current);

#endif /* PUBSUB_H_ */
