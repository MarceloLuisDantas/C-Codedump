#include <stdint.h>

// 64KB de RAM 
typedef struct RAM {
    /* Cada instrução ocupa 1 index (1 linha)
        
    xFFFF |--------------|  xFFFF (65535) | De xC000 a xFFFF é a memoria de programa
          |              |                | Totalizando 16383 possiveis instruções
          |              |                |  
          |--------------|  xC000 (49152) |  
          |              |  xBFFF (49151)     
          |              |  
          |              |       
          |              |  
          |              |    
          |              |
          |              |    
          |              |
    x0000 |--------------| x0000 (0)
          


    */
    int16_t program_mem[16383]
};

 