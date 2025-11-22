# Event Notes – Raw Observations While Learning

These are my personal notes from looking at the Windows and Linux logs I generated on purpose. I'm still learning, so I'm writing things the way I understood them. These are not “polished” findings — just what I saw and how I interpreted it as a beginner.

---

## Windows Failed Logon Attempts (Event ID 4625)

I created several failed logon attempts using the `runas` command with a fake username. Then I checked Event Viewer under:

Windows Logs → Security → Event ID 4625

Here’s what stood out to me:

### What I Saw:
- **Logon Type:** 2  
  (This means it was an interactive logon attempt at the machine.)
- **Account Name:** FakeUser  
  (The account I intentionally tried to log in as.)
- **Failure Reason:** Unknown user name or bad password  
- **Status/SubStatus:** 0xC000006D / 0xC000006A  
  (From what I looked up, the substatus usually means “bad password.”)
- **Process Name:** `C:\Windows\System32\runas.exe`  
  (This matches how I generated the event.)

### My Beginner Interpretation:
- The system logged exactly what I expected.
- Seeing the failed logons in Event Viewer helped me understand how brute-force behavior starts showing up.
- These events could be the beginning stage of someone trying to guess passwords.

---

## Linux Failed Sudo Attempts (Ubuntu /var/log/auth.log)

I also wanted to generate failed sudo logs inside Ubuntu (WSL). I mistyped my password on purpose a few times.

Here are lines I noticed in the auth log:

authentication failure; logname= uid=1000 euid=0 tty=/dev/pts/0 ruser=keith rhost= user=keith
keith : 3 incorrect password attempts ; COMMAND=/usr/bin/ls


### What I Saw:
- It shows the username (`keith`) attempting sudo.
- It shows how many incorrect password attempts I made.
- It shows the exact command I tried (`ls` with sudo).
- It tells me authentication failed.

### My Beginner Interpretation:
- This helped me understand what failed privilege escalation attempts look like.
- Seeing these logs makes it easier to imagine how attackers try to gain higher privileges.

---

## Ping Flood / Noisy Network Traffic (Windows)

I ran a simple ping loop:

ping 127.0.0.1 -t


What I noticed:
- It generated continuous ICMP traffic.
- I couldn't see network-related logs in Event Viewer and Task Manager as the network traffic was local.
- No external connection → no network boundary crossed → no log needed.
- Windows does not treat local-loop ICMP as a network connection event
- No Event ID 5156 created
- This helped me understand how noisy network behavior looks.

---

## Overall Thoughts

This lab helped me get comfortable reading logs and understanding what they mean. Even these small examples show how logs can tell a story about what’s happening on a machine. I’m starting to see how SOC analysts spot suspicious activity just from patterns in logs.


