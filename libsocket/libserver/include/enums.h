/**
 * @file enums.h
 * @author Kreain
 * @brief This file contains the enums used for the libserver
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ENUMS_H_
#define ENUMS_H_

/**
 * @brief The protocol_t enum is only to set up the server settings
 * 
 *  Any TCP/UDP requests and responses must be handled by the main program
 */
typedef enum protocol_e {
    TCP,
    UDP
} protocol_t;


/**
 * @brief The activity_type_t enum is used to tell the main program 
 * what type of action the server has received.
 * The 'NOTHING' is not to be used or verified, it only used to reset the
 * type each loop
 * 
 */
typedef enum activity_type_e {
    CONNECTION,
    MESSAGE,
    DISCONNECTION,
    NOTHING
} activity_type_t;

#endif