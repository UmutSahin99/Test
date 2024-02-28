#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void child1(char a[]) {
  int count = 0;
  for (int k = 0; k < strlen(a); k++) {
    if (isupper(a[k]) != 0) {
      count++;
    }
  }
  if (count == 0) {
    printf("Condition FAILED1\n");
    exit(1);
  }
  else if (count != 0) {
    printf("Condition Successed1\n");
    exit(0);
  }
}

void child2(char a[]) {
  int count = 0;
  for (int k = 0; k < 2; k++) {
    if (isdigit(a[k]) != 0) {
      count++;
    }
  }
  if (count != 0) {
    printf("Condition FAILED2\n");
    exit(1);
  } else if (count == 0) {
     printf("Condition Successed2\n");
          exit(0);
  }
}

void child3(char a[]) {
  int count = 0;
  for (int k = 0; k < strlen(a); k++) {
    if (a[k] == '_' | a[k] == '@' | a[k] == '?' | a[k] == '!') {
      count++;
    }
  }
  if (count == 0) {
    printf("Condition FAILED3\n");
    exit(1);
  } else if (count != 0) {
           printf("Condition Successed3\n");
    exit(0);
  }
}

void child4(char a[]) {
  int count = 0;
  for (int k = 0; k < strlen(a); k++) {
    if (isdigit(a[k]) != 0) {
      count++;
    }
  }
  if (count < 2) {
    printf("Condition FAILED4\n");
    exit(1);
  } else if (count >= 2) {
           printf("Condition Successed4\n");
    exit(0);
  }
}


int main(void) {
  int id, a, count = 0, check, code, validity = 0;
  char pw[20];
  printf("Insert a password: ");
  scanf("%s", pw);
  for (int i = 0; i < 4; i++) {
    id = fork();
     if (id == 0) {
      if (i == 0) child1(pw);
        // at least 1 uppercase
       else if (i == 1)  child2(pw);
        // first 2 chars cant be digit
       else if (i == 2) child3(pw);
       //special keys        
       else if (i == 3) child4(pw);
        // at least 2 digit 
    }
    
  }
for (int i = 0; i < 4; i++) {
      check = wait(&code);
      code = code >> 8;
      validity = validity + code;  
    }
  if (validity == 0) {
    printf("Password is VALID");
  } else if (validity > 0) {
    printf("Password is NOT VALID");
  }
  return 0;
}
