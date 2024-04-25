#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// #include <strings.h>

void encode() {
  char text[100];
  int key;
  printf("Enter the text to be encrypted:");
  getchar();
  fgets(text, sizeof(text), stdin);
  printf("Enter the key to be shifted:\n");
  scanf("%d", &key);
  for (int i = 0; text[i] != '\0'; i++) {
    char ch = text[i];
    if (isalnum(ch)) {
      if (islower(ch)) {
        ch = (ch - 'a' + key) % 26 + 'a';
      }
      if (isupper(ch)) {
        ch = (ch - 'A' + key) % 26 + 'A';
      }
    }
    text[i] = ch;
  }
  printf("Encryped text:\n");
  printf("%s\n\n", text);
}

void decode() {
  char encrypted[100];
  int key;
  printf("Enter the text to be decrypted:");
  getchar();
  fgets(encrypted, sizeof(encrypted), stdin);
  printf("Enter the key:\n");
  scanf("%d", &key);
  for (int i = 0; encrypted[i] != '\0'; i++) {
    char ch = encrypted[i];
    if (isalnum(ch)) {
      if (islower(ch)) {
        ch = (ch - 'a' - key) % 26 + 'a';
      }
      if (isupper(ch)) {
        ch = (ch - 'A' - key) % 26 + 'A';
      }
    }
    encrypted[i] = ch;
  }
  printf("decrypted text:\n");
  printf("%s\n\n", encrypted);
}

int main() {
  int choice;
  while (1) {
    printf("enter '1' to encode\nenter '2' to decode\n3.Exit:\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      encode();
      break;
    case 2:
      decode();
      break;
    default:
      exit(0);
    }
  }
}
