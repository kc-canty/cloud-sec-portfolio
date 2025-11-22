# Network Security Monitoring Report (Beginner Summary)

**Lab Goal:**  
To practice generating and reviewing system logs in Windows and Linux, understand what suspicious activity looks like, and connect real events to MITRE ATT&CK techniques.

I created harmless “suspicious” activity on purpose so I could learn how to analyze it like a beginner SOC analyst or security engineer.

---

## What I Did
- Generated failed login attempts on Windows using `runas`
- Created failed sudo attempts in Ubuntu
- Ran common reconnaissance-style commands (`whoami`, `systeminfo`, etc.)
- Created noisy ICMP traffic using a ping loop
- Collected logs from Event Viewer and auth.log
- Mapped the activity to MITRE ATT&CK techniques

---

## Key Things I Learned

### Failed Logons (Windows)
- These showed up as Event ID 4625.
- I used a fake username to trigger them.
- This helped me understand how brute-force events look in logs.

### Failed sudo Attempts (Linux)
- auth.log clearly showed failed privilege escalation.
- I could see my incorrect password attempts.
- I learned how Linux records escalation failures.

### System Reconnaissance Commands
- Commands like `whoami`, `ipconfig`, and `systeminfo` appeared in the logs.
- These are common in early attack phases.
- MITRE classifies them under command execution (T1059).

### ICMP Noise / Ping Loop
- The ping loop created noticeable network activity.
- This helped me understand network “noise” and how it might look during scanning or flooding attacks.

---

## MITRE ATT&CK Mapping Summary (Simple)

| Activity | MITRE Technique | Why |
|---------|------------------|-----|
| Failed Windows logons | **T1110** (Brute Force) | Repeated authentication failures |
| Failed sudo attempts | **T1110.001** (Password Guessing) | Trying to guess a privileged password |
| Recon commands | **T1059** (Command Execution) | Attackers use these to learn about the system |
| Ping flood | **T1498** (Network Flooding) | Noisy ICMP traffic from a ping loop |

---

## Final Thoughts

This was my first time working with logs in a security context. Seeing how Windows and Linux record failed logons, command usage, and network noise helped me understand the basics of how real attackers leave traces.

This lab gave me more confidence reviewing logs and connecting them to actual MITRE techniques. I plan to keep doing more labs like this to build my skills as I aim for my first cybersecurity role.
