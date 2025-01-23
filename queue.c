/*******************************************************************************************************************
* FILE NAME: queue.c
*                                                                                                               
* PURPOSE: 
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
*   
* 
*    
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:                                                  
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                                                       
*                                
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
* 
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
* FUNCTION NAME:       
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* 
*
*
* RETURNS:   
*
*
*
*****************************************************************/
void create_queue(void** id_of_queue, uint64_t size_of_datatype, uint64_t elements_to_allocate)
{

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

        if(0 == elements_to_allocate)
                ((struct queue*)(*id_of_queue))->queue_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                ((struct queue*)(*id_of_queue))->queue_size_allocated = elements_to_allocate;

        ((struct queue*)(*id_of_queue))->queue_front = 0;
        ((struct queue*)(*id_of_queue))->queue_back = 0;
        ((struct queue*)(*id_of_queue))->queue_size = 0;
        ((struct queue*)(*id_of_queue))->datatype_size = size_of_datatype;
        
        // Allocate space in the queue for the array of values
        ((struct queue*)(*id_of_queue))->queue_data = (void*) malloc(((struct queue*)(*id_of_queue))->queue_size_allocated*((struct queue*)(*id_of_queue))->datatype_size);     
        if(NULL == ((struct queue*)(*id_of_queue))->queue_data)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }
        
        return ;        
}



/******************************************************************
*
* FUNCTION NAME:       
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* 
*
*
* RETURNS:   
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
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS:
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
* FUNCTION NAME:       
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* 
*
*
* RETURNS:   
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
                ((struct queue*)id_of_queue)->queue_front++;                            // TODO: if front is at end of array, front is decremented instead
        }
        return;

}



/******************************************************************
*
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS:
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
        
        if(!check_queue_is_empty(id_of_queue))                                  //caution (left == right will not work, because they are the same for 1 element)
                 ((struct queue*)id_of_queue)->queue_back++;
        ((struct queue*)id_of_queue)->queue_size++;
       
        // reallocate memory if num of elements in queue becomes larger than the max num of elements allocated for the queue 
        if(((struct queue*)id_of_queue)->queue_back > ((struct queue*)id_of_queue)->queue_size_allocated)               // TODO: better implementation to prevent uncontrollable increase in empty queue space
        {
                // tries to allocate double the size of the current queue;
                void* queue_aux = realloc(((struct queue*)id_of_queue)->queue_data, (((struct queue*)id_of_queue)->queue_size_allocated + ((struct queue*)id_of_queue)->queue_size_allocated)*((struct queue*)id_of_queue)->datatype_size); 
                if(NULL == queue_aux)
                {
                        fprintf(stderr, "Memory allocation failed\n");
                }
                ((struct queue*)id_of_queue)->queue_data = queue_aux;
                ((struct queue*)id_of_queue)->queue_size_allocated <<= 1;
        }

        memcpy(check_queue_back(id_of_queue), data_to_push, ((struct queue*)id_of_queue)->datatype_size);

        return ;

}



/******************************************************************
*
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS:
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
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS:
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
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS:
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