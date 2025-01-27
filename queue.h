
/*******************************************************************************************************
* NAME: queue.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a queue implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 14-01-2025    Tiago Rodrigues                       1         File preparation     
* 14-01-2025    Tiago Rodrigues                       1         Added prototype functions                                                                                                       
* 23-01-2025    Tiago Rodrigues                       1         Further changed queue prototypes
* 27-01-2025    Tiago Rodrigues                       1         Added comments to functions
*                                                                                                      
*******************************************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

/* 0 copyright/licensing */
/**********************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
***********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif



/* 1 includes */
/*****************************************************/
#include <stdint.h>

/*****************************************************/

/* 2 defines */
/*****************************************************/

/*****************************************************/

/* 3 external declarations */
/*****************************************************/

/*****************************************************/

/* 4 typedefs */
/*****************************************************/

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_queue       
*
* PURPOSE: Allocates the needed memory for the queue wanted
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue	        void**	        I/O	pointer to the memory position of the queue to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the queue
* elements_to_allocate  uint64_t        I       number of elements to allocate for the queue
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_queue(void** id_of_queue, uint64_t size_of_datatype, uint64_t elements_to_allocate);



/******************************************************************
*
* FUNCTION NAME: check_queue_front
*
* PURPOSE: Returns the memory position of the element that is currently on the front of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
* 
*
* RETURNS: void* (pointer to the memory position of the element at the front of the queue)
*
*
*
*****************************************************************/
void* check_queue_front(void* id_of_queue);




/******************************************************************
*
* FUNCTION NAME: check_queue_back    
*
* PURPOSE: Returns the memory position of the element that is currently on the back of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
* 
*
* RETURNS: void* (pointer to the memory position of the element at the back of the queue)
*
*
*
*****************************************************************/
void* check_queue_back(void* id_of_queue);


/******************************************************************
*
* FUNCTION NAME: queue_pop
*
* PURPOSE: Removes one position from the front of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to pop from
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void queue_pop(void* id_of_queue);


/******************************************************************
*
* FUNCTION NAME: queue_push
*
* PURPOSE: Pushes an element to the back of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to which the element is being push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the queue
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void queue_push(void* id_of_queue, void* data_to_push);


/******************************************************************
*
* FUNCTION NAME: check_queue_is_empty
*
* PURPOSE: Checks if the queue is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t check_queue_is_empty(void* id_of_queue);



/******************************************************************
*
* FUNCTION NAME: check_queue_size
*
* PURPOSE: Will return the current element count in the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
*
*
* RETURNS: uint64_t (size of the queue)
*
*
*
*****************************************************************/
uint64_t check_queue_size(void* id_of_queue);



/******************************************************************
*
* FUNCTION NAME: free_queue
*
* PURPOSE: Frees the memory allocated for the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue   void*	        I	pointer to the memory position of the queue to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_queue(void* id_of_queue);





#ifdef __cplusplus
}
#endif


#endif

























