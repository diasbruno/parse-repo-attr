#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "substr/substr.h"
#include "parse-repo-attr.h"

#define assert_null(x) assert(x == NULL)

void
printer(struct repo_attr_t* repo)
{
  printf("%s\n", repo->host);
  printf("%s\n", repo->user);
  printf("%s\n", repo->name);
  printf("%s\n", repo->version);
}

int main(void)
{
  struct repo_attr_t ra;
  ra.host = NULL;
  ra.user = NULL;
  ra.name = NULL;
  ra.version = NULL;

  parse_repo_attr(&ra, "clibs@readline");
  assert_null(ra.host);
  assert_null(ra.user);
  assert_null(ra.name);
  assert_null(ra.version);
  parse_repo_attr_free(&ra);

  parse_repo_attr(&ra, "clibs:readline");
  assert_null(ra.host);
  assert_null(ra.user);
  assert_null(ra.name);
  assert_null(ra.version);
  parse_repo_attr_free(&ra);

  parse_repo_attr(&ra, "clibs/readline");
  assert_null(ra.host);
  assert(ra.user);
  assert(ra.name);
  assert_null(ra.version);
  parse_repo_attr_free(&ra);

  parse_repo_attr(&ra, "clibs/readline@0.0.2");
  assert_null(ra.host);
  assert(ra.user);
  assert(ra.name);
  assert(ra.version);
  parse_repo_attr_free(&ra);

  parse_repo_attr(&ra, "github:clibs/readline@0.0.2");
  printer(&ra);
  assert(ra.host);
  assert(ra.user);
  assert(ra.name);
  assert(ra.version);
  parse_repo_attr_free(&ra);

  parse_repo_attr(&ra, "local:clibs/readline@0.0.2");
  printer(&ra);
  assert(ra.host);
  assert(ra.user);
  assert(ra.name);
  assert(ra.version);
  parse_repo_attr_free(&ra);

  return 0;
}
