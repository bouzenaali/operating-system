#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

char tampon[6];

int main(int argc, char *argv[])
{
	int fd;
	pid_t pid;

	 if ((fd = open("toto.txt", O_RDONLY)) < 0)
		 return EXIT_FAILURE;

	 pid = fork(); sleep(1);

	 switch (pid)
	 {
	 	case -1:
			return EXIT_FAILURE;
		case 0:
			read(fd, tampon, 5);
			printf("from case 0 ");
			break;
		default:
			wait(NULL);
			read(fd, tampon, 5);
			printf("from default ");
	 }

	 if (pid == 0){ printf("from the child : ");} else {printf("from the parent : ");}
	 sleep(1); printf("%s\n", tampon); close(fd);
	 return EXIT_SUCCESS;
}
