#include <stdio.h>
#include <string.h>
#include <sys/sdt.h>

struct Co {
  int id_;
  char* data_;
};
struct Co g;
void setmbuf(const char *str);

void Run (struct Co *a, struct Co LOCAL) {
  LOCAL.id_ = 101;
  LOCAL.data_ = "LOCAL101";


  printf("address of a: %p, value of a: %p\n", &a, a);
  printf("before: %2d %s\n", a->id_, a->data_);
  a->id_ = -1;         // change the value!
  setmbuf("kkkkkkk");  // change the value!
  printf("after : %2d %s\n", a->id_, a->data_);

  LOCAL.id_ = 299;
  LOCAL.data_ = "XXXXFFFFF";
DTRACE_PROBE(PROV0, BEFORERUNRETURN);
}

char buf[100];

void setmbuf(const char *str)
{
  int i = 0;
  int l = strlen(str) - 1;
  for (i = 0; i <= l; i++) {
    buf[i] = str[i];
  }
  buf[i] = '\0';
}

int main() {
  struct Co s;
  g.id_ = 0;
  g.data_ = buf; 
  
  s.id_ = 1;
  s.data_ = buf;
  setmbuf("aaaaaa");

  struct Co local1;
  local1.id_ = 21;
  local1.data_ = "LOCAL21";
  Run(&s, local1);
  return 0;
}
