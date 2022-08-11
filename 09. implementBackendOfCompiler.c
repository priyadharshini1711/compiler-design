// #include <stdio.h >
// #include<conio.h>
// #include <string.h >

int main() {
  char icode[10][30], str[20], opr[10];
  int i = 0;
  // clrscr();
  printf("\n Enter the set of intermediate code (terminated by exit):\n");
  do {
    scanf("%s", icode[i]);
  } while (strcmp(icode[i++], "exit") != 0);
  printf("\n target code generation");
  printf("\n************************");
  i = 0;
  do {
    strcpy(str, icode[i]);
    switch (str[3]) {
    case '+':
      strcpy(opr, "ADD ");
      break;
    case '-':
      strcpy(opr, "SUB ");
      break;
    case '*':
      strcpy(opr, "MUL ");
      break;
    case '/':
      strcpy(opr, "DIV ");
      break;
    }
    printf("\n\tMov %c,R%d", str[2], i);
    printf("\n\t%s%c,R%d", opr, str[4], i);
    printf("\n\tMov R%d,%c", i, str[0]);
  } while (strcmp(icode[++i], "exit") != 0);
  // getch();
}

/*
output
Enter the set of intermediate code (terminated by exit):
x=a-b
y=a-c
z=a+b
c=a-b
c=a-b
exit
target code generation
************************
	Mov a,R0
	SUB b,R0
	Mov R0,x
	Mov a,R1
	SUB c,R1
	Mov R1,y
	Mov a,R2
	ADD b,R2
	Mov R2,z
	Mov a,R3
	SUB b,R3
	Mov R3,c
	Mov a,R4
	SUB b,R4
	Mov R4,c
*/