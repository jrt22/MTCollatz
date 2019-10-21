# MTCollatz
Significant problems:

1) 2 errors with pthread_create.  
      - invalid conversion from void* (*) (void*&) to void* (*) (void*)
      - initializing argument 
      
2) Segmentation fault (no command line arguments)

3) Makefile compile issues (missing -lpthread flag at compile)
