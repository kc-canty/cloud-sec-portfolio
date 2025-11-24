j### Finding: Use of strcpy (unsafe string copy)

This file is just my rough notes from running cppcheck and flawfinder on my small C++ program. I'm still learning how to read static analysis results, so some of these notes may not be perfect, but they reflect what I understood as I went through the tool output.

---

## Tool Output (cppcheck)

When I ran `cppcheck .`, it didn’t give a huge number of warnings, but here are the things I noticed:

- Some messages about potential buffer issues
- Mentions of uninitialized variables (I think this is common in simple C++ programs)
- It pointed out that fixed-size arrays can be risky if user input isn’t checked

I copied a couple of lines here just to reference:

./main.cpp:11:  [4] (buffer) strcpy:
  Does not check for buffer overflows when copying to destination [MS-banned]
  (CWE-120). Consider using snprintf, strcpy_s, or strlcpy (warning: strncpy
  easily misused).
  
./main.cpp:5:  [2] (buffer) char:
  Statically-sized arrays can be improperly restricted, leading to potential
  overflows or other issues (CWE-119!/CWE-120). Perform bounds checking, use
  functions that limit length, or ensure that the size is larger than the
  maximum possible length.
  
./main.cpp:10:  [2] (buffer) char:
  Statically-sized arrays can be improperly restricted, leading to potential
  overflows or other issues (CWE-119!/CWE-120). Perform bounds checking, use
  functions that limit length, or ensure that the size is larger than the
  maximum possible length.

  
These stood out to me because I know buffer overflow problems are a big deal in security.

---

## Tool Output (flawfinder)

When I ran `flawfinder main.cpp`, I got warnings about:

- `strcpy` being unsafe
- possible risks when using fixed-size char arrays


These stood out to me because I know buffer overflow problems are a big deal in security.

This immediately made sense because the program doesn’t check how long the user input is before copying it.

---

## My Beginner Interpretations

### 1. `strcpy()` is unsafe
I learned that `strcpy` doesn’t check how big the destination buffer is. So if someone types too much text, it can cause a buffer overflow. Even though my program is tiny, this pattern is still unsafe in real applications.

### 2. Fixed-size arrays can cause trouble
Anything like `char buffer[10];` seems simple, but it can be risky because the user can type more than 9 characters.

### 3. No input validation
I didn’t check what the user typed before using it. I know now that validating input early helps avoid a lot of problems.

### 4. No error handling
If input fails or behaves weirdly, the program doesn’t handle it. I can see how that becomes an issue in bigger programs.

---

## Summary of My Notes

This lab helped me get more comfortable with reading tool output and trying to translate it into real problems. I’m definitely still learning, but scanning a small C++ program made the ideas easier to understand.

I’ll add to this file as I get better at spotting issues.

Example line from the output:

