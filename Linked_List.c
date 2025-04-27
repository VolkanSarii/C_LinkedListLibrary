#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "Linked_List.h"
#include "my_utility.h"

#define FUNC_SET_ERROR(err)       (ptr->linkedlist_err |= err)
#define FUNC_GET_ERROR(err)       (ptr->linkedlist_err & err )
#define FUNC_CLEAN_ERROR(err)     (ptr->linkedlist_err &= (~err))
#define FUNC_STATE_ERROR()        (ptr->linkedlist_err) 


#define PUSHB_NOT_NODE      (0x00000001) /* error code that node does not occur in push_back function                   */
#define PUSHB_NOT_HANDLE    (0x00000002) /* error code when the argument of the push_back function is a NULL pointer    */
#define PUSHF_NOT_NODE      (0x00000004) /* error code that node does not occur in push_front function                  */
#define POP_NODE_FUNC       (0x00000008) /* error code when the argument of the pop_node function is a NULL pointer     */

#define POP_HEAD_FUNC       (0x00000010) /* error code that node does not occur in pop_head_func function               */
#define POP_BACK_FUNC       (0x00000020) /* error code that node does not occur in pop_back_func function               */
#define BUBBLE_SORT_FUNC    (0x00000040) /* error code that node does not occur in bubble_sort_func function            */

/**
 * @brief Creates a new node of type Node_t.
 *
 * This function dynamically allocates memory for a new node and initializes
 * its pointers to NULL. If memory allocation fails, it prints an error
 * message and returns NULL.
 *
 * @retval Node_t* Pointer to the newly created node if successful.
 * @retval NULL If memory allocation fails.
 */
static Node_t* create_node(void)
{
    Node_t* p = (Node_t*)malloc(sizeof(Node_t));

    if (!p)
    {
        printf("bellek yetersiz, Node oluþturulamadý");
        return NULL;
    }

    p->pnext = NULL;
    p->pprevious = NULL;

    return p;
}

/**
 * @brief Retrieves the last node in the list.
 *
 * This function returns a pointer to the last node in the linked list
 * referenced by the given list handle. The list handle is cast to
 * an internal structure type to access the last node's address.
 *
 * @param h The handle to the linked list (ListHandle).
 * @retval Node_t* Pointer to the last node in the list.
 */
static Node_t* get_last_node(ListHandle h)
{
    employeeList_ptr ptr = (employeeList_ptr)h;
    return ptr->last_addr;
}

 /**
  * @brief Checks if the linked list is empty.
  *
  * This function determines whether the linked list referenced by the
  * given handle is empty by checking the size of the list.
  *
  * @param h The handle to the linked list (ListHandle).
  * @retval size_t Returns 1 if the list is empty, 0 otherwise.
  */
static size_t is_empty(ListHandle h)
{
    employeeList_ptr ptr = (employeeList_ptr)h;
    return (ptr->mp_list_size == 0);
}

 /**
  * @brief Creates a new linked list.
  *
  * This function allocates memory for a new linked list structure and
  * initializes its fields. The list starts as empty, with no nodes and
  * a size of 0. If memory allocation fails, an error message is printed,
  * and the function returns NULL.
  *
  * @retval ListHandle Pointer to the newly created list if successful.
  * @retval NULL If memory allocation fails.
  */
ListHandle create_list(void)
{
    ListHandle p = (ListHandle)malloc(sizeof(eemployeeList_t));
    employeeList_ptr ptr = (employeeList_ptr)p;

    if (!p)
    {
        printf("bellek yetersiz\n");
        return NULL;
    }
    ptr->mp_first = NULL;
    ptr->mp_list_size = 0;
    ptr->linkedlist_err = 0;

    return p;
}

/**
 * @brief Adds a new node to the end of the linked list.
 *
 * This function creates a new node and appends it to the end of the
 * linked list. The new node's data is populated with the provided
 * employee data. If the list is empty, the new node becomes the first
 * node in the list. The function also updates the list's size and the
 * pointer to the last node.
 *
 * If memory allocation for the new node fails or if the provided list
 * handle is invalid, the function logs an error and returns a failure status.
 *
 * @param h The handle to the linked list (ListHandle).
 * @param edata Pointer to the employee data to be added to the new node.
 *
 * @retval STATUS_SUCCESS If the node is successfully added to the list.
 * @retval STATUS_FAILURE If an error occurs (e.g., memory allocation failure
 *         or invalid list handle).
 */
status_e push_back(ListHandle h, Employee* edata)
{
    Node_t* p_new_node = create_node();
    employeeList_ptr ptr = (employeeList_ptr)h;

    if (p_new_node == NULL)
    {
        printf("push_back fonk. yeni node olusturulamadi\n");
        FUNC_SET_ERROR(PUSHB_NOT_NODE);
        return STATUS_FAILURE;
    }

    if (ptr == NULL)
    {
        printf("push_back fonksiyonda yeni list oluþturuldu\n");
        FUNC_SET_ERROR(PUSHB_NOT_HANDLE);
        return STATUS_FAILURE;
    }

    p_new_node->eData = *edata;


    if (ptr->mp_first == NULL)
    {
        ptr->mp_first = p_new_node;
    }
    else
    {
        Node_t* iter = ptr->mp_first;

        while (iter->pnext != NULL)
        {
            iter = iter->pnext;
        }

        p_new_node->pprevious = iter;
        iter->pnext = p_new_node;
        ptr->last_addr = p_new_node;
    }

    ++ptr->mp_list_size;


    FUNC_CLEAN_ERROR(PUSHB_NOT_NODE);
    FUNC_CLEAN_ERROR(PUSHB_NOT_HANDLE);
    return STATUS_SUCCESS;
}

/**
 * @brief Adds a new node to the front of the linked list.
 *
 * This function creates a new node and inserts it at the beginning of the
 * linked list. The new node's data is populated with the provided
 * employee data. The function also updates the list's size. If the list
 * is empty, the new node becomes the first node in the list.
 *
 * If memory allocation for the new node fails or if the list is empty,
 * the function logs an error and returns a failure status.
 *
 * @param h The handle to the linked list (ListHandle).
 * @param edata Pointer to the employee data to be added to the new node.
 *
 * @retval STATUS_SUCCESS If the node is successfully added to the front of
 *         the list.
 * @retval STATUS_FAILURE If an error occurs (e.g., memory allocation failure
 *         or invalid list handle).
 */
status_e push_front(ListHandle h, Employee* edata)
{
    Node_t* p_new_node = create_node();
    employeeList_ptr ptr = (employeeList_ptr)h;

    if (is_empty(h))
    {
        printf("push_head fonksiyonunda geçici node oluþturulamadý");
        FUNC_SET_ERROR(PUSHF_NOT_NODE);
        return STATUS_FAILURE;
    }

    p_new_node->eData = *edata;

    p_new_node->pnext = ptr->mp_first;
    p_new_node->pprevious = NULL;

    if (ptr->mp_first)
        ptr->mp_first->pprevious = p_new_node;

    ptr->mp_first = p_new_node;

    ++ptr->mp_list_size;

    FUNC_CLEAN_ERROR(PUSHF_NOT_NODE);
    return STATUS_SUCCESS;
}

/**
 * @brief Removes a node with the specified employee name from the linked list.
 *
 * This function searches for a node containing the employee's name in the list
 * and removes it. If the node is found, it adjusts the pointers of adjacent
 * nodes to maintain the list integrity. The list's size is also updated. If
 * the node is not found or if the list is empty, an error message is printed
 * and a failure status is returned.
 *
 * @param h The handle to the linked list (ListHandle).
 * @param name The name of the employee whose node is to be removed.
 *
 * @retval STATUS_SUCCESS If the node is successfully removed from the list.
 * @retval STATUS_FAILURE If an error occurs (e.g., empty list or node not found).
 */
status_e pop_node(ListHandle h, const char* name)
{
    employeeList_ptr ptr = (employeeList_ptr)h;

    Node_t* temp = ptr->mp_first;
    Node_t* iter = ptr->mp_first;
    
    if ((ptr) == NULL || ptr->mp_first == NULL)
    {
        printf("Linked List is empty");
        FUNC_SET_ERROR(POP_NODE_FUNC);
        return STATUS_FAILURE;
    }
    else if (strcmp(ptr->mp_first->eData.m_name, name) == 0)
    {
        temp = ptr->mp_first->pnext;
        temp->pprevious = NULL;

        free(ptr->mp_first);
        ptr->mp_first = NULL;

        ptr->mp_first = temp;
        --ptr->mp_list_size;
        FUNC_CLEAN_ERROR(POP_NODE_FUNC);
        return STATUS_SUCCESS;
    }
    else
    {
        while (strcmp(iter->eData.m_name, name) != 0 && iter != NULL)
        {
            temp = iter;
            iter = iter->pnext;
        }

        if (iter == NULL)
        {
            printf("Data is not found!!!");
        }
        else
        {
            temp->pnext = iter->pnext;
            temp->pprevious = iter->pprevious;
            free(iter);
            iter = NULL;
            --ptr->mp_list_size;
        }
    }
    FUNC_CLEAN_ERROR(POP_NODE_FUNC);
    return STATUS_SUCCESS;
}

/**
 * @brief Removes the first node from the linked list.
 *
 * This function removes the first node from the list. If the list is empty,
 * it returns an error. The function also updates the first node pointer
 * and adjusts the list's size. The removed node is freed from memory.
 *
 * @param h The handle to the linked list (ListHandle).
 *
 * @retval STATUS_SUCCESS If the first node is successfully removed.
 * @retval STATUS_FAILURE If the list is empty or an error occurs.
 */
status_e pop_head(ListHandle h)
{
    employeeList_ptr ptr = (employeeList_ptr)h;

    Node_t* p_new_node = ptr->mp_first;

    if (is_empty(ptr))
    {
        printf("push_head fonksiyonunda geçici node oluþturulamadý");
        FUNC_SET_ERROR(POP_BACK_FUNC);
        return STATUS_FAILURE;
    }

    p_new_node = ptr->mp_first->pnext;
    p_new_node->pprevious = NULL;

    free(ptr->mp_first);
    ptr->mp_first = NULL;

    ptr->mp_first = p_new_node;
    --ptr->mp_list_size;

    FUNC_CLEAN_ERROR(POP_BACK_FUNC);
    return STATUS_SUCCESS;
}

/**
 * @brief Removes the last node from the linked list.
 *
 * This function removes the last node from the list. If the list is empty
 * or if there is an error in retrieving the last node, the function logs
 * an error and returns a failure status. The function also updates the
 * pointers accordingly and frees the memory of the removed node.
 *
 * @param h The handle to the linked list (ListHandle).
 *
 * @retval STATUS_SUCCESS If the last node is successfully removed.
 * @retval STATUS_FAILURE If an error occurs (e.g., empty list or failure
 *         to retrieve the last node).
 */
status_e pop_back(ListHandle h)
{
    employeeList_ptr ptr = (employeeList_ptr)h;
    Node_t* p_new_node = get_last_node(h);

    if (p_new_node == NULL || h == NULL)
    {
        FUNC_SET_ERROR(PUSHF_NOT_NODE);
        return STATUS_FAILURE;
    }
    else if (p_new_node == NULL)
    {
        free(p_new_node);
        p_new_node = NULL;
        FUNC_CLEAN_ERROR(PUSHF_NOT_NODE);
        return STATUS_SUCCESS;
    }

    Node_t* temp = p_new_node->pprevious;

    temp->pnext = NULL;

    free(p_new_node);
    p_new_node = NULL;

    FUNC_CLEAN_ERROR(PUSHF_NOT_NODE);
    return STATUS_SUCCESS;
}

/**
 * @brief Sorts the linked list using the bubble sort algorithm.
 *
 * This function sorts the nodes in the linked list based on the 'ages' field
 * of the employee data in each node. The sorting is done in ascending order.
 * The function iteratively compares adjacent nodes and swaps their data if
 * they are in the wrong order. This process continues until no swaps are made
 * during an iteration, indicating that the list is sorted. The sorting is
 * done using a do-while loop to ensure at least one pass is performed.
 *
 * @param h The handle to the linked list (ListHandle).
 *
 * @retval STATUS_SUCCESS If the list is successfully sorted.
 * @retval STATUS_FAILURE If the list is empty or an error occurs.
 */
status_e bubble_sort(ListHandle h)
{
    Node_t* new_node_ptr;
    Node_t* last_node_ptr = NULL;
    uint8_t swapped;
    employeeList_ptr ptr = (employeeList_ptr)h;

    if (ptr == NULL || ptr->mp_first == NULL)
    {
        FUNC_SET_ERROR(BUBBLE_SORT_FUNC);
        return STATUS_SUCCESS;
    }

    /*for ile de yapýlabilirdi ama do while yapmak istedim*/
    do 
    {
        swapped = 0;
        new_node_ptr = ptr->mp_first;

        while (new_node_ptr->pnext != last_node_ptr) 
        {
            if (new_node_ptr->eData.ages > new_node_ptr->pnext->eData.ages)
            {
                Employee temp = new_node_ptr->eData;
                new_node_ptr->eData = new_node_ptr->pnext->eData;
                new_node_ptr->pnext->eData = temp;
                swapped = 1;
            }
            new_node_ptr = new_node_ptr->pnext;
        }
        last_node_ptr = new_node_ptr;
    } while (swapped);

    FUNC_CLEAN_ERROR(BUBBLE_SORT_FUNC);
    return STATUS_SUCCESS;
}

/**
 * @brief Returns the size of the linked list.
 *
 * This function returns the number of nodes present in the linked list. It
 * accesses the `mp_list_size` field from the list structure to retrieve the
 * current size of the list.
 *
 * @param h The handle to the linked list (ListHandle).
 *
 * @retval The size of the linked list.
 */
size_t get_size_list(ListHandle h)
{
    employeeList_ptr ptr = (employeeList_ptr)h;
    return ptr->mp_list_size;
}

/**
 * @brief Retrieves the current error state of the linked list.
 *
 * This function returns the error state of the linked list by calling
 * the `FUNC_STATE_ERROR` function, which likely retrieves the current
 * error code or status. This is useful for diagnosing issues within
 * the linked list operations.
 *
 * @retval uint32_t The current error state of the linked list.
 */
uint32_t get_linkedlist_error(ListHandle h)
{
    employeeList_ptr ptr = (employeeList_ptr)h;
    return FUNC_STATE_ERROR();
}

/**
 * @brief Prints the elements of the linked list.
 *
 * This function iterates through the entire linked list and prints the
 * name and age of each employee contained in the nodes. It formats
 * the output for each node and prints a separator line at the end.
 *
 * @param h The handle to the linked list (ListHandle).
 */
void print_list(ListHandle h) {

    employeeList_ptr ptr = (employeeList_ptr)h;

    for (Node_t* iter = ptr->mp_first; iter != NULL; iter = iter->pnext) {
        printf("NAME: %-16s  NO: %-16d\n", iter->eData.m_name, iter->eData.ages);
    }
    printf("------------------------------------------------------\n");
}
