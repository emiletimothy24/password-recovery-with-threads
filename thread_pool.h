#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <stddef.h>
#include <stdlib.h>

#include "queue.h"

/**
 * A pool of threads. Work added to the pool
 * is run on whichever thread is available first.
 */
typedef struct thread_pool thread_pool_t;

/** A function that can be run on a thread pool */
typedef void (*work_function_t)(void *aux);

/**
 * Creates a new heap-allocated thread pool
 *
 * @param num_worker_threads the number of threads in the pool
 * @return a pointer to the new thread pool
 */
thread_pool_t *thread_pool_init(size_t num_worker_threads);

/**
 * Adds work to a thread pool
 *
 * @param pool the thread pool to perform the work
 * @param function the function to call on a thread in the thread pool
 * @param aux the argument to call the work function with
 */
void thread_pool_add_work(thread_pool_t *pool, work_function_t function, void *aux);

/**
 * Waits for all work added to a thread pool to finish,
 * then frees all resources associated with a heap-allocated thread pool.
 * You can enqueue a special value, e.g. NULL, to mark the end of the work.
 *
 * @param pool the thread pool to close
 */
void thread_pool_finish(thread_pool_t *pool);

#endif /* THREAD_POOL_H */
