int num_int;
char string_string[] = "Hello, World!";

const char* mainElement() {
  num_int = 0;
  return "<h1 style=\"text-align: center\">this site was built in c</h1>"
  "<h1 style=\"text-align: center\">it has jsx support</h1>"
  "<h1 style=\"text-align: center\">for example this number was rendered from a variable: {num_int}</h1>"
  "<h1 style=\"text-align: center\">and this string was rendered from a variable: {string_string}</h1>";
}
