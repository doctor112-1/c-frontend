#include "./site/mainElement.c"
#include "./site/vars.h"
#include <emscripten.h>
#include <stdio.h>
#include <string.h>

EM_JS(void, createPage, (const char *mainElementResult), {
  let element = UTF8ToString(mainElementResult);
  let rxp = /{([^}]+)}/g;

  while (rxp.exec(element) != null) {
    rxp.lastIndex = 0;
    let match = rxp.exec(element);
    let type = match[0].split("_");
    type = type[type.length - 1].split("}")[0];
    element = element.substring(0, match.index) + Module.ccall(`get${match[1]}`, type, ['number'], [1]) + element.substring(match[0].indexOf("}") + match.index + 1);
    rxp.lastIndex = 0;
  }

  // take the output and parse it into html
  let parser = new DOMParser();
  let parsed = parser.parseFromString(element, "text/html");

  document.body.replaceWith(parsed.body);
});


int main() {
  // call mainElement which is code the user makes to make page
  // this could be condensed into just createPage(mainElement()); but in case we need to do any processing in c on the output, it should be kept here
  const char* mainElementPre = mainElement();
  createPage(mainElementPre);
  return 0;
}
