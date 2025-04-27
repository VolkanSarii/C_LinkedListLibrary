# C_LinkedListLibrary


# Employee Linked List in C

## 📋 Project Description

This project is a **doubly linked list** implementation developed in the C programming language.  
It is specifically designed to dynamically manage **employee** data, supporting operations like adding, removing, sorting, and error handling.

---

## 🚀 Features

- Dynamic creation and insertion of nodes
- Add nodes to the front or back of the list (`push_front`, `push_back`)
- Remove nodes by employee name (`pop_node`)
- Remove the head or the last node (`pop_head`, `pop_back`)
- Sort the list based on employee ages using bubble sort (`bubble_sort`)
- Retrieve the size of the list (`get_size_list`)
- Error handling and error tracking
- Print the contents of the list (`print_list`)

---

## 🔧 Data Structures

- `Node_t` structure: Each node contains employee data (`Employee` structure).
- `Employee` structure: Stores name (`name`) and age (`age`) information.
- `ListHandle`: General handle type representing the linked list.

---

**Note:**  
Make sure that the required header files (`Linked_List.h` and `my_utility.h`) are available in the same directory.

---

## 📄 Functions

| Function | Description |
|-----------|-------------|
| `create_list()` | Creates a new linked list |
| `push_back()` | Adds a node to the end of the list |
| `push_front()` | Adds a node to the front of the list |
| `pop_node()` | Removes a node by employee name |
| `pop_head()` | Removes the first node of the list |
| `pop_back()` | Removes the last node of the list |
| `bubble_sort()` | Sorts the list by employee ages |
| `print_list()` | Prints all the nodes in the list |
| `get_size_list()` | Returns the number of nodes in the list |
| `get_linkedlist_error()` | Returns the current error state of the list |

---

## 📚 Requirements

- A C compiler compatible with the C99 standard
- Standard C libraries: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `math.h`, `ctype.h`
- `Linked_List.h` and `my_utility.h` header files

---

## 📌 Notes

- The project is designed with careful memory management.  
  Every dynamically created node must be properly freed (`free`).
- Error management is handled through macros (`FUNC_SET_ERROR`, `FUNC_GET_ERROR`, etc.).

---

