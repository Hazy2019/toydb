#include <iostream>
struct Co {
  int id_;
  const char* data_;	
};

#define X1 "XXYYZZ"
#define X2 "AABBCC"

class Opx {
  public:
    Opx(int id, const char *data) : id_(id), data_(data) {
    }
    void Run(Opx *s) {
      std::cout << id_ << "," << data_ << " " << s->id() << "," << s->data() << std::endl;
      s->m_data(X2);
      std::cout << id_ << "," << data_ << " " << s->id() << "," << s->data() << std::endl;
    }
    void Run2(Co* x) {
      std::cout << id_ << "," << data_ << " " << x->id_ << "," << x->data_ << std::endl;
    }
    const int id() const {
      return id_;
    }
    const char * data() const { 
      return data_;
    }
    void m_data(const char *f) {
      data_ = f;
    }
  private:
    int id_;
    const char *data_;
};

int main() {
  Opx a1(0, "abc"), b1(1, X1);
  Co cc;
  cc.id_ = 3;
  cc.data_ = "co";

  a1.Run(&b1);
  a1.Run2(&cc);
  return 0;
}
