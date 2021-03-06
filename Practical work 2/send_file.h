#ifndef _SEND_FILE_H_RPCGEN
#define _SEND_FILE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define SEND_FILE_PROG 0x23451110
#define SEND_FILE_VER 1

#if defined(__STDC__) || defined(__cplusplus)
#define SEND_NAME 1
extern  int * send_name_1(char **, CLIENT *);
extern  int * send_name_1_svc(char **, struct svc_req *);
#define SEND_SIZE 2
extern  int * send_size_1(long *, CLIENT *);
extern  int * send_size_1_svc(long *, struct svc_req *);
#define SEND_BUFFER 3
extern  int * send_buffer_1(char **, CLIENT *);
extern  int * send_buffer_1_svc(char **, struct svc_req *);
extern int send_file_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define SEND_NAME 1
extern  int * send_name_1();
extern  int * send_name_1_svc();
#define SEND_SIZE 2
extern  int * send_size_1();
extern  int * send_size_1_svc();
#define SEND_BUFFER 3
extern  int * send_buffer_1();
extern  int * send_buffer_1_svc();
extern int send_file_prog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_SEND_FILE_H_RPCGEN */
