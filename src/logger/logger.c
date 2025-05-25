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
#include "logger.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *log_file = "log.log";
char *app_name = "logger";
enum log_verbosity log_verbosity_g = AVG;

void _info(const char *file_name, const char *func_name, int line_number, enum log_verbosity verbosity, const char *fmt_str,...)
{
	if(verbosity <= log_verbosity_g) {
		va_list args;

		// Calculate the needed size
		va_start(args,fmt_str);
		size_t buffer_size = vsnprintf(NULL,0,fmt_str,args);
		va_end(args);

		// Store the processed format string
		va_start(args,fmt_str);
		char *msg = malloc(buffer_size*sizeof(char));
		vsprintf(msg,fmt_str,args);
		va_end(args);

		// Print the message to stdout
		fprintf(stdout,"[%s] %s\033[32m INFO \033[0m%s(%d): %s",
			app_name, get_current_datetime(), func_name, line_number, msg);

		// Log the message
		FILE *log_file_ptr = fopen(log_file,"a");
		fprintf(log_file_ptr,"[%s] %s INFO %s(%d): %s",
			app_name, get_current_datetime(), func_name, line_number, msg);
		fclose(log_file_ptr);

		free(msg);
	}
}

void _warning(const char *file_name, const char *func_name, int line_number, const char *fmt_str,...)
{
	va_list args;

	// Calculate the needed size
	va_start(args,fmt_str);
	size_t buffer_size = vsnprintf(NULL,0,fmt_str,args);
	va_end(args);

	// Store the processed format string
	va_start(args,fmt_str);
	char *msg = malloc(buffer_size*sizeof(char));
	vsprintf(msg,fmt_str,args);
	va_end(args);

	// Print the message
	fprintf(stderr,"[%s] %s\033[33m WARNING \033[0m%s(%d): %s",
		app_name, get_current_datetime(), func_name, line_number, msg);
	// Log the message
	FILE *log_file_ptr=fopen(log_file,"a");
	fprintf(log_file_ptr,"[%s] %s WARNING %s(%d): %s",
		app_name, get_current_datetime(), func_name, line_number, msg);
	fclose(log_file_ptr);

	free(msg);
}

void _error(const char *file_name, const char *func_name, int line_number, const char *fmt_str,...)
{
	va_list args;

	// Calculate the needed size
	va_start(args,fmt_str);
	size_t buffer_size = vsnprintf(NULL,0,fmt_str,args);
	va_end(args);

	// Store the processed format string
	va_start(args,fmt_str);
	char *msg = malloc(buffer_size*sizeof(char));
	vsprintf(msg,fmt_str,args);
	va_end(args);

	// Print the message
	fprintf(stderr,"[%s] %s\033[31m ERROR \033[0m%s(%d): %s",
		app_name, get_current_datetime(), func_name, line_number, msg);
	// Log the message
	FILE *log_file_ptr=fopen(log_file,"a");
	fprintf(log_file_ptr,"[%s] %s ERROR %s(%d): %s",
		app_name, get_current_datetime(), func_name, line_number, msg);
	fclose(log_file_ptr);

	free(msg);
}

void _fatal(const char *file_name, const char *func_name, int line_number, const char *fmt_str,...)
{
	va_list args;

	// Calculate the needed size
	va_start(args,fmt_str);
	size_t buffer_size = vsnprintf(NULL,0,fmt_str,args);
	va_end(args);

	// Store the processed format string
	va_start(args,fmt_str);
	char *msg = malloc(buffer_size*sizeof(char));
	vsprintf(msg,fmt_str,args);
	va_end(args);

	// Print the message
	fprintf(stderr,"[%s] %s\033[91m FATAL \033[0m%s(%d): %s",
		app_name, get_current_datetime(), func_name, line_number, msg);
	// Log the message
	FILE *log_file_ptr=fopen(log_file,"a");
	fprintf(log_file_ptr,"[%s] %s FATAL %s(%d): %s",
		app_name, get_current_datetime(), func_name, line_number, msg);
	fclose(log_file_ptr);

	free(msg);
}

char *get_current_datetime()
{
	// Get epoch time
	time_t epoch = time(0);
	// Get current time
	struct tm *current_time = localtime(&epoch);
	static char time_str[25];
	strftime(time_str, 25, "%Y-%m-%d %Z %H:%M:%S", current_time);
	return time_str;
}
