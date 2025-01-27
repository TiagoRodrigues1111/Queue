/*******************************************************************************************************************
* FILE NAME: queue_ll.c
*                                                                                                               
* PURPOSE: This file implements the functions defined in queue.h, with a linked list
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
* memcpy                        copies x number of bytes from one memory position to another memory position    https://man7.org/linux/man-pages/man3/memcpy.3.html
* fprintf                       writes formatted data to a stream                                               https://man7.org/linux/man-pages/man3/fprintf.3p.html
* 
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
* 23-01-2025    Tiago Rodrigues                               1         Implementation of queue using a linked list     
* 27-01-2025    Tiago Rodrigues                               1         Added Comments to functions  
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

/*****************************************************/


/* 3 external declarations */
/*****************************************************/

/*****************************************************/


/* 4 typedefs */
/*****************************************************/


/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/

struct data
{
        void *data_element;
        struct data *next;
};


struct queue
{
        uint64_t datatype_size;                         
        uint64_t queue_size;                                    // needed for the check_size(otherwise O(k))
        struct data *queue_front;
        struct data *queue_back; 

        // struct data *queue_data;
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
* --------	-----------	---	--------------------------
* id_of_queue	        void**	        I/O	pointer to the memory position of the queue to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the queue
* elements_to_allocate  uint64_t        I       number of elements to allocate for the queue
*
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
                fprintf(stderr, "Memory allocation failed\n");
        }

        ((struct queue*)(*id_of_queue))->queue_front = NULL;
        ((struct queue*)(*id_of_queue))->queue_back = NULL;
        ((struct queue*)(*id_of_queue))->queue_size = 0;
        ((struct queue*)(*id_of_queue))->datatype_size = size_of_datatype;
        
        
        return ;        
}



/******************************************************************
*
* FUNCTION NAME: check_queue_front
*
* PURPOSE: Returns the memory position of the element that is currently on the front of the queue
*
* ARGUMENTS: Returns the memory position of the element that is currently on the front of the queue
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
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
               

        // if(check_queue_is_empty(id_of_queue))                       
        //        return NULL;

        if(NULL != ((struct queue*)id_of_queue)->queue_front)
                return ((struct queue*)id_of_queue)->queue_front->data_element;
  

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
* --------	-------------	---	--------------------------
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
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
               

        if(NULL != ((struct queue*)id_of_queue)->queue_back)
                return ((struct queue*)id_of_queue)->queue_back->data_element;




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
* --------	-----------	---	--------------------------
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
        *  Variable        Type         Description
        *  --------        ----         -----------
        *  aux_ptr         struct data* pointer to data node to be removed
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return ;
        }   
        if(!check_queue_is_empty(id_of_queue))
        {
                

                struct data *aux_ptr = ((struct queue*)id_of_queue)->queue_front;

                ((struct queue*)id_of_queue)->queue_front = ((struct queue*)id_of_queue)->queue_front->next;

                free(aux_ptr->data_element);
                free(aux_ptr);

                ((struct queue*)id_of_queue)->queue_size--;

                if(0 == ((struct queue*)id_of_queue)->queue_size)
                        ((struct queue*)id_of_queue)->queue_back = NULL;                        // TODO: check if there are other places where this might be a problem

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
* --------	-------------	---	--------------------------
* id_of_queue   void*	        I	pointer to the memory position of the queue to which the element is being push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the queue
*
* RETURNS: void
*
*
*
*****************************************************************/
void queue_push(void* id_of_queue, void* data_to_push)
{
       /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ------------    -----------
        *  aux_data_ptr struct data*    pointer to the new node to allocate and push into the queue
        */
        if(NULL == id_of_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return ;
        }

        
        // Allocate space in the queue for the array of values
        struct data *aux_data_ptr = (struct data*) malloc(1*sizeof(struct data));   
        if(NULL == aux_data_ptr)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }

        aux_data_ptr->data_element = (void*) malloc(1*((struct queue*)id_of_queue)->datatype_size);
        if(NULL == aux_data_ptr->data_element)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }
        
        memcpy(aux_data_ptr->data_element, data_to_push, ((struct queue*)id_of_queue)->datatype_size);
        aux_data_ptr->next = NULL;

        if(0 == ((struct queue*)id_of_queue)->queue_size)
        {
                ((struct queue*)id_of_queue)->queue_front = aux_data_ptr;
                ((struct queue*)id_of_queue)->queue_back = aux_data_ptr;
        }
        else
        {
                ((struct queue*)id_of_queue)->queue_back->next = aux_data_ptr;
                ((struct queue*)id_of_queue)->queue_back = ((struct queue*)id_of_queue)->queue_back->next;
        }

        ((struct queue*)id_of_queue)->queue_size++;


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
* --------	-------------	---	--------------------------
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
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
* --------	-------------	---	--------------------------
* id_of_queue   void*	        I	pointer to the memory position of the queue to check
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
* --------	-------------	---	--------------------------
* id_of_queue   void*	        I	pointer to the memory position of the queue to free
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_queue(void* id_of_queue)
{

        /* LOCAL VARIABLES:
        *  Variable        Type         Description
        *  --------        ------------ -----------
        *  aux_data_ptr    struct data* auxiliary pointer to data node to deallocate
        */
        if(NULL == id_of_queue)
                return;

        struct data *aux_data_ptr = ((struct queue*)id_of_queue)->queue_front; 

        while(NULL != (((struct queue*)id_of_queue)->queue_front))
        {
                ((struct queue*)id_of_queue)->queue_front = ((struct queue*)id_of_queue)->queue_front->next;
                free(aux_data_ptr->data_element);
                free(aux_data_ptr);
                aux_data_ptr = ((struct queue*)id_of_queue)->queue_front;
        }

        free(id_of_queue);
        return ;


}