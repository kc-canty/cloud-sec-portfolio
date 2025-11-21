# Cloud Security & Cyber Lab Projects

This repo is where I'm keeping track of a few security labs I'm doing while learning more about cloud security, software security, and basic network monitoring.  
The goal is to build a small portfolio that shows my progress as I prepare for Security+ and transition into a cloud/network security engineer role.

These labs are simple, beginner-friendly, and meant to help me understand core concepts by actually doing them.

---

## Lab 1 – C++ Vulnerability Check (Static Analysis)

This lab is me taking a small open-source C++ project and scanning it with a couple of tools (cppcheck and flawfinder) to see what issues come up.  
I'm going through the findings, reading what they mean, and writing down a few notes on potential vulnerabilities and how they could be fixed.

**What I learned so far:**
- how to run cppcheck  
- how static analysis tools flag unsafe or risky code  
- common issues like uninitialized variables and unsafe functions  
- how to write a simple report on what I found  

The files for this lab (reports, notes, etc.) are in the `lab1-cpp-vuln-analysis` folder.

---

## Lab 2 – Basic Network Monitoring + MITRE Mapping

This lab is focused on generating some basic logs, reviewing them, and comparing activity to the MITRE ATT&CK framework.  
I’m using Windows Event Viewer, PowerShell, and Ubuntu (WSL) to practice looking at system activity and understanding what might be suspicious.

**What I'm getting out of this:**
- how to generate events (failed logins, odd commands, etc.)
- how to read and export logs
- matching log behavior to MITRE ATT&CK techniques
- writing short notes on “what happened” and “what it might mean”

Files and write-ups for this one are in the `lab2-network-monitoring-mitre` folder.

---

## Lab 3 – Cloud Threat Modeling (Azure)

This lab is me learning how to think about cloud security by drawing out a simple system and listing possible threats.  
I’m using Azure’s diagrams and general threat modeling ideas (STRIDE, data flow, etc.).  
No actual cloud deployments here, just planning and thinking through how an attacker might target a cloud setup.

**Learning goals:**
- understand basic cloud architecture pieces
- identify possible attack paths
- think through mitigations and controls
- practice documenting a threat model in a beginner-friendly way

Everything for this lab is in the `lab3-cloud-threat-model` directory.

---

## Why I'm Doing These

I'm working toward becoming a Cloud Security Network Engineer.  
I want hands-on practice, even at a small scale, so I can show progress, learn tools, and mostly build confidence.  
Each lab is intentionally small enough to finish in about a day so I don’t lose momentum.

More labs will be added as I keep learning.  THank you for giving me the opportunity!
