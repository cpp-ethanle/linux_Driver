#ifndef TEST_IOCTL_H
#define TEST_IOCTL_H
#include <linux/ioctl.h>

typedef struct {
  int value;
  //int filter;
} ece_ioctl_args_t;

/*#define ECE_GET_RP _IOR('a', 0, ece_ioctl_args_t*)
#define ECE_GET_WP _IOR('a', 1, ece_ioctl_args_t*)
#define ECE_CLR_RP _IO('a', 2)
#define ECE_CLR_WP _IO('a', 3)
#define ECE_SET_RP _IOW('a', 4, ece_ioctl_args_t*)
#define ECE_SET_WP _IOW('a', 5, ece_ioctl_args_t*)*/

#define ECE_W _IOW('a',0, ece_ioctl_args_t*)
#define ECE_R _IOR('a',1, ece_ioctl_args_t*)
#define ECE_RESET _IO('a',2)

#endif