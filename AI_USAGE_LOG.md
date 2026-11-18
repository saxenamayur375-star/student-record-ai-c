# AI Usage Log

**Project Title**: AI-Assisted Student Record and Result Management System  
**Course Code & Name**: PRC1001 – Programming in C  
**Degree & Specialization**: B.Tech CSE (Semester I)  
**Institution**: University of Petroleum and Energy Studies (UPES), Dehradun  
**Student Name**: Mayur Saxena  
**SAP ID**: 590032873  
**Submission Date**: 19 November 2026  

---

## 📋 Overview of AI Assistance
In accordance with the project guidelines, AI tools (ChatGPT and GitHub Copilot) were utilized as learning assistants for:
1. Formulating the criteria and tier structure for the rule-based Academic Advisor.
2. Generating diverse boundary test cases for CGPA and year-wise cohort calculations.
3. Structuring clean C code adhering to ANSI C standards with appropriate memory and string handling.
4. Designing comprehensive test inputs and structured Markdown project documentation.

All AI-suggested concepts were thoroughly analyzed, validated, and translated into native C logic using structures, arrays, pointers, functions, and conditional decision blocks.

---

## 📊 Detailed AI Usage Log

| AI Tool | Prompt / Question Asked | How I Used / Verified the Response |
| :--- | :--- | :--- |
| **ChatGPT** | *"Suggest simple CGPA-based academic advice and performance tiers for university engineering students without using an external API."* | **Concept Formulation**: The AI suggested four distinct performance tiers: *Excellent Performance* ($\ge 8.5$), *Good Performance* ($7.0 - 8.49$), *Needs Improvement* ($5.5 - 6.99$), and *Requires Immediate Attention* ($< 5.5$). I adopted these tiers and translated them into an `if-else` ladder in C within `giveAcademicAdvice()`. |
| **ChatGPT** | *"How can an academic advisor function provide personalized tips beyond just overall CGPA?"* | **Feature Enhancement**: The AI proposed inspecting the lowest completed semester SGPA. I verified and implemented this by writing a loop over `sgpa[0..7]` that identifies the lowest non-zero score and pinpoints the exact semester needing extra focus. |
| **ChatGPT** | *"Give test cases for a CGPA calculation function where students have varying numbers of completed semesters (some semesters yet to be completed)."* | **Edge-Case Validation**: ChatGPT provided cases with zeroes for upcoming semesters. I verified that dividing by a fixed 8 produces incorrect results, so I engineered the logic to compute the average strictly over semesters where `sgpa[i] > 0.0f`. |
| **GitHub Copilot** | *"Suggest safe C string and numeric input reading techniques using `scanf` inside a console menu loop to prevent buffer overflow and infinite loops on whitespace."* | **Input Hardening**: Copilot suggested using field-width specifiers (`%49[^\n]` for multi-word names and `%19s` for roll numbers) along with a leading space to discard trailing newline characters. I manually tested this to ensure clean menu navigation. |
| **ChatGPT** | *"How to perform Bubble Sort on an array of structs in C without modifying the original student insertion order?"* | **Algorithm Implementation**: The AI recommended copying the global array of structures into a local temporary array before sorting. I verified this behavior in `displaySortedBySapId()` and `displaySortedByName()`, ensuring the primary record sequence remains untouched. |
| **ChatGPT** | *"Help draft a structured README.md and sample test plan for an academic C programming submission with GitHub version control."* | **Documentation**: Reviewed the suggested layout, tailored all paths, filenames, SAP ID references, and compilation instructions for GCC on Windows. |

---

## 💡 Key Learning Outcomes
1. **Prompt Engineering**: Formulated focused technical prompts to generate clean, modular logic instead of vague queries.
2. **Critical Verification**: Discovered that naive CGPA division by 8 skews junior students' scores; refined algorithm to compute dynamic averages over active semesters only.
3. **Translating Concepts to C**: Converted abstract advisory guidelines into efficient C functions using `struct Student`, pointers, and `if-else` branches.
4. **Version Control Integration**: Practiced incremental commits on GitHub, issue tracking, and maintaining a transparent audit log of AI usage.
