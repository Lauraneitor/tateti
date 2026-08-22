#include "render.c"
#include "update.c"

int main() {
  do render();
  while (update());
  render();
}
