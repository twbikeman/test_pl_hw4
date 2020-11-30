#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;

template <class item>
class  queue {
  // item items[max_items];
  item *items;
  int max_items;
  int next_free, next_full, num_items;
public:
  queue(int _max_items = 100) : next_free(0), next_full(0), num_items(0), max_items(_max_items) {items = new item[_max_items];}
  bool enqueue (const item &it) {
    if (num_items == max_items)
      return false;
    ++num_items;
    items[next_free] = it;
    next_free = (next_free + 1) % max_items;
    return true;
  }
  bool dequeue(item *it) {
    if (num_items == 0)
      return 0;
    --num_items;
    *it = items[next_full];
    next_full = (next_full + 1) % max_items;
    return true;
  }
};

int main(int argc, char *argv[]) {
  queue<int> q(10);
  int a = 5;
  
  assert(q.enqueue(a));
  assert(q.enqueue(a));
  assert(q.enqueue(a));
  
  
  int b = 10;
  q.dequeue(&b);
  cout << b << endl;
  return 0;
}
