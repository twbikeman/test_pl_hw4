#include <list>
using std::list;
// ...


class foo {
  // ...
};

class bar : public foo {
  // ...
};

void print_all(list<foo *> &l) {
  // ...
}

int main(int argc, char *argv[]){
list<foo *> LF;
list<bar *> LB;
 print_all(LF);
 print_all(LB);
 return 0;
}
