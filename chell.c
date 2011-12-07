#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <pwd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
  char hostname[_POSIX_HOST_NAME_MAX + 1] = { 0 };
  char *input = NULL;
  struct passwd *passwd = NULL;
  char directory[PATH_MAX] = { 0 };

  gethostname(hostname, sizeof(hostname));
  passwd = getpwuid(getuid());
  getcwd(directory, 255);

  printf("--------------------------------------\n");
  printf("Chell. Don't trust this shell. at all.\n");
  printf("Your cwd is: %s\n", directory);
  printf("And yes, this uses system() for now.\n");
  printf("And yes, it is cheating.\n");
  printf("--------------------------------------\n");

  do {
    gethostname(hostname, sizeof(hostname));
    passwd = getpwuid(getuid());
    getcwd(directory, 255);

    int prompt_len = snprintf(NULL, 0, "(chell) [%s@%s %s]$ ", passwd->pw_name, hostname, directory);
    char prompt[prompt_len + 1];
    snprintf(prompt, sizeof(prompt), "(chell) [%s@%s %s]$ ", passwd->pw_name, hostname, directory);
 
    input = readline(prompt);
    add_history(input);
    system(input);    

    if (strcmp(input, "exit") == 0) {
      return 1;
    }

  } while (1);
}
