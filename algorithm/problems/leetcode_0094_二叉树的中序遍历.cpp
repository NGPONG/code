#include <iostream>
#include <stack>

using namespace std;

struct tree_node {
  char elem;
  struct tree_node *left;
  struct tree_node *right;
};

void midorder_traverse(tree_node *root) {
  stack<tree_node *> s;
  tree_node *cur = root;
  while (cur != nullptr || !s.empty()) {
    while (cur != nullptr) {
      s.push(cur);
      cur = cur->left;
    }

    if (!s.empty()) {
      cur = s.top(); s.pop();
      cout << cur->elem << endl;
      cur = cur->right;
    }
  }
}

int main(void) {
  
  return EXIT_SUCCESS;
}
