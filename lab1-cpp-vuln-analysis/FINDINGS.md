### Finding: Use of strcpy (unsafe string copy)

- **Tool / Source:** code review + flawfinder (intended use)
- **Description:** `strcpy` copies data into a fixed-size buffer without checking if the input is too long. This can overwrite memory and cause a buffer overflow.
- **Risk:** May crash the program or allow an attacker to corrupt memory.
- **Fix:** Use `strncpy` or add input length checks before copying.
