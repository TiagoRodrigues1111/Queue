/*******************************************************************************************************************
* FILE NAME: queue.c
*                                                                                                               
* PURPOSE: This file implements the functions defined in queue.h, with an array 
*                                                                                                               
* FILE REFERENCES:                                                                                              
*                                                                                                               
* Name                          I/O                     Description                                             
* ----                          ---                     -----------                                             
* none     
                                                                                                          
* EXTERNAL VARIABLES:                                                                                           
*                                                                                        
*                                                                                                               
* Name          Type            I/O                     Description                                             
* ----          ----            ---                     -----------                                             
* none
*
*                                                                                                             
* EXTERNAL REFERENCES:                                                                                          
* Name                          Description                                                                     
* ----                          -----------                                                                     
* malloc                        allocates memory space                                                          https://man7.org/linux/man-pages/man3/free.3.html
* realloc                       reallocates memory space                                                        https://man7.org/linux/man-pages/man3/realloc.3p.html
* memcpy                        copies x number of bytes from one memory position to another memory position    https://man7.org/linux/man-pages/man3/memcpy.3.html
* fprintf                       writes formatted data to a stream                                               https://man7.org/linux/man-pages/man3/fprintf.3p.html
*     
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:                                                  
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                                                       
*  It is assumed that the queue will never have more than 2^64 elements.                               
*  It is assumed that the user will grab only 1 element size from the memory position returned from check_queue_front and check_queue_back 
*
*
*
* NOTES:                                                                                                        
*
*
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                                                            
*
*                                                                                                               
* DEVELOPMENT HISTORY:                                                                                          
*                                                                                                               
* Date          Author                  Change Id       Release         Description Of Change                   
* ----------    ---------------         ---------       -------         ---------------------   
* 14-01-2025    Tiago Rodrigues                               1         File preparation   
* 23-01-2025    Tiago Rodrigues                               1         Initial queue implementation     
* 27-01-2025    Tiago Rodrigues                               1         Added comments to functions
*                                                                                                               
* ALGORITHM (PDL)
*    
*
*                                                                                                           
****************************************************************************************************************/


/* 0 copyright/licensing */
/***************************************************************************************************************/
/*
*       2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*/
/***************************************************************************************************************/


/* 1 includes */
/*****************************************************/

#include "queue.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*****************************************************/


/* 2 defines */
/*****************************************************/
#define INITIAL_ALLOC 3

/*****************************************************/


/* 3 external declarations */
/*****************************************************/

/*****************************************************/


/* 4 typedefs */
/*****************************************************/


/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/

// Possible solutions:  queue_front and queue_size (increment to find the back )
//                      queue_front and queue_back (initiate queue_back as always +1 than it should )
struct queue
{
        uint64_t queue_front;
        uint64_t queue_back;
        uint64_t queue_size;
        uint64_t queue_size_allocated;                  // num_of_elements
        uint64_t datatype_size;                         // num_of_bytes
        uint64_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        void *queue_data;
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
void create_queue(void** id_of_queue, uint64_t size_of_datatype, uint64_t elements_to_allocate)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return ;
        }
                

        // Allocation of a queue struct
        (*id_of_queue) = malloc(1*sizeof(struct queue));                       
        if(NULL == *id_of_queue)
        {
                perror("Memory allocation failed");
                return ;
        }

        if(0 == elements_to_allocate)
                ((struct queue*)(*id_of_queue))->queue_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                ((struct queue*)(*id_of_queue))->queue_size_allocated = elements_to_allocate;

        ((struct queue*)(*id_of_queue))->queue_front = 0;
        ((struct queue*)(*id_of_queue))->queue_back = 0;
        ((struct queue*)(*id_of_queue))->queue_size = 0;
        ((struct queue*)(*id_of_queue))->datatype_size = size_of_datatype;
        ((struct queue*)(*id_of_queue))->k_aux = 1;
        
        // Allocate space in the queue for the array of values
        ((struct queue*)(*id_of_queue))->queue_data = (void*) malloc(((struct queue*)(*id_of_queue))->queue_size_allocated*((struct queue*)(*id_of_queue))->datatype_size);     
        if(NULL == ((struct queue*)(*id_of_queue))->queue_data)
        {
                perror("Memory allocation failed");
                return ;
        }
        
        return ;        
}



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
void* check_queue_front(void* id_of_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return NULL;
        }
               

        if(check_queue_is_empty(id_of_queue))                       
                return NULL;

        return (void *) &((uint8_t*)(((struct queue*)id_of_queue)->queue_data))[(((struct queue*)id_of_queue)->queue_front)*((struct queue*)id_of_queue)->datatype_size];       



}

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
void* check_queue_back(void* id_of_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return NULL;
        }
               

        if(check_queue_is_empty(id_of_queue))                       
                return NULL;

        return (void *) &((uint8_t*)(((struct queue*)id_of_queue)->queue_data))[(((struct queue*)id_of_queue)->queue_back)*((struct queue*)id_of_queue)->datatype_size];  




}




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
void queue_pop(void* id_of_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return ;
        }   
        if(!check_queue_is_empty(id_of_queue))
        {
                ((struct queue*)id_of_queue)->queue_size--;
                if(!check_queue_is_empty(id_of_queue))
                        ((struct queue*)id_of_queue)->queue_front++;                            // TODO: if front is at end of array, front is decremented instead
        }
        return;

}



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
void queue_push(void* id_of_queue, void* data_to_push)
{
       /* LOCAL VARIABLES:
        *  Variable     Type    Description
        *  --------     ----    -----------
        *  queue_aux    void*   auxiliary pointer for the realloc operation
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return ;
        }
        if(UINT64_MAX == ((struct queue*)id_of_queue)->queue_back)
        {
                fprintf(stderr, "Queue full, can't add more elements\n");
                return ;
        }


        if(!check_queue_is_empty(id_of_queue))                                  //caution (left == right will not work, because they are the same for 1 element)
                 ((struct queue*)id_of_queue)->queue_back++;
        
        ((struct queue*)id_of_queue)->queue_size++;
       
        // reallocate memory if num of elements in queue becomes larger than the max num of elements allocated for the queue (has to be >= because queue_back is zero for first element)
        if(((struct queue*)id_of_queue)->queue_back >= ((struct queue*)id_of_queue)->queue_size_allocated)               // TODO: better implementation to prevent uncontrollable increase in empty queue space
        {

                void* queue_aux = NULL;
                if(1 == (((struct queue*)id_of_queue)->k_aux))
                {
                        queue_aux = realloc(((struct queue*)id_of_queue)->queue_data, (((struct queue*)id_of_queue)->queue_size_allocated + ((struct queue*)id_of_queue)->queue_size_allocated)*((struct queue*)id_of_queue)->datatype_size);
                        if(NULL != queue_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                        {
                                ((struct queue*)id_of_queue)->queue_size_allocated <<= 1;
                        }
                }
                else
                {
                        while (NULL == queue_aux)
                        {
                                perror("Memory reallocation failed");
                                printf("Attempting smaller reallocation\n");
                                (((struct queue*)id_of_queue)->k_aux)<<=1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                                 
                                if(0 == (((struct queue*)id_of_queue)->queue_size_allocated/(((struct queue*)id_of_queue)->k_aux)))
                                {
                                        fprintf(stderr, "Impossible to reallocate queue\n");
                                        //perror("Impossible to reallocate queue");
                                        return ;
                                }
                                queue_aux = realloc(((struct queue*)id_of_queue)->queue_data, (((struct queue*)id_of_queue)->queue_size_allocated + (((struct queue*)id_of_queue)->queue_size_allocated / (((struct queue*)id_of_queue)->k_aux)))*((struct queue*)id_of_queue)->datatype_size);
                        }

                        ((struct queue*)id_of_queue)->queue_size_allocated += (((struct queue*)id_of_queue)->queue_size_allocated/(((struct queue*)id_of_queue)->k_aux));          
                }
                
                ((struct queue*)id_of_queue)->queue_data = queue_aux;

        }

        memcpy(check_queue_back(id_of_queue), data_to_push, ((struct queue*)id_of_queue)->datatype_size);

        return ;

}



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
uint8_t check_queue_is_empty(void* id_of_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return 0;
        }
                
        if(0 == ((struct queue*)id_of_queue)->queue_size)
                return 1;
        else
                return 0;


}


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
uint64_t check_queue_size(void* id_of_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return 0;
        }

        return ((struct queue*)id_of_queue)->queue_size;



}

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
void free_queue(void* id_of_queue)
{

        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_queue)
                return;

        if(NULL != ((struct queue*)id_of_queue)->queue_data)
                free(((struct queue*)id_of_queue)->queue_data);
        
        free(id_of_queue);
        return ;


}