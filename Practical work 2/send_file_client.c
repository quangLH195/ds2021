#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "send_file.h"


void
send_file_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	char * file_name;
	int  *result_2;
	long  file_size;
	int  *result_3;
	char * file_buffer;

	//file pointer
	FILE *fp;

	char s[100];

#ifndef	DEBUG
	clnt = clnt_create (host, SEND_FILE_PROG, SEND_FILE_VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	//enter only existing file
	do{
		printf("Enter file name: ");
		scanf("%s", s);
		file_name = s;
		fp = fopen(file_name, "rb");
	}while(fp == NULL);

	//send file name
	result_1 = send_name_1(&file_name, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("The name is sent: %d\n", *result_1);
	}

	//get file size
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	//malloc
	file_buffer = (char*)malloc(file_size+1);

	//send file size
	result_2 = send_size_1(&file_size, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("The size is sent: %d\n", *result_2);
	}

	//read file into buffer
	fread(file_buffer, file_size, 1, fp);

	//send buffer
	result_3 = send_buffer_1(&file_buffer, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("The buffer is sent: %d\n", *result_3);
	}

	free(file_buffer);
	
	fclose(fp);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	send_file_prog_1 (host);
	exit (0);
}
