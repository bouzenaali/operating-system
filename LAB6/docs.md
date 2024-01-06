## Before using a semaphore
```bash
Thread creation with ID : 140019794192064
Thread Function :: Start
Waiting for thread to exit
Thread Function :: End
sold : 80347481
Exiting Main
```
- Here `compte` don't have the same value at the end of the exectution of the program as it was at the first

## After using a semaphore
```bash
Thread creation with ID : 140633475991232
Thread Function :: Start
Thread Function :: End
Waiting for thread to exit
sold : 100000000
Exiting Main
```
- Here the value of `compte` stayed the same

### Why?
because Semaphores provide more efficient synchronization


## Operations:
- **sem_init()**:
Initializes a semaphore.
Ex: sem_init(&semaphore, 0, 1);
This initialises a semaphore using the pointer in the first argument (should be declared before with sem_t
type), the last argument is the initial value of the semaphore in a binary semaphore it is either zero or one
The second argument ‘pshared’, specifies whether the semaphore is shared between processes or
threads. Determining the scope. If ‘pshared’ is 0 the semaphore can only be used between threads within
the same process, else if it’s non-zero, the semaphore can be shared between multiple processes.
Note: In this course, we only need the semaphore locally. and in modern versions of POSIX, the use of
pshared has been deprecated, and its value is typically ignored or set to 0. So always, use zero for the
second argument.
- **sem_wait()**:
Decrements the semaphore value (P operation).
Ex: sem_wait(&semaphore);
Decrements the semaphore. If the semaphore value is greater than 0, it decrements the value and
continues execution; otherwise (value is 0), it blocks the process/thread.
- **sem_post()**:
Increments the semaphore value (V operation).
Ex: sem_post(&semaphore);
Increments the semaphore value. If any process/thread is blocked due to sem_wait(), it will be unblocked.
- **sem_destroy()**:
Destroys the semaphore when it's no longer needed.
