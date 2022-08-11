#include<stdio.h>

#include<conio.h>

#include<malloc.h>

#include<string.h>

#include<math.h>

#include<ctype.h>

int main() {
  int i = 0, j = 0, x = 0, n, flag = 0;
  void * p, * add[15];
  char ch, srch, b[15], d[15], c;
  //clrscr();
  printf("expression terminated by $:");
  while ((c = getchar()) != '$') {
    b[i] = c;
    i++;
  }
  n = i - 1;
  printf("given expression:");
  i = 0;
  while (i <= n) {
    printf("%c", b[i]);
    i++;
  }
  printf("symbol table\n");
  printf("symbol\taddr\ttype\n");
  while (j <= n) {
    c = b[j];
    if (isalpha(toascii(c))) {
      if (j == n) {
        p = malloc(c);
        add[x] = p;
        d[x] = c;
        printf("%c\t%d\tidentifier\n", c, p);
      } else {
        ch = b[j + 1];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '=') {
          p = malloc(c);
          add[x] = p;
          d[x] = c;
          printf("%c\t%d\tidentifier\n", c, p);
          x++;
        }
      }
    }
    j++;
  }
  printf("the symbol is to be searched\n");
  srch = getch();
  for (i = 0; i <= x; i++) {
    if (srch == d[i]) {
      printf("symbol found\n");
      printf("%c%s%d\n", srch, "@address", add[i]);
      flag = 1;
    }
  }
  if (flag == 0)
    printf("symbol not found\n");
  //getch();
}

/*
output
expression terminated by $:a+b-c$
given expression:a+b-csymbol table
symbol	addr	type
a	1599273664	identifier
b	1599273776	identifier
c	1599273888	identifier
the symbol is to be searched
symbol not found
*/