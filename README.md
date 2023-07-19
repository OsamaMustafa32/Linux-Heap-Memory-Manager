# Linux-Heap-Memory-Manager
This project is about designing a Heap memory manager which will handle the memory requests of the user space processes. It also takes care of the problems of internal fragmentation, external fragmentation, and boost performance of the process by preventing unnecessary system calls for allocating/releasing the memory.

The memory manager can display the statistics regarding the memory usage by each structure of the process. From this stats, application memory usage can be analyzed and can provide hints to further optimize the memory requirements of the process.

The memory manager requests and releases memmory from kernel space on behalf of application in units of Virtual Memory Pages. It uses mmap() and munmap() system calls for this purpose. It caches the VM pages and use it as reservoir for future memory requests issued by the application, until the VM page is fully exhausted. VM page is released back to kernel if application has freed enough Memory such that VM page has no region occupied/allocated to the application for use.

Main tasks: 
- Block Splitting and Merging
- Glue way Doubly linked list for maintaining free and allocated blocks 
- Memory allocation techniques for allocating memory to the processes

Compilations:
- gcc -g -c testApp.c -o testApp.o
- gcc -g -c memoryManager.c -o memoryManager.o
- gcc -g -c gluethread/glthread.c -o gluethread/glthread.o
- gcc -g gluethread/glthread.o memoryManager.o testApp.o -o test.exe

Execution: ./test.exe

![Screenshot from 2023-07-20 02-06-08](https://github.com/OsamaMustafa32/Linux-Heap-Memory-Manager/assets/53177552/91e4ec02-ea3c-4f73-b24d-194d08936bbe)
![Screenshot from 2023-07-20 02-06-36](https://github.com/OsamaMustafa32/Linux-Heap-Memory-Manager/assets/53177552/d449896f-a1f8-4903-96eb-ea91048c87ff)

