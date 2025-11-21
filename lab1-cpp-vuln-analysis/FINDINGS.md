### Finding: Use of strcpy (unsafe string copy)

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

Example line from the output:

