

#include "queue.h"
#include <stdio.h>

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



int main()
{
        single_queue_simple_test();
        
        return 0;  
}