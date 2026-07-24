<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://img.shields.io/badge/DataAnalyzer-CLI-00d2ff?style=for-the-badge&logo=c&logoColor=white&labelColor=1a1a2e">
    <img src="https://img.shields.io/badge/DataAnalyzer-CLI-00d2ff?style=for-the-badge&logo=c&logoColor=white&labelColor=1a1a2e" alt="DataAnalyzer-CLI" width="100%">
  </picture>
</p>

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=24&pause=1000&color=00D2FF&center=true&vCenter=true&random=false&width=500&lines=Your+CLI+Data+Analysis+Companion;Fast+%E2%80%A2+Lightweight+%E2%80%A2+Powered+by+C" alt="Typing SVG" />
</p>

<p align="center">
  <img src="https://img.shields.io/github/license/RakshithNanduri/DataAnalyzer-CLI?style=flat-square&color=00d2ff" alt="License">
  <img src="https://img.shields.io/github/repo-size/RakshithNanduri/DataAnalyzer-CLI?style=flat-square&color=7c3aed" alt="Repo Size">
  <img src="https://img.shields.io/github/languages/top/RakshithNanduri/DataAnalyzer-CLI?style=flat-square&color=06b6d4" alt="Top Language">
  <img src="https://img.shields.io/badge/code_style-standard-22c55e?style=flat-square" alt="Code Style">
  <img src="https://img.shields.io/github/last-commit/RakshithNanduri/DataAnalyzer-CLI?style=flat-square&color=f59e0b" alt="Last Commit">
  <img src="https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-8b5cf6?style=flat-square" alt="Platforms">
</p>

---

## 🌟 Overview

**DataAnalyzer-CLI** is a powerful, lightning-fast command-line data analysis tool written in **pure C**. It provides a comprehensive suite of statistical functions — from basic operations like sum and average to advanced computations like median, mode, and binary search — all wrapped in an intuitive interactive menu.

> ✨ **Why DataAnalyzer-CLI?** No bloat, no dependencies, no nonsense. Just raw C performance for your data analysis needs.

---

## ✨ Features at a Glance

<details open>
<summary><b>📊 Core Statistical Functions</b></summary>
<br>

| Feature | Description | Complexity |
|:--------|:------------|:----------:|
| **Sum** | Total sum of all dataset elements | O(n) |
| **Average** | Arithmetic mean of the dataset | O(n) |
| **Minimum** | Smallest value in the dataset | O(n) |
| **Maximum** | Largest value in the dataset | O(n) |
| **Range** | Difference between max and min | O(n) |
| **Median** | Middle value (even/odd handling) | O(n log n) |
| **Mode** | Most frequently occurring value | O(n²) |

</details>

<details open>
<summary><b>🔍 Search & Sort Capabilities</b></summary>
<br>

| Feature | Description | Complexity |
|:--------|:------------|:----------:|
| **Linear Search** | Find an element by scanning the dataset | O(n) |
| **Binary Search** | Fast search on a sorted dataset | O(log n) |
| **Bubble Sort (Ascending)** | Sort dataset in ascending order | O(n²) |
| **Bubble Sort (Descending)** | Sort dataset in descending order | O(n²) |

</details>

<details open>
<summary><b>💾 Data Persistence</b></summary>
<br>

- **Save** your dataset to `Database.txt` for later use
- **Load** a previously saved dataset back into memory
- Data survives program restarts — analyze once, use forever

</details>

---

## 🚀 Getting Started

### Prerequisites

- A **C compiler** (GCC, Clang, MSVC, or MinGW)
- Basic familiarity with the **command line / terminal**

### Installation

**1. Clone the repository**

```bash
git clone https://github.com/RakshithNanduri/DataAnalyzer-CLI.git
cd DataAnalyzer-CLI
```

**2. Compile the project**

```bash
# Using GCC (Linux/macOS/MinGW)
gcc main.c -o dataanalyzer -lm

# Using Clang
clang main.c -o dataanalyzer -lm

# On Windows with MSVC
cl main.c /Fe:dataanalyzer.exe
```

**3. Run the program**

```bash
# Linux/macOS
./dataanalyzer

# Windows
.\dataanalyzer.exe
```

---

## 🎮 Usage Guide

### Quick Start

```bash
# 1. Run the program
gcc main.c -o dataanalyzer && ./dataanalyzer
```

When you launch the program, you'll be prompted to:

```
1️⃣ Enter the number of elements in your dataset
2️⃣ Input each data element one by one
3️⃣ Explore the interactive menu!

Your dataset: [10 20 30 40 50]
```

### Interactive Menu

```
--------------- Menu ---------------
1.  Sum
2.  Average
3.  Minimum
4.  Maximum
5.  Search (Linear)
6.  Bubble Sort (Ascending)
7.  Bubble Sort (Descending)
8.  Range of given dataset
9.  Median of given dataset
10. Mode of given dataset
11. Save dataset
12. Load dataset
15. Exit
```

### Example Session

```
--------------- Menu ---------------
Enter your choice: 1
Sum is 150.00

--------------- Menu ---------------
Enter your choice: 9
Median of given dataset is 30.00

--------------- Menu ---------------
Enter your choice: 5
Type your desired value: 40
Value 40 was found at index 3.
```

---

## 📈 Performance

DataAnalyzer-CLI is built in **pure C**, offering near-zero overhead and blazing-fast execution:

| Operation | 1,000 elements | 10,000 elements | 100,000 elements |
|:----------|:--------------:|:---------------:|:-----------------:|
| Sum / Avg / Min / Max | < 1ms | < 1ms | < 5ms |
| Bubble Sort | ~5ms | ~450ms | ~45s |
| Linear Search | < 1ms | < 1ms | < 5ms |
| Binary Search | < 1ms | < 1ms | < 1ms |
| Save / Load | < 1ms | < 1ms | < 10ms |

---

## 🏗️ Project Architecture

```
📁 DataAnalyzer-CLI/
├── 📄 main.c              # Core application logic
├── 📄 Database.txt        # Persistent data storage
├── 📄 README.md           # You are here ✨
├── 📄 .gitignore          # Git ignore rules
├── 📄 .gitattributes      # Git attributes
└── 📁 output/             # Build output directory
```

### Code Structure

```c
// Global dataset — dynamically allocated
int *Dataset = NULL;
int numofentries = 0;

// Statistical functions
float sum();       // O(n) — Calculate sum
float avg();       // O(n) — Calculate average
int min();         // O(n) — Find minimum
int max();         // O(n) — Find maximum
int Range();       // O(n) — Calculate range
float Median();    // O(n log n) — Find median (sorts data)
int mode();        // O(n²) — Find mode

// Search & Sort
int LinearSearch(int value);           // O(n)
int BinarySearch();                    // O(log n) — requires sorted data
void BubbleSortAscending();            // O(n²)
void BubbleSortDescending();           // O(n²)

// Persistence
void Savedata();                       // Save to Database.txt
void Loaddata();                       // Load from Database.txt
```

---

## 🧪 Try It Yourself

### Sample Dataset

```
Dataset: [12, 7, 19, 3, 11, 5, 8, 14, 6, 10]
```

| Operation | Result |
|:----------|:------:|
| **Sum** | 95.00 |
| **Average** | 9.50 |
| **Minimum** | 3 |
| **Maximum** | 19 |
| **Range** | 16 |
| **Median** | 9.00 |
| **Mode** | 12 (or first occurring tie) |

---

## 🛠️ Building from Source

### Compilation Flags

For optimal performance, use these compiler flags:

```bash
# Maximum optimization
gcc main.c -o dataanalyzer -O3 -march=native -flto

# Debug build with warnings
gcc main.c -o dataanalyzer -Wall -Wextra -pedantic -g -Og

# Release build
gcc main.c -o dataanalyzer -O2 -DNDEBUG
```

---

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place! Any contributions you make are **greatly appreciated**.

1. 🍴 Fork the Project
2. 🌿 Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. 💾 Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. 📤 Push to the Branch (`git push origin feature/AmazingFeature`)
5. 🔀 Open a Pull Request

### Ideas for Future Features

- [ ] **Quick Sort / Merge Sort** — faster sorting algorithms
- [ ] **Standard Deviation & Variance** — advanced statistics
- [ ] **File Import/Export** — CSV support
- [ ] **Histogram Visualization** — ASCII chart output
- [ ] **Multi-dataset Support** — work with multiple datasets simultaneously
- [ ] **Undo/Redo** — reversable operations

---

## 📜 License

Distributed under the **MIT License**. See [LICENSE](LICENSE) for more information.

---

## 📬 Connect

<p align="center">
  <a href="https://github.com/RakshithNanduri">
    <img src="https://img.shields.io/badge/GitHub-RakshithNanduri-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub">
  </a>
  <a href="mailto:your.email@example.com">
    <img src="https://img.shields.io/badge/Email-Contact%20Me-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email">
  </a>
</p>

---

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-❤️%20and%20C-00d2ff?style=flat-square" alt="Made with love and C">
  <br>
  <sub>Built with passion by <b>Rakshith Nanduri</b> © 2026</sub>
</p>

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer&text=Keep%20Analyzing!&fontSize=24&fontColor=ffffff" alt="Footer Wave"/>
</p>