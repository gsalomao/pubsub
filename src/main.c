/******************************************************************************
 * @brief Publisher/Subscriber application test.
 *****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include "pubsub.h"

static void subscriber1_handler(void);
static void subscriber2_handler(void);
static void subscriber3_handler(void);

/**
 * @brief Application which test the pubsub module.
 */
int main()
{
    publisher_t publisher;
    subscriber_t subscriber1;
    subscriber_t subscriber2;
    subscriber_t subscriber3;

    /* Initialize publisher */
    pubsub_pub_init(&publisher);

    /* Initialize subscribers */
    pubsub_sub_init(&subscriber1, subscriber1_handler);
    pubsub_sub_init(&subscriber2, subscriber2_handler);
    pubsub_sub_init(&subscriber3, subscriber3_handler);

    /* Add subscribers to publisher */
    pubsub_add(&publisher, &subscriber1);
    pubsub_add(&publisher, &subscriber2);
    pubsub_add(&publisher, &subscriber3);

    while (1)
    {
        printf("Notifying subscribers... \n");

        /* Notify subscribers */
        pubsub_notify(&publisher);

        printf("\n");
        sleep(1);
    }

    return 0;
}

/**
 * Callback which is called by publisher to notify subscriber 1.
 */
static void subscriber1_handler(void)
{
    printf("Subscriber 1 - OK!\n");
}

/**
 * Callback which is called by publisher to notify subscriber 2.
 */
static void subscriber2_handler(void)
{
    printf("Subscriber 2 - OK!\n");
}

/**
 * Callback which is called by publisher to notify subscriber 3.
 */
static void subscriber3_handler(void)
{
    printf("Subscriber 3 - OK!\n");
}
