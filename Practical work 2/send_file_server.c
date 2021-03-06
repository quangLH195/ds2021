#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "send_file.h"

char file_name[100];
long int file_size;
FILE * output_file;

int *
send_name_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;

	strcpy(file_name, *argp);
	printf("Receive name! %s\n", file_name);
	result = 1;

	return &result;
}

int *
send_size_1_svc(long *argp, struct svc_req *rqstp)
{
	static int  result;

	file_size = *argp;
	printf("Receive file size! %ld\n", file_size);

	result = 1;

	return &result;
}

int *
send_buffer_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;

	printf("Receive name! %s\n", file_name);

	output_file = fopen(file_name, "wb");
	
	fwrite(*argp, file_size, 1, output_file);

	fclose(output_file);

	printf("Finish writing into file!\n");

	printf("\nWaiting for next file...\n");
	result = 1;

	return &result;
}