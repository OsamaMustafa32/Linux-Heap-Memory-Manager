#include "user_api.h"
#include <stdio.h>
#include <assert.h>
typedef struct company_ {

    char name[32];
    char role_offered[32];
} company_t;

typedef struct student_ {

    char name[32];
    char course[32];
    uint32_t percentage;
    char eligible;
    struct student_ *next;
} student_t;

int
main(int argc, char **argv){

    int wait;
    mm_init();
    MM_REG_STRUCT(company_t);
    MM_REG_STRUCT(student_t);
    mm_print_registered_page_families();
    
    company_t *cmp1 = XCALLOC(1, company_t);
    company_t *cmp2 = XCALLOC(1, company_t);
    company_t *cmp3 = XCALLOC(2, company_t);

    student_t *stud1 = XCALLOC(1, student_t);
    student_t *stud2 = XCALLOC(3, student_t);

    printf(" \nSCENARIO 1 : *****ALLOCATION OF MEMORY****** \n");
    mm_print_memory_usage(0);
    mm_print_block_usage();

    printf("\n\nEnter any key: ");
    scanf("%d", &wait); 

    XFREE(cmp1);
    XFREE(cmp3);
    XFREE(stud2);
    printf(" \nSCENARIO 2 : *****DE-ALLOCATION OF MEMORY****** \n");
    mm_print_memory_usage(0);
    mm_print_block_usage();

    
    XFREE(cmp2);
    XFREE(stud1);
    printf(" \n\nSCENARIO 3 : *****ALL ALLOCATED MEMORY FREED****** \n");
    mm_print_memory_usage(0);
    mm_print_block_usage();
    return 0;
}
