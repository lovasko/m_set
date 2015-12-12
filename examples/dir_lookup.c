#include <m_set.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int
main(int argc, char** argv)
{
	DIR* dir;
	char buffer[256];
	char* error;
	int ret;
	struct dirent* de;
	struct m_set set;

	if (argc != 2) {
		fprintf(stderr, "Expected one argument.\n");
		return EXIT_FAILURE;
	}

	m_set_init(&set);

	dir = opendir(argv[1]);
	if (dir == NULL) {
		perror("opendir");
		return EXIT_FAILURE;
	}

	while ((de = readdir(dir)) != NULL)
		m_set_add(&set, de->d_name, de->d_namlen);

	closedir(dir);

	while (1) {
		fgets(buffer, 256, stdin);

		ret = m_set_test(&set, buffer, strlen(buffer)-1);	
		switch (ret) {
			case M_SET_TRUE:
				printf("Yes.\n");
			break;

			case M_SET_FALSE:
				printf("No.\n");
			break;

			default:
				m_set_error_string(ret, &error);
				fprintf(stderr, "ERROR: %s\n", error);
			break;
		}
	}

	return EXIT_SUCCESS;
}

