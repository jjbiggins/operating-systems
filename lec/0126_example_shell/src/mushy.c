/* mush.c
 * a Minimally Usable SHell
 * by Douglas Jones
 *
 * Warning:  This code is not commented -- deliberately in order to force
 * you to read the code.
 *
 * Warning:  This code is not unsafe!  Array bounds are not checked because
 * adding checking enlarges the code, making it harder to read.
 */

#include <stdio.h>	/* needed for getchar, putchar, NULL */
#include <stdlib.h>	/* needed for exit() */
#include <unistd.h>	/* needed for fork() */
#include <sys/wait.h>	/* needed for wait() */
 
char command[100];
char *argv[100];

void getcommand() {
	char ch;
	int i = 0;
	putchar( '>' );
	do {
		ch = getchar();
		command[i] = ch;
		i++;
	} while (ch != '\n');
	command[i - 1] = '\0';
}

void splitargv() {
	int i = 0;
	int j = 0;
	for (;;) {
		while (command[j] == ' ') j++;
		if (command[j] == '\0') break;
		argv[i] = &command[j];
		i++;
		while ((command[j] != ' ')
		&&     (command[j] != '\0')) {
			j++;
		}
		if (command[j] == '\0') break;
		command[j] = '\0';
		j++;
	}
	argv[i] = NULL;
}

void launch() {
	if (fork() == 0) { /*child*/
		execve( argv[0], argv, NULL );
		printf( "no such command\n" );
		exit( EXIT_FAILURE );
	} else { /*parent*/
		wait( NULL );
	}
}

int main(){
	for (;;) {
		getcommand();
		splitargv();
		launch();
	}
}
