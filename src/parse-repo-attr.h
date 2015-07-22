#ifndef PARSE_REPO_ATTR_H

struct repo_attr_t
{
  char* host;
  char* user;
  char* name;
  char* version;
};

void parse_repo_attr(struct repo_attr_t* repo, const char* args);
void parse_repo_attr_free(struct repo_attr_t* r);

#define PARSE_REPO_ATTR_H 1
#endif
