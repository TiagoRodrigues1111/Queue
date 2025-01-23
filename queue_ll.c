/*******************************************************************************************************************
* FILE NAME: queue_ll.c
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
* 23-01-2025    Tiago Rodrigues                               1         Implementation of queue using a linked list     
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

        ((struct queue*)(*id_of_queue))->queue_front = NULL;
        ((struct queue*)(*id_of_queue))->queue_back = NULL;
        ((struct queue*)(*id_of_queue))->queue_size = 0;
        ((struct queue*)(*id_of_queue))->datatype_size = size_of_datatype;
        
        
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
               

        // if(check_queue_is_empty(id_of_queue))                       
        //        return NULL;

        if(NULL != ((struct queue*)id_of_queue)->queue_front)
                return ((struct queue*)id_of_queue)->queue_front->data_element;
  

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
               

        if(NULL != ((struct queue*)id_of_queue)->queue_back)
                return ((struct queue*)id_of_queue)->queue_back->data_element;




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