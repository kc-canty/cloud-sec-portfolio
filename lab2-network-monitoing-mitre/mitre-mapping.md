
# MITRE ATT&CK Mapping

These are the MITRE techniques I mapped to the activity I generated on purpose. I’m still learning how to do this, so I wrote it in a simple way that made sense to me.

---

## 1. Failed Windows Logons → T1110 (Brute Force)

**Event:** Windows Event ID 4625  
**What I did:** Entered a fake username using `runas`  
**Why it maps:**  
Repeated failed logon attempts connect to brute-force style behavior. Even though this was a small test, this is exactly how password-guessing attacks start.

---

## 2. Command Execution → T1059 (Command-Line Execution)

**Event:** Process execution logs (Event ID 4688)  
**Commands used:** `whoami`, `systeminfo`, `ipconfig`  
**Why it maps:**  
Attackers commonly run these commands early to learn about the system. MITRE classifies this under command-line execution.

---

## 3. Failed sudo Attempts (Linux) → T1110.001 (Password Guessing)

**Event:** `/var/log/auth.log`  
**What I did:** Typed the wrong sudo password on purpose  
**Why it maps:**  
Multiple failed sudo attempts can indicate someone trying to guess a privileged password.

---

## 4. Ping Loop / ICMP Noise → T1498 (Network Flooding)

**Event:** Continuous ICMP traffic (`ping -t`)  
**Why it maps:**  
A ping flood can overwhelm a machine or network. MITRE puts this under network flooding and denial techniques.

---

## Summary 

Mapping my activity to MITRE helped me understand how specific events fit into bigger attacker behaviors. Even small logs can point to techniques like brute force, privilege escalation attempts, and network flooding. This gave me confidence reading logs and connecting them to real-world tactics.
