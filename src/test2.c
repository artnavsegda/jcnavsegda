#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <json-c/json.h>
#include <string.h>

FILE * my_popen_read (char * command, char *envp[], int * pid)
{

    char *argp[] = {"/bin/sh", "-c", command, NULL};
    int fd[2];
    int read_fd, write_fd;
    pipe(fd);
    read_fd = fd[0];
    write_fd = fd[1];
    *pid = fork();
    if (*pid == 0) {
        close(read_fd);
        dup2(write_fd,1);
        close(write_fd);
        execve("/bin/sh",argp,envp);
        return NULL;
    } else {
        close(write_fd);
        return fdopen(read_fd, "r");
    }
}

char ** envconv(json_object *obj)
{
  int i = 0;
  char ** envp = NULL;
  char tmpstr[1000];
  json_object_object_foreach(obj, key, val)
  {
    envp = realloc(envp, sizeof(envp)*(i+1));
    snprintf(tmpstr,1000,"__%s=%s",key,json_object_to_json_string(val));//check for leaks plz
    envp[i]=strdup(tmpstr);
    i++;
  }
  envp = realloc(envp, sizeof(envp)*(i+1));
  envp[i]=NULL;
  return envp;
}

void emptyenv(char *envp[])
{
  int i = 0;
  while (envp[i] != NULL)
  {
    free(envp[i]);
    i++;
  }
  free(envp);
}

int main()
{
  json_object *obj = json_object_from_file("test3.json");

  puts(json_object_to_json_string(obj));

  char ** envp = envconv(obj);
  int forkpid = 0;
  FILE *fp = my_popen_read("./test.sh", envp, &forkpid);

  emptyenv(envp);

  return 0;
}
