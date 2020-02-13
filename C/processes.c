#include <stdio.h>
#include <unistd.h> /* execl(), fork(), getuid(), geteuid(), getgid(), getegid(), getpid(), getpgid(), getppid()*/
#include <stdlib.h>// exit()
#include <sys/types.h> /* pid_t, uid_u, gid_t*/
#include <sys/wait.h> // wait()
void ids();
void twoProcesses();
void execUse();


int main(int argc, char **argv){

    //ids();
    //twoProcesses();
    execUse();
    return 0;
}

void ids(){
    printf("I'm process %ld\n", (long)getpid());
    printf("My father/parent is %ld\n", (long)getppid());
    printf("My real user ID is %5ld\n", (long)getuid());
    printf("My effective user ID is %5ld\n", (long)geteuid());
    printf("My real group ID is %5ld\n", (long)getgid());
    printf("My effective group ID is %5ld\n", (long)getegid());
}

void twoProcesses(){
    pid_t childpid = 0;

    childpid = fork();
    if(childpid < 0){
        perror("Failed to work");
    }
    if(!childpid)
        printf("I'm child %ld\n",(long)getpid());
    else
        printf("I'm parent %ld\n", (long)getpid());
}

void execUse(){

    pid_t pid;

    pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork failed\n");
        exit(-1);
    } else if (!pid)
        execl("/bin/ls", "ls", NULL);
    else {
        wait(NULL);
        printf("Child completed -- parent now exiting.\n");
    }
}
