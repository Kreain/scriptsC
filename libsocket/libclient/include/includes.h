/**
 * @file includes.h
 * @author Kreain
 * @brief This file contains all the includes needed for the libclient
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDES_H_
#define INCLUDES_H_

/**
 * @brief Those includes are used for any basic needs (malloc, free, etc)
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** 
 * @brief This include is important, it allows the use of SO_REUSEPORT
 * Not supported on APPLE products
 */
#ifdef __unix__
#include <asm-generic/socket.h>
#endif

/** 
 * @brief includes needed for any socket related functions and variables
 * 
 * <arpa/inet.h> - Definitions for internet operations (ie: htons)
 * <netdb.h> - Definitions for network database operations (ie: getprotobyname)
 * <sys/select.h> - Select types (select, FD_ZERO, FD_SET, etc)
 * <sys/types.h> - Data types (socket)
 * <sys/socket.h> - Main sockets header (all the information about a socket)
 */
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>

#endif