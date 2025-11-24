# Screenshot Reference Guide

These screenshots support the activity I generated during Lab 3. I added them so anyone reviewing the project (including myself later on) can easily follow what happened and how the logs connect to the MITRE techniques I mapped.

Each screenshot here matches a specific step in the lab.

---

## 01_windows_failed-logon_4625.png
**What this shows:**  
A failed logon event (Event ID 4625) from Windows Event Viewer.

**Why it matters:**  
This is the log entry created when I tried to log in with a fake username using the `runas` command. I looked at fields like Logon Type, Failure Reason, and Caller Process to understand how Windows records authentication failures.

---

## 02_windows_process-created_4688.png
**What this shows:**  
A process creation event (Event ID 4688), usually tied to commands like `whoami` or `systeminfo`.

**Why it matters:**  
Attackers often run these commands for reconnaissance. This helped me understand how normal command-line activity shows up in Windows logs.

---

## 03_windows_ping-loop.png
**What this shows:**  
The terminal running a continuous ping (`ping 127.0.0.1 -t`).

**Why it matters:**  
This created noisy ICMP traffic that shows up in logs and simulates basic network flood-like behavior. It helped me see how repetitive network activity looks from a defender’s perspective.

---

## 04_linux_failed-sudo-attempt.png
**What this shows:**  
A failed sudo attempt inside Ubuntu (WSL) where I deliberately typed the wrong password.

**Why it matters:**  
Failed privilege escalation attempts can be an early sign of unauthorized access attempts. I used these logs to understand how Linux records authentication issues.

---

## 05_linux_authlog_sudo.png
**What this shows:**  
Filtered output from auth.log using:  
`sudo cat /var/log/auth.log | grep "sudo"`

**Why it matters:**  
This highlights the actual log lines Linux writes when sudo authentication fails. It helped me interpret fields like the user, TTY, command attempted, and number of incorrect passwords.

---

## How to Interpret These Screenshots
I included these to show:
- what the activity looks like visually  
- how logs match the actions I performed  
- how a security analyst might start building a timeline or story from raw events  

They also make the lab feel more real and help me practice explaining what I’m seeing in both Windows and Linux logs.

