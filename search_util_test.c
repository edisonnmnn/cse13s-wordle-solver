// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // TODO(you): exercise all of your functions in here. Write some good test
  // cases! You may want to repeatedly set up the vocabulary and filter it down,
  // testing as you go. This is up to you!
  //
  // Make sure to include tests for, at least:


  // score_word
  // initializing test values for score_word which will be used for test cases
  int test_letter_scores[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
  };  //a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y, z 
	
  printf("\nSCORE_WORD TESTS\n");
  printf("test for word aaaaa: %d. This is the actual: 1\n", score_word("aaaaa", test_letter_scores));
  printf("test for word ababc: %d. This is the actual: 7\n", score_word("ababc", test_letter_scores));
  printf("test for word shear: %d. This is the actual: 8\n", score_word(words[2], test_letter_scores));
  printf("test for word tense: %d. This is the actual: 4\n", score_word(words[5], test_letter_scores));
  printf("test for word zebra: %d. This is the actual: 16\n", score_word("zebra", test_letter_scores));
  
  // score_letter
  printf("\nSCORE_LETTER TESTS\n");
  printf("test for a: %d. This is the actual: 7\n",  score_letter('a', vocabulary, num_words));
  printf("test for z: %d. This is the actual: 0\n",  score_letter('z', vocabulary, num_words));
  printf("test for s: %d. This is the actual: 4\n",  score_letter('s', vocabulary, num_words));
  // filter_vocabulary_green

  // filter_vocabulary_gray
  printf("\nFILTER_VOCABULARY_GRAY TESTS\n");
  printf("Test for letter a:\ntest for count: %zu. this is the actual: 7\n", filter_vocabulary_gray('a', vocabulary, num_words));
  printf("test for freeing of pointers:\n");
  printf("ACTUAL: ");
  for (size_t i = 0; i < num_words; i++) {
	 if (vocabulary[i] == NULL) {
		printf("NULL ");
	 } else {
		printf("%s ", vocabulary[i]);
	 }
  }
  printf("\nEXPECT: NULL NULL NULL NULL motif tense NULL NULL ether NULL\n\n");
  
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }

  // char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
  // "tense", "ultra", "vital", "ether", "nadir"}; 
  printf("Test for letter z:\ntest for count: %zu. this is the actual: 0\n", filter_vocabulary_gray('z', vocabulary, num_words));
  printf("test for freeing of pointers:\n");
  printf("ACTUAL: ");
  for (size_t i = 0; i < num_words; i++) {
	 if (vocabulary[i] == NULL) {
		printf("NULL ");
	 } else {
		printf("%s ", vocabulary[i]);
	 }
  }
  printf("\nEXPECT: stalk scrap shear batch motif tense ultra vital ether nadir\n\n");
  
  // filter_vocabulary_yellow
  printf("FILTER_VOCABULARY_YELLOW TESTS\n");
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }

  printf("Test for letter a:\ntest for count: %zu. this is the actual: 4\n", filter_vocabulary_yellow('a', 2, vocabulary, num_words));
  printf("test for freeing of pointers:\n");
  printf("ACTUAL: ");
  for (size_t i = 0; i < num_words; i++) {
	 if (vocabulary[i] == NULL) {
		printf("NULL ");
	 } else {
		printf("%s ", vocabulary[i]);
	 }
  }
  printf("\nEXPECT: NULL scrap shear batch NULL NULL ultra vital NULL nadir\n\n");

  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }

  printf("Test for letter z:\ntest for count: %zu. this is the actual: 10\n", filter_vocabulary_yellow('z', 2, vocabulary, num_words));
  printf("test for freeing of pointers:\n");
  printf("ACTUAL: ");
  for (size_t i = 0; i < num_words; i++) {
	 if (vocabulary[i] == NULL) {
		printf("NULL ");
	 } else {
		printf("%s ", vocabulary[i]);
	 }
  }
  printf("\nEXPECT: NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL\n\n");

  // filter_vocabulary_green 
  printf("FILTER_VOCABULARY_GREEN TESTS\n");
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }

  printf("Test for letter a:\ntest for count: %zu. this is the actual: 9\n", filter_vocabulary_green('a', 2, vocabulary, num_words));
  printf("test for freeing of pointers:\n");
  printf("ACTUAL: ");
  for (size_t i = 0; i < num_words; i++) {
	 if (vocabulary[i] == NULL) {
		printf("NULL ");
	 } else {
		printf("%s ", vocabulary[i]);
	 }
  }
  printf("\nEXPECT: stalk NULL NULL NULL NULL NULL NULL NULL NULL NULL\n\n");

  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }

  printf("Test for letter z:\ntest for count: %zu. this is the actual: 10\n", filter_vocabulary_green('z', 3, vocabulary, num_words));
  printf("test for freeing of pointers:\n");
  printf("ACTUAL: ");
  for (size_t i = 0; i < num_words; i++) {
	 if (vocabulary[i] == NULL) {
		printf("NULL ");
	 } else {
		printf("%s ", vocabulary[i]);
	 }
  }
  printf("\nEXPECT: NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL\n\n");
  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
}

