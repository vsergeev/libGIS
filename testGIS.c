/*
 * This program prints all of the records stored in an Atmel Generic, Intel HEX, or Motorola S-Record formatted file.
 * Author: Vanya A. Sergeev <vsergeev@gmail.com>
 */

#include <stdio.h>
#include <string.h>
#include "srecord.h"
#include "atmel_generic.h"
#include "ihex.h"

/* Windows doesn't have 'strcasecmp' but does have stricmp */
#ifdef _WIN32
	#define strcasecmp stricmp
#endif

int main (int argc, const char * argv[]) {
	FILE *fp;
	AtmelGenericRecord arec;
	IHexRecord irec;
	SRecord srec;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <file format> <file>\n", argv[0]);
		fprintf(stderr, "This program will print the records saved in a generic,\nIntel HEX, or Motorola S-Record formatted file.\n\n");
		fprintf(stderr, "<file format> can be generic, ihex, or srecord.\n");
		fprintf(stderr, "<file> is the path to the file containing the records.\n");
		return -1;
	}

	fp = fopen(argv[2], "r");
	if (fp == NULL) {
		perror("Error opening file!");
		return -1;
	}

	if (strcasecmp(argv[1], "generic") == 0) {
		while (Read_AtmelGenericRecord(&arec, fp) == ATMEL_GENERIC_OK) {
			Print_AtmelGenericRecord(&arec);
			printf("\n");
		}
	} else if (strcasecmp(argv[1], "ihex") == 0) {
		while (Read_IHexRecord(&irec, fp) == IHEX_OK) {
			Print_IHexRecord(&irec);
			printf("\n");
		}
	} else if (strcasecmp(argv[1], "srecord") == 0) {
		while (Read_SRecord(&srec, fp) == SRECORD_OK) {
			Print_SRecord(&srec);
			printf("\n");
		}
	} else {
		fprintf(stderr, "Invalid file format specified!\n");
		fclose(fp);
		return -1;
	}

	fclose(fp);
	return 0;
}

