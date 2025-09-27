#include "./site/mainElement.c"
#include <emscripten.h>

EM_JS(void, createPage, (const char *mainElementResult), {
  let element = UTF8ToString(mainElementResult);
  console.log(element);
  document.body.innerHTML = element;
});

int main() {
  createPage(mainElement());
  return 0;
}
