

#include "queue.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void single_queue_simple_test()
{

        void *queue1 = NULL;
        uint16_t data_test = 0;

        create_queue(&queue1, sizeof(uint16_t), 0);

        printf("%u\n",check_queue_is_empty(queue1));
        

        data_test = 1;
        queue_push(queue1,(void*) &data_test);

        data_test = 2;
        queue_push(queue1,(void*) &data_test);
        
        data_test = 3;
        queue_push(queue1,(void*) &data_test);
        

        printf("%u\n", *((uint16_t*)check_queue_front(queue1)));
        queue_pop(queue1);

        printf("%u\n", *((uint16_t*)check_queue_front(queue1)));
        queue_pop(queue1);

        printf("%u\n", *((uint16_t*)check_queue_front(queue1)));


        printf("%lu\n",check_queue_size(queue1));

        free_queue(queue1);

        return ;
}


/* High memory usage test */
void queue_stress_test1()
{
        void *queue1=NULL;
        uint16_t data1=0; 

        create_queue(&queue1,sizeof(uint16_t),100);

        // uint64_t n = 400000000;
        uint64_t n = 400000;
        
        while(0 < n)
        {
                
                if(NULL != check_queue_front(queue1))
                {
                        // printf("%lu",*((uint16_t*)check_queue_top(queue1)));
                }

                data1++;
                queue_push(queue1, (void*) &data1);
                n--;



        }
        while(!check_queue_is_empty(queue1))
        {
                queue_pop(queue1);
                // printf("%lu",check_queue_size(queue1));
        }

        free_queue(queue1);

}

void queue_stress_test2()
{
        void *queue1=NULL;
        void *queue2=NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        create_queue(&queue1,sizeof(uint16_t),5);
        create_queue(&queue2,sizeof(uint16_t),5);

        uint64_t n = 4000000;
        // uint64_t n = 4000000;
        
        while(0 < n)
        {
                queue_pop(queue1);
                queue_pop(queue2);
                data1++;
                data2++;
                queue_push(queue1, (void*) &data1);
                queue_push(queue2, (void*) &data2);
                n--;        
        }
        while(!check_queue_is_empty(queue1))
        {
                queue_pop(queue1);
                // printf("%lu",check_queue_size(queue1));
        }

        free_queue(queue1);
        free_queue(queue2);

}

/* Array of queues test */
void queue_stress_test3()
{
        void **queues=NULL;
        
        uint64_t num_of_queues = 20000;
        queues = (void **) malloc(num_of_queues* sizeof(void *));
        if(queues == NULL)
        {
                perror("");
                return ;
        }
        uint16_t data1=20;

        for(uint64_t i=0;i<num_of_queues;i++)
        {
                create_queue(&(queues[i]),sizeof(uint16_t),2);
                
                queue_push(queues[i], (void*) &data1);
                queue_push(queues[i], (void*) &data1);
        }

        for(uint64_t i=0;i<num_of_queues;i++)
        {

                while(!check_queue_is_empty(queues[i]))
                {
                if(NULL != check_queue_front(queues[i]))
                {
                        printf("%u ",*((uint16_t*)check_queue_front(queues[i])));
                }

                queue_pop(queues[i]);
                
                // printf("%lu",check_queue_size(queue1));
                }
        }

        for(uint64_t i=0;i<num_of_queues;i++)
        {
                free_queue(queues[i]);
        }        
        free(queues);
        
}

/* Random Operations test*/
void queue_stress_test4()
{
        void *queue1=NULL;
        uint16_t data1=0; 
        srand(time(NULL));                      
       
        create_queue(&queue1,sizeof(uint16_t),100);

        // uint64_t n = 400000000;
        uint64_t operations = 400000;

        
        while(0 < operations)
        {
                uint8_t op_to_do = rand() % 6;          
                switch (op_to_do)
                {
                case 0:                                         // queue_push
                        queue_push(queue1, (void*) &data1);
                        break;
                case 1:                                         // queue_pop
                        queue_pop(queue1);
                        break; 
                case 2:                                         // check_queue_front
                       if(NULL != check_queue_front(queue1))
                        {
                                printf("queue front: %u\n",*((uint16_t*)check_queue_front(queue1)));
                        }
                        break; 
                case 3:
                        if(NULL != check_queue_back(queue1))
                        {
                                printf("queue back: %u\n",*((uint16_t*)check_queue_back(queue1)));
                        }
                        break; 
                case 4:                                         // check_queue_is_empty
                        printf("queue empty?: %u\n",check_queue_is_empty(queue1));
                        break; 
                case 5:                                         // check_queue_size
                        printf("queue size: %lu\n",check_queue_size(queue1));
                        break; 
                default:
                        break;
                }



                data1++;
                operations--;
        }

        free_queue(queue1);    


}


void tutorial()
{
        void *queue1 = NULL;
        create_queue(&queue1, sizeof(uint16_t),5);                              // create a queue of 5 elements of uint16_t size

        uint16_t data1 = 3;
        queue_push(queue1,(void*) &data1);                                      // Push a value onto the queue
        
        data1 = 20;
        queue_push(queue1,(void*) &data1);                                  // Push another value onto the queue

        if(!check_queue_is_empty(queue1))                                       // Checks if queue is not empty 
        {
                printf("%u\n",*((uint16_t*)check_queue_front(queue1)));         // prints top of queue
        }

        if(!check_queue_is_empty(queue1))                                       // Checks if queue is not empty 
        {
                printf("%u\n",*((uint16_t*)check_queue_back(queue1)));         // prints top of queue
        }


        queue_pop(queue1);                                                      // Pops a value from the queue

        printf("%lu\n",check_queue_size(queue1));                               // prints size of the queue

        free_queue(queue1);                                                     // frees the queue

        return ;



}


int main()
{

        // queue_stress_test1();
        // queue_stress_test2();
        // queue_stress_test3();
        // queue_stress_test4();
        tutorial();
        // single_queue_simple_test();
        
        return 0;  
}