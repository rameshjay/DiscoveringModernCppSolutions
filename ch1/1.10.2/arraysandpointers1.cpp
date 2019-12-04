
int main() {
  char *pc;
  char c = 'a';
  pc = &c;

  int ia[10];
  for (int i = 0; i < 10; ++i) {
    ia[i] = i;
  }

  int(*pia)[10];
  pia = &ia;

  char *ps[3];
  char saying[10] = {'e', 'n', 'd', '\0'};
  ps[0] = saying;

  char **ppc;
  ppc = &pc;
  **ppc = c;

  const int *pic;
  const int cint = 0;
  pic = &cint;

  int *const cpi = nullptr;
}
