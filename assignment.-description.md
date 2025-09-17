# Homework 02 – Guessing Minigame  
**Course:** CSC 3320 – System-Level Programming   

## Overview
Implement a C program that recreates a Tunnels of Doom–style vault guessing challenge.  
The program randomly generates a secret numeric code and gives the player a fixed number of attempts to guess it. After each guess, the program provides feedback similar to *Wordle*.

## Requirements
- **Random code generation**  
  - Use `rand()` to generate a secret code with `DIGITS` digits.  
  - Each digit ranges from 0 to `RANGE`.  

- **Gameplay**
  - Constant `TRIES` sets the maximum number of attempts.
  - For each guess:
    - Report if the code is *higher* or *lower* than the guess.
    - Report how many digits are correct and in the correct position.
    - Report how many digits are correct but in the wrong position.
  - If the player guesses all digits correctly, display a success message.
  - If the player fails within `TRIES`, display the correct code.

- **User input**
  - Reject invalid guesses (wrong length, non-digit characters, etc.).
  - Accept `q` or `Q` to quit immediately.

- **Program style**
  - Include a block comment at the top of your `.c` file with your name and a short description.
  - Use meaningful, descriptive variable names.
  - Comment your code clearly.

## Hints
- Store the code both as an integer and as an array of digits for easy comparisons.
- `itoa()` (integer → string) and `atoi()` (string → integer) can simplify conversions.

## Example Output
**Suppose that the secret code is 403. We might have the following input/output.**
```
8 tries remaining. What is the code? 678
Too high, 0 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
7 tries remaining. What is the code? 123
Too low, 1 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
6 tries remaining. What is the code? 145
Too low, 0 digits are correct and in the right place, 1 digits are correct
and in the wrong place.
5 tries remaining. What is the code? 904
Too high, 1 digits are correct and in the right place, 1 digits are correct
and in the wrong place.
4 tries remaining. What is the code? 042
Too low, 0 digits are correct and in the right place, 2 digits are correct
and in the wrong place.
3 tries remaining. What is the code? 403
You opened the vault!
```
**Suppose that the secret code is 722.**
```
8 tries remaining. What is the code? 678
Too low, 0 digits are correct and in the right place, 1 digits are correct
and in the wrong place.
7 tries remaining. What is the code? 901
Too high, 0 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
6 tries remaining. What is the code? 234
Too low, 0 digits are correct and in the right place, 1 digits are correct
and in the wrong place.
5 tries remaining. What is the code? 853
Too high, 0 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
4 tries remaining. What is the code? 444
Too low, 0 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
3 tries remaining. What is the code? 333
Too low, 0 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
2 tries remaining. What is the code? 688
Too low, 0 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
1 tries remaining. What is the code? 776
Too high, 1 digits are correct and in the right place, 0 digits are correct
and in the wrong place.
The vault shuts down permanently due to too many incorrect attempts. You
failed to open the vault!
The secret code was 722
```
