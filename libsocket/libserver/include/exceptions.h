/**
 * @file exceptions.h
 * @author Kreain
 * @brief This header contains the different types of exceptions
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LSERVER_EXCEPTIONS_H_
#define LSERVER_EXCEPTIONS_H_

typedef enum server_exception_e {
    NO_EXCEPTIONS,
    EXCEPTION_NULL_HOSTNAME
    
} server_exception_t;

extern server_exception_t server_exception;

#ifndef EXCEPTION_MSG
#define EXCEPTION_MSG

extern const char *EXCEPTION_MESSAGES[];

#endif

void *throw_exception(void *return_value, server_exception_t exception_type);
void show_server_exception(void);

#endif