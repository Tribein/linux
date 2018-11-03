#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
    struct rlimit old, new;
    struct rlimit *newp;
    pid_t pid;

    if (!(argc == 5)) {
        fprintf(stderr, "Usage: %s <pid> [<new-soft-limit> <new-hard-limit>]\n", argv[0]);
            exit(EXIT_FAILURE);
    }

    pid = atoi(argv[1]);        /* PID of target process */

    newp = NULL;
    new.rlim_cur = atoi(argv[3]);
    new.rlim_max = atoi(argv[4]);
    newp = &new;
    if ( strcmp(argv[2],"AS") ==0 ){
            if (prlimit(pid, RLIMIT_AS, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else if( strcmp(argv[2],"CORE")==0 ){
            if (prlimit(pid, RLIMIT_CORE, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else if( strcmp(argv[2],"DATA")==0 ){
            if (prlimit(pid, RLIMIT_DATA, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else if( strcmp(argv[2],"FSIZE")==0 ){
            if (prlimit(pid, RLIMIT_FSIZE, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else if( strcmp(argv[2],"MEMLOCK")==0 ){
            if (prlimit(pid, RLIMIT_MEMLOCK, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else if( strcmp(argv[2],"NOFILE")==0 ){
            if (prlimit(pid, RLIMIT_NOFILE, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else if( strcmp(argv[2],"NPROC")==0 ){
            if (prlimit(pid, RLIMIT_NPROC, newp, &old) == -1){
                printf("Failed to set limits!");
                exit(EXIT_FAILURE);
            }
    }else{
            fprintf(stderr, "Limit should be one of AS(-v), CORE(-c), DATA(-d), FSIZE(-f), MEMLOCK(-l), NOFILE(-n), NPROC(-p) \n", argv[0]);
            exit(EXIT_FAILURE);
    }

    printf("OK!\nPrevious limits were: soft=%lld; hard=%lld\n",(long long) old.rlim_cur, (long long) old.rlim_max);

    exit(EXIT_SUCCESS);
}
