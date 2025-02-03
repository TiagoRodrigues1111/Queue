
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/TiagoRodrigues1111/queue?color=orange)](https://github.com/TiagoRodrigues1111/queue/releases)
[![Unlicense License](https://img.shields.io/badge/license-Unlicense-blue.svg)](LICENSE)

 
# Queue Implementation in C

This repository contains a simple implementation of a queue data structure in the C programming language. The queue follows the First In, First Out (FIFO) principle, and the implementation supports common queue operations such as push, pop, front, back, and check for emptiness as well as the current size of the queue.

## Features

- Dynamic queue implementation (using a resizable array or linked list).
- Basic operations:
  - `Create`: Creates the queue datastructure.  - `create_queue`
  - `Push`: Add an element to the back of the queue. - `queue_push`
  - `Pop`: Remove the front element of the queue. - `queue_pop`
  - `Front`: View the front element without removing it. - `check_queue_front`
  - `Back`: View the back element without removing it. - `check_queue_back`
  - `IsEmpty`: Check if the queue is empty. - `check_queue_is_empty`
  - `Size`: Get the current size of the queue. - `check_queue_size`
  - `Free`: Frees the queue datastructure. - `free_queue` 
## Prerequisites

To compile and run the program, you need:
- A C compiler (e.g., GCC, Clang, or MSVC).
- Basic knowledge of working with C files.


## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/TiagoRodrigues1111/queue
   cd queue
   ```



2. Compile the code using one of the following options:

   #### 2.1 Using `queue.c` (Array-based implementation):
   ```bash
   gcc queue.c simplemain.c -o queue
   ```

   #### 2.2 Using `queue_ll.c` (Linked list-based implementation):
   ```bash
   gcc queue_ll.c simplemain.c -o queue
   ```
   #### 2.3 Using `MakeFile`:
   ```bash
   make all/queue_test    # uses queue.c 
   make queue_ll          # uses queue_ll.c
   ```   

3. Run the executable:
  #### 3.1 Without make:
   ```bash
   ./queue
   ```
  #### 3.2 With make:
   ```bash
    make run
   ```


## Repo Structure

### File Structure

- [queue.c](queue.c): Contains the implementation of the queue functions (array-based)
- [queue_ll.c](queue_ll.c): Contains the implementation of the queue functions (linked list-based)
- [queue.h](queue.h): Header file with function declarations and definitions
- [simplemain.c](simplemain.c): Example usage of the queue
- [README.md](README.md): Documentation for the project
- [Makefile](Makefile): Simple Makefile 


### Folder  Structure

```
.
├── queue.c         
├── queue_ll.c      
├── queue.h         
├── simplemain.c          
├── README.md
└── Makefile         
```

## Operations Breakdown

### `Create`
- **Description**: Creates the queue datastructure
- **Input**: The pointer to the memory position of the queue, the datatype size, and number of elements to allocate.
- **Example**:
  ```c
  void *queue= NULL;
  create_queue(&queue, sizeof(uint8_t), 10);
  ```

### `Push`
- **Description**: Adds an element to the front of the queue.
- **Input**: The pointer to the queue, as well as a void* to the input data.
- **Example**:
  ```c
  uint8_t data=10;
  queue_push(queue,(void*)&data);
  ```

### `Pop`
- **Description**: Removes the back element from the queue.
- **Output**: None.
- **Example**:
  ```c
  queue_pop(queue);
  ```

### `Front`
- **Description**: Returns the front element of the queue without removing it.
- **Output**: The starting memory position of the element.
- **Example**:
  ```c
  uint8_t front = *((uint8_t*)check_queue_front(queue));
  printf("Front element: %u\n",front);  
  ```
### `Back`
- **Description**: Returns the back element of the queue without removing it.
- **Output**: The starting memory position of the element.
- **Example**:
  ```c
  uint8_t back = *((uint8_t*)check_queue_back(queue));
  printf("Back element: %u\n",back);  
  ```


### `IsEmpty`
- **Description**: Checks if the queue is empty.
- **Output**: A boolean value (0 or 1).
- **Example**:
  ```c
  if (check_queue_is_empty(queue)) {
      printf("Queue is empty\n");
  }
  ```

### `Size`
- **Description**: Returns the number of elements currently in the queue.
- **Output**: An uint64_t representing the queue size.
- **Example**:
  ```c
  uint64_t size = check_queue_size(queue);
  printf("Queue size: %lu\n", size);
  ```

### `Free`
- **Description**: Frees the queue datastructure.
- **Output**: None.
- **Example**:
  ```c
  free_queue(queue);
  ```



## Example Usage

Here is a simple example of how the queue can be used (tutorial() in [simplemain.c](simplemain.c)):

```c
#include <stdio.h>
#include "queue.h"

int main() 
{
        void *queue1 = NULL;
        create_queue(&queue1, sizeof(uint16_t),5);                              // create a queue of 5 elements of uint16_t size

        uint16_t data1 = 3;
        queue_push(queue1,(void*) &data1);                                      // Push a value onto the queue
        
        data1 = 20;
        queue_push(queue1,(void*) &data1);                                  // Push another value onto the queue

        if(!check_queue_is_empty(queue1))                                       // Checks if queue is not empty 
        {
                printf("%u\n",*((uint16_t*)check_queue_front(queue1)));         // prints front of queue
        }

        if(!check_queue_is_empty(queue1))                                       // Checks if queue is not empty 
        {
                printf("%u\n",*((uint16_t*)check_queue_back(queue1)));         // prints back of queue
        }


        queue_pop(queue1);                                                      // Pops a value from the queue

        printf("%lu\n",check_queue_size(queue1));                               // prints size of the queue

        free_queue(queue1);                                                     // frees the queue

        return 0;
}
```
## Notes
uint64_t is the size of the queue, therefore comparisons of size must be to zero (unlike other implementations which might use size = -1 to initialize queue). 

It is assumed that the queue will never have more than 2^64 elements (as in the back).

It is assumed that the user will grab only 1 element size from the memory position returned from check_queue_front check_queue_back.

## Contributions

Contributions are welcome! If you find any issues or have ideas for improvement, feel free to open an issue or submit a pull request.

## License

This project is licensed under the Unlicense license. See the `LICENSE` file for more details.
