/*
 author: Ethan Le
--------------------------------------------------------------------------
Seminar 4 - ioctl
--------------------------------------------------------------------------
specifications: create a sample linux driver
create a sample user space application that interact with your driver 
    https://linux.die.net/man/3/write
    https://linux.die.net/man/3/read
add one function_operation that was not included in the slides (e.g. ioctl)
hint for ioctl:
    use a structure that is shared between the driver and the user space application
        have 2 integers inside the structure 
            param_name (e.g.: READ_POINTER, WRITE_POINTER, RESET_READ_POINTER, RESET_WRITE_POINTER)
            param_value (e.g.: 0)
you will need to include fs.h and uaccess.h 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
 
#define MAX 4096 
#define DEVICE_FILE "/dev/test_mod02"
#define ECE_W _IOW('a',0, ece_ioctl_args_t*) //write command
#define ECE_R _IOR('a',1, ece_ioctl_args_t*) //read command
#define ECE_RESET _IO('a',2) //reset cmd

typedef struct {
    int value;
} ece_ioctl_args_t;
 
int main()
{
        int fd;
        int32_t n1, n2;    
        int cmd;
        fd = open(DEVICE_FILE, O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }

        /*printf("enter value to write: \n");

        scanf("%d",&n1);

        printf("writing %d\n", n1);
        int countWrite = ioctl(fd, ECE_W, (int32_t*) &n1); //write from input to fd

        printf("reading value from driver\n");
        int countRead = ioctl(fd, ECE_R, (int32_t*) &n2); //read 
        printf("value is %d\n", n2);

        printf("closing the driver\n");
        close(fd);*/

        do {
            printf("enter command: 1. clear, 2. write, 3. read, or 4. quit...\n");
            scanf("%d", &cmd);
            switch(cmd){
                case 1: //clear
                    printf("clear the kernel value\n");
                    ioctl(fd, ECE_RESET, (int32_t*) &n1);
                    break;
                case 2: //write
                    printf("enter value to write to kernel mod:\n");
                    scanf("%d", &n1);
                    ioctl(fd, ECE_W, (int32_t*) &n1);
                    printf("wrote %d to kern\n", n1);
                    break;
                case 3: //read
                    printf("reading value from driver\n");
                    ioctl(fd, ECE_R, (int32_t*) &n2);
                    printf("read value from kern is: %d\n", n2);
                    break;
                case 4: //quit
                    printf("closing driver\n");
                    close(fd);
                    break;
                default:
                    printf("invalid cmd!\n");
            }
        } while(cmd != 4);


}

