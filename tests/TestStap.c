#include <stdio.h>
#include <string.h>

struct Co {
  int id_;
  char* data_;
};
void setmbuf(const char *str);

void Run (struct Co* a) {
  printf("before: %2d %s\n", a->id_, a->data_);
  a->id_ = -1;         // change the value!
  setmbuf("kkkkkkk");  // change the value!
  printf("after : %2d %s\n", a->id_, a->data_);
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
  struct Co a;
  a.id_ = 0;
  a.data_ = buf; 
  setmbuf("aaaaaa");
  Run(&a);
  return 0;
}
