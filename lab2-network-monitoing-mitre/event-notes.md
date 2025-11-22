
# Event Notes (My Raw Observations)

These are my personal notes from looking at the logs after generating different kinds of activity. I'm still learning how to read and interpret log data, so these notes reflect what I understood in plain language.

---

## Failed Login Attempts (Windows – Event ID 4625)

I generated several failed login attempts using the `runas` command with a fake username and password. Then I checked Event Viewer under:

Windows Logs → Security → Event ID 4625

Here’s what I noticed:

### Event 4625 Observations
- **Logon Type:** 2  
  (This means interactive login — I used the console.)
- **Account Name:** FakeUser  
  (The account I attempted to use.)
- **Status / SubStatus:** 0xC000006D / 0xC000006A  
  (From what I found online, these codes mean "Logon failed" and "Bad password.")
- **Failure Reason:** "Unknown user name or bad password."
- **Process Name:** `C:\Windows\System32\runas.exe`  
  (Matches the command I used.)
- **IP Address:** Not present  
  (Makes sense because this was a local login attempt.)

### My Beginner Interpretation
- The system logged each attempt exactly the way I expected.
- Seeing the different fields helped me understand what information Windows records during a failed logon.
- If this happened many times in a row on a real machine, it *could* be a sign of someone trying to guess passwords (brute force).

### Why I Think This Matters
Even though this was just a test, I can see how failed logon events are useful for detecting suspicious activity. It's one of the first things SOC analysts learn to look at.

---

## Example Raw Event Log Snippet (Copied from Event Viewer)

An account failed to log on.

Subject:
Security ID: SYSTEM
Account Name: DESKTOP-12345$
Account Domain: WORKGROUP
Logon ID: 0x3E7

Logon Type: 2

Account For Which Logon Failed:
Security ID: NULL SID
Account Name: FakeUser
Account Domain: DESKTOP-12345

Failure Information:
Failure Reason: Unknown user name or bad password.
Status: 0xC000006D
Sub Status: 0xC000006A

Process Information:
Caller Process Name: C:\Windows\System32\runas.exe



