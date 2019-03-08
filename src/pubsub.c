/******************************************************************************
 * @brief Module which implements the publisher/subscriber pattern.
 *****************************************************************************/

#include "pubsub.h"

/**
 * Initialize publisher.
 *
 * @param   publisher   Publisher to be initialized.
 */
void pubsub_pub_init(publisher_t *publisher)
{
    lklist_init((lklist_t *) publisher);
}

/**
 * Initialize subscriber.
 *
 * @param   subscriber  Subscriber to be initialized.
 * @param   callback    Callback to be assigned to subscriber.
 */
void pubsub_sub_init(subscriber_t *subscriber, callback_t callback)
{
    lklist_init_item((lkitem_t *) subscriber);
    subscriber->callback = callback;
}

/**
 * Add subscriber to publisher.
 *
 * @param   publisher   Publisher where the subscriber will be added.
 * @param   subscriber  Subscriber to be added in publisher.
 */
void pubsub_add(publisher_t *publisher, subscriber_t *subscriber)
{
    lklist_add((lklist_t *) publisher, (lkitem_t *) subscriber);
}

/**
 * Remove subscriber from publisher.
 *
 * @param   publisher   Publisher where the subscriber will be removed.
 * @param   subscriber  Subscriber to be removed from publisher.
 */
void pubsub_remove(publisher_t *publisher, subscriber_t *subscriber)
{
    lklist_remove((lklist_t *) publisher, (lkitem_t *) subscriber);
}

/**
 * Notify all subscriber for the publisher.
 *
 * @note  The notification is done by calling all subscriber's callback.
 *
 * @param   publisher   Publisher to notify the subscribers.
 */
void pubsub_notify(const publisher_t *publisher)
{
    subscriber_t *subscriber;

    subscriber = (subscriber_t *) lklist_first((const lklist_t *) publisher);

    while (subscriber)
    {
        if (subscriber->callback)
        {
            subscriber->callback();
        }

        subscriber = (subscriber_t *)
                lklist_next((const lkitem_t *) subscriber);
    }
}

/**
 * Get the first subscriber of a publisher.
 *
 * @param   publisher    Publisher to get the first subscriber.
 * @return  First subscriber of a publisher. If the publisher is empty, so this
 *          function returns 'NULL'.
 */
subscriber_t * pubsub_get_first(const publisher_t *publisher)
{
    return (subscriber_t *) lklist_first((lklist_t *) publisher);
}

/**
 * Get the next subscriber of the publisher.
 *
 * @param   current     The current subscriber of the publisher.
 * @return  The next subscriber of the current publisher in the linked list.
 *          If there is no next subscriber, so this function returns 'NULL'.
 */
subscriber_t * pubsub_get_next(const subscriber_t *current)
{
    return (subscriber_t *) lklist_next((lkitem_t *) current);
}
