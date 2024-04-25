#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to encrypt plaintext using monoalphabetic cipher
void encrypt(char plaintext[], char key[]) {
  int i;
  for (i = 0; i < strlen(plaintext); i++) {
    // Encrypt only alphabetic characters
    if (isalpha(plaintext[i])) {
      if (islower(plaintext[i])) {
        plaintext[i] = key[plaintext[i] - 'a'];
      } else {
        plaintext[i] = toupper(key[plaintext[i] - 'A']);
      }
    }
  }
}

// Function to decrypt ciphertext using monoalphabetic cipher
void decrypt(char ciphertext[], char key[]) {
  int i;
  for (i = 0; i < strlen(ciphertext); i++) {
    // Decrypt only alphabetic characters
    if (isalpha(ciphertext[i])) {
      if (islower(ciphertext[i])) {
        int index = strchr(key, ciphertext[i]) - key;
        ciphertext[i] = 'a' + index;
      } else {
        int index = strchr(key, tolower(ciphertext[i])) - key;
        ciphertext[i] = 'A' + index;
      }
    }
  }
}

int main() {
  char plaintext[1000];
  char key[26];

  printf("Enter plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);
  plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

  printf("Enter key: ");
  fgets(key, sizeof(key), stdin);
  key[strcspn(key, "\n")] = '\0'; // Remove newline character

  // Convert key to lowercase
  for (int i = 0; key[i]; i++) {
    key[i] = tolower(key[i]);
  }

  printf("\nOriginal: %s\n", plaintext);

  encrypt(plaintext, key);
  printf("Encrypted: %s\n", plaintext);

  decrypt(plaintext, key);
  printf("Decrypted: %s\n", plaintext);

  return 0;
}
/*
A long time ago, in a galaxy far, far away... It is a dark time for the
Rebellion. Although the Death Star has been destroyed, Imperial troops have
driven the Rebel forces from their hidden base and pursued them across the
galaxy. Evading the dreaded Imperial Starfleet, a group of freedom fighters led
by Luke Skywalker has established a new secret base on the remote ice world of
Hoth. The evil lord Darth Vader, obsessed with finding young Skywalker, has
dispatched thousands of remote probes into the far reaches of space…
*/
