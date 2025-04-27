#pragma once

#ifndef _MY_UTLITY_H
#define _MY_UTLITY_H
#include <stdint.h>
#include <math.h>
#include <time.h>


#define randomize()                      (srand((unsigned int)time(0)))
#define asize(x)                         (sizeof(x) / sizeof(x[0]))
#define get_random_element(a)            (a[rand() % asize(a)])

#define MAX_NAME_LEN    20

typedef struct {
    char m_name[MAX_NAME_LEN];
    uint8_t ages;
}Employee;

Employee* set_employee_random(Employee* p);

#endif
