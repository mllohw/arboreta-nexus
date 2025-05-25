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
#include "logger/logger.h"
#include <stdlib.h>

int main()
{
	log_file = "arbex.log";
	app_name = "arboreta-nexus";
	log_verbosity_g = HIGH;

	info(HIGH,
		"\n\n\tarboretea-nexus, Copyright (C) 2025 Mirko Lindroth\n\n"
		"\tLicense GPLv2: GNU GPL version 2\n\n"
		"\tThis is free software, and you are welcome to redistribute it\n"
		"\tunder certain conditions; Check the license for details.\n"
		"\tarboreta-nexus comes with ABSOLUTELY NO WARRANTY\n\n"
	);

	return EXIT_SUCCESS;
}
