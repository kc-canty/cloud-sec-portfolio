# Lab 3 – Network Security Monitoring & MITRE ATT&CK Mapping

This lab is my hands-on practice with reading system logs, generating suspicious activity on purpose, and mapping that activity to MITRE ATT&CK techniques. I’m still new to security, so the goal here wasn’t to be perfect — it was just to learn what different types of events look like and get comfortable explaining them.

---

## What I Did in This Lab

To understand how attackers leave traces in logs, I manually generated different kinds of activity on both Windows and Linux:

### Windows
- Created multiple **failed logon attempts** using `runas`  
- Ran common reconnaissance commands like `whoami`, `ipconfig`, and `systeminfo`  
- Created noisy network traffic using a **ping loop**

### Linux (WSL)
- Entered the wrong sudo password on purpose  
- Checked `/var/log/auth.log` to see how Linux logs privilege escalation failures

This gave me real log data to practice with, instead of guessing.

---

## What I Learned

### 1. Failed Logons (Event ID 4625)
I could clearly see when I mistyped passwords or used a fake username.  
This helped me understand how brute-force activity starts showing up.

### 2. Recon Commands (Event ID 4688)
Commands like `whoami` and `systeminfo` show up in process creation logs.  
These are often used by attackers early on.

### 3. Failed sudo Attempts
Linux records these in `/var/log/auth.log` with very clear detail.  
Seeing this helped me understand how privilege escalation attempts look.

### 4. Noisy ICMP Traffic
A simple ping loop generates a surprising amount of network noise.  
I can see why defenders pay attention to ICMP traffic patterns.

---

## MITRE ATT&CK Mapping

I mapped each activity to the MITRE technique that made the most sense:

- **T1110 – Brute Force** → Failed Windows logons  
- **T1110.001 – Password Guessing** → Failed sudo attempts  
- **T1059 – Command-Line Execution** → Recon commands  
- **T1498 – Network Flooding** → Ping loop / ICMP noise  

This helped me connect what I did to real attacker behavior.

---

## Files in This Lab
- **event-notes.md** → My raw log observations  
- **mitre-mapping.md** → Beginner-friendly MITRE mapping  
- **network-report.md** → Final summary report  
- **screenshots/** → Log screenshots from Windows and Ubuntu  

---

## Notes & Troubleshooting
## Why Event ID 5156 Didn’t Appear, But MITRE T1498 Still Applies

When I ran the ping loop (`ping 127.0.0.1 -t`), I noticed that Windows did not generate Event ID 5156 (“A network connection was allowed”). At first I expected this event to show up, so I dug into why it didn’t — and it actually made sense once I understood how Windows logs network activity.

There are two reasons this happened:

### 1. I Used the Loopback Address (127.0.0.1)
Traffic to 127.0.0.1 never leaves the machine. Since it doesn’t cross a real network boundary, Windows Filtering Platform does not treat it as a new network connection. Because of that, no 5156 event is created.

### 2. ICMP Traffic Doesn’t Always Trigger 5156
5156 logs are more consistent with TCP/UDP connections. ICMP (which ping uses) sometimes won’t produce a 5156 event unless it’s going over an external network interface.

Because of both of these reasons, the ping loop didn’t generate a 5156 event — but the behavior still represents a form of network flooding.

### Why I Still Mapped This Activity to MITRE Technique T1498
MITRE ATT&CK techniques describe the behavior itself, not specific Windows event IDs.  
T1498 (“Network Denial / Network Flooding”) reflects the *intent and action* — generating repetitive ICMP traffic that could overwhelm a system or network.

Even without a 5156 event, the ping loop still qualifies as network-flooding behavior in MITRE terms. The lab helped me understand the important difference between:

- **MITRE Technique IDs** (which describe attacker behaviors), and  
- **Windows Event IDs** (which are just the logging details for certain actions).

This made me more comfortable analyzing how behavior and logging don’t always perfectly match, especially with ICMP traffic or loopback scenarios.

---

## Why This Lab Matters to Me

This was my first real practice tying actual logs to attacker techniques. I feel more comfortable reading logs now, and I can explain what I’m seeing in a way that makes sense. It helped me think more like an analyst and less like someone reading definitions.

This is the kind of work I’m excited to do as I break into cybersecurity.

