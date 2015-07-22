#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substr/substr.h"
#include "parse-repo-attr.h"

void parse_repo_attr(struct repo_attr_t* repo, const char* args)
{
  // (contract)
  //       da    db       dc
  // github:clibs/readline@0.0.2
  // 
  //  da &&  db &&   _ - ok
  // !da &&  db &&  dc - ok
  // !da &&  db && !dc - ok
  //   _ && !db &&   _ - fail
  char* da = NULL;
  char* db = strchr(args, '/');
  char* dc = NULL;

  if (db == NULL) {
    fprintf(stderr, "malformatted.\n");
    return;
  }

  da = strchr(args, ':');
  dc = strchr(args, '@');

  if (da) {
    repo->host = substr(args, 0, (da - args));
    da++;
  } else {
    da = (char*)args;
  }

  repo->user = substr(da, 0, (db - da));
  db++;

  if (dc) {
    repo->name = substr(db, 0, (dc - db));
    dc++;
  } else {
    repo->name = substr(db, 0, strlen(db));
    return;
  }

  if (dc && *dc != '\0') {
    repo->version = strdup(dc);
  }
}

void parse_repo_attr_free(struct repo_attr_t* r)
{
  free(r->name);
  free(r->user);
  free(r->host);
  free(r->version);
}
