#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "main.h"
#include "my_utility.h"


typedef enum 
{
    STATUS_SUCCESS,
    STATUS_FAILURE
}status_e;


typedef struct tagNode 
{
    Employee eData;
    struct tagNode* pnext;
    struct tagNode* pprevious;
}Node_t;


typedef struct employeeList 
{
    Node_t* mp_first;
    Node_t* last_addr;
    size_t mp_list_size;
    uint32_t linkedlist_err;
}eemployeeList_t;

//struct employeeList;
typedef void* ListHandle;
typedef eemployeeList_t* employeeList_ptr;

ListHandle create_list(void);
static size_t is_empty(ListHandle h);
void print_list(ListHandle h);
size_t get_size_list(ListHandle h);
Node_t* get_last_node(ListHandle h);
status_e push_back(ListHandle h, Employee* edata);
status_e push_front(ListHandle h, Employee* edata);
status_e pop_node(ListHandle h, const char* name);
status_e pop_head(ListHandle h);
status_e pop_back(ListHandle h);
status_e bubble_sort(ListHandle h);
uint32_t get_linkedlist_error(ListHandle h);


#endif
