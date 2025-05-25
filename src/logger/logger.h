/**
 *   arboreta-nexus
 *   Copyright (C) 2025  Mirko Lindroth
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2.0
 *   as published by the Free Software Foundation.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License version 2.0 for more details.
 */
#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

extern char *log_file;
extern char *app_name;

enum log_verbosity { NONE=0,LOW=100,AVG=200,HIGH=300,FULL=400 };
extern enum log_verbosity log_verbosity_g;

char *get_current_datetime();

// Console and file logging functions
void _info(const char *file_name, const char *func_name, int line_number, enum log_verbosity verbosity, const char *fmt_str,...);
void _warning(const char *file_name, const char *func_name, int line_number, const char *fmt_str,...);
void _error(const char *file_name, const char *func_name, int line_number, const char *fmt_str,...);
void _fatal(const char *file_name, const char *func_name, int line_number, const char *fmt_str,...);

// Reporting macros for different message types
#define info(verb,fmt_str,...) _info(__FILE__,__func__,__LINE__,verb,fmt_str,##__VA_ARGS__)
#define warning(fmt_str,...) _warning(__FILE__,__func__,__LINE__,fmt_str,##__VA_ARGS__)
#define error(fmt_str,...) _error(__FILE__,__func__,__LINE__,fmt_str,##__VA_ARGS__)
#define fatal(fmt_str,...) _fatal(__FILE__,__func__,__LINE__,fmt_str,##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
