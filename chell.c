#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <pwd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <bits/posix1_lim.h>

// TODO: alternate handling?
extern int gethostname(char *, size_t);

int main()
{
  char hostname[_POSIX_HOST_NAME_MAX + 1] = { 0 };
  char *input = NULL;
  struct passwd *passwd = NULL;
  char directory[PATH_MAX] = { 0 };

  if(getcwd(directory, PATH_MAX) != directory) {
    perror("Could not get current directory");
    return 2;
  }

  printf("--------------------------------------\n");
  printf("Chell. Don't trust this shell. at all.\n");
  printf("Your cwd is: %s\n", directory);
  printf("And yes, this uses system() for now.\n");
  printf("And yes, it is cheating.\n");
  printf("--------------------------------------\n");

  using_history();
  do {
    if(gethostname(hostname, sizeof(hostname)) < 0) {
      fprintf(stderr, "Could not get hostname\n");
      strncpy(hostname, "HOSTNAME", _POSIX_HOST_NAME_MAX);
    }
    if((passwd = getpwuid(getuid())) == NULL) {
      perror("Could not get password file entry");
      return 1;
    }
    if(getcwd(directory, PATH_MAX) != directory) {
      perror("Could not get current directory");
      return 2;
    }

    int prompt_len = snprintf(NULL, 0, "(chell) [%s@%s %s]$ ",
        passwd->pw_name, hostname, directory);
    char prompt[prompt_len + 1];
    snprintf(prompt, sizeof(prompt), "(chell) [%s@%s %s]$ ",
        passwd->pw_name, hostname, directory);

    input = readline(prompt);
    if(input == NULL) {
       return 0;
    }
    add_history(input);
    system(input);

    if(strcmp(input, "exit") == 0) {
       return 0;
    }
  } while (1);

  clear_history();
  return 0;
}

// vim: ts=2: et:
