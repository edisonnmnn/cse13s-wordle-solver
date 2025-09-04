# Homework 6: Design Document

 * author: Edison Kuo
 * date: May 19, 2025

## introduction

This will be the design document for hw6. I will implement a Wordle solver in this homework and create my own test cases.

## `score_letter` 

This function will  loop over the vocabulary (which contains `num_words` entries) 
and return the number of words in which that particular letter occurs.
The implementation should be simple: return a count of how many words contain a given letter
based off of the count. 
The function doesn't seem to be in charge of freeing the words; it is done elsewhere.

## `score_word`

The function will calculate the score for a given word using a predetermined score for every letter.
The function will:
1. Loop over the word
2. Calculate the letter score for each letter
3. Return the letter score

## `get_guess` 

Returns the most optimal guess based on the heuristic. 
The implementation is already done but the memory will need to be freed elsewhere.

## `filter_vocabulary_gray`

This function will filter down the vocabulary based on the knowledge that the 
specified.letter *does not occur* in the secret word.
The function should loop over every word:
- Free the memory associated with each word that contains the given letter
- Set the slot to NULL
- Return the count for the amount of words that have been filtered

Note: The use of `score_letter` could be of use when implementing.

## `filter_vocabulary_yellow`

This function will filter down the vocabulary based on the knowledge that the
specified letter occurs in the word, *but not at this particular position*. 
The function will work similarly to `filter_vocabulary_gray` 
with the addition of filtering out the words with the letter at the particular position given.
This could be done by comparing position of the words that aren't filtered with the given position and letter.

## `filter_vocabulary_green`

This function will filter down the vocabulary based on the knowledge that the
specified letter *definitely* occurs as the specified position.
The function will remove all words that don't contain the letter and also don't contain the word at the specific position.
The implementation will closely follow the previous two filter functions.

## `free_vocabulary`

The implementation is already done.
Free each of the strings in the vocabulary, as well as the pointer vocabulary
tself (which points to an array of char *)

## `search_util_test.c` 

The test cases will be dynamic and will change based off of the current program I am working on. 
Two or more test cases for each function.
