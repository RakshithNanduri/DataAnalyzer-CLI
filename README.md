# DataAnalyzer-CLI

_A lightweight data analysis tool written in pure C — run entirely from your terminal._

<p align="center">
  <a href="https://github.com/RakshithNanduri/DataAnalyzer-CLI/actions/workflows/build.yml"><img src="https://github.com/RakshithNanduri/DataAnalyzer-CLI/actions/workflows/build.yml/badge.svg" alt="Build status"></a>
  <img src="https://img.shields.io/badge/language-C-00599C?style=flat-square" alt="Language: C">
  <img src="https://img.shields.io/badge/platform-Windows%20|%20Linux%20|%20macOS-06b6d4?style=flat-square" alt="Platforms">
</p>

---

## What is this?

**DataAnalyzer-CLI** is a command-line program that lets you enter a dataset and run statistical and algorithmic operations on it — sum, average, minimum, maximum, range, median, mode, linear search, binary search, and sorting. It can also save data to a file so you can return to it later.

Everything runs in your terminal with a simple numbered menu.

---

## Features

| Category | Operations |
|----------|-----------|
| **Basic Stats** | Sum, Average, Minimum, Maximum, Range |
| **Advanced Stats** | Median, Mode |
| **Search** | Linear Search, Binary Search |
| **Sorting** | Bubble Sort (Ascending / Descending) |
| **Data Persistence** | Save dataset to file, Load dataset from file |

---

## Getting Started

### 1. Compile

```bash
gcc main.c -o dataanalyzer
```

Or on Windows with MSVC:

```bash
cl main.c /Fe:dataanalyzer.exe
```

### 2. Run

```bash
# Linux / macOS
./dataanalyzer

# Windows
.\dataanalyzer.exe
```

### 3. Use the menu

```text
--------------- Menu ---------------
1.  Sum
2.  Average
3.  Minimum
4.  Maximum
5.  Search
6.  Bubblesort
7.  Descending Order
8.  Range of given dataset
9.  Median of given dataset
10. Mode of given dataset
11. Save dataset
12. Load dataset
13. Binary Search
15. Exit
```

Binary Search first sorts the current dataset into ascending order, then performs the search on that sorted dataset.

---

## Example

```text
Your dataset: [10 20 30 40 50]

Enter your choice: 1
Sum is 150.00

Enter your choice: 9
Median of given dataset is 30.00
```

---

## Project Structure

```text
DataAnalyzer-CLI/
├── .github/workflows/build.yml  # GitHub Actions compile check
├── main.c                       # The entire program
├── Database.txt                 # Data file used by save/load
├── README.md
├── .gitignore
└── .gitattributes
```

The whole application logic lives in a single `main.c` file — no external dependencies or configuration files are required to compile it.

---

## Technical Details

- **Memory**: Dynamically allocated array using `malloc` / `realloc`
- **Persistence**: Saves/loads dataset to/from `Database.txt` in plain text
- **Algorithms**: Bubble Sort (O(n²)), Linear Search (O(n)), Binary Search (O(log n) after sorting)
- **Functions**: `sum()`, `avg()`, `min()`, `max()`, `Range()`, `Median()`, `mode()`, `LinearSearch()`, `BinarySearch()`, `BubbleSortAscending()`, `BubbleSortDescending()`, `Savedata()`, `Loaddata()`
- **CI**: GitHub Actions compiles `main.c` with GCC on every push and pull request

---

## Current Scope

This project is a learning-focused C application. It currently uses a single source file and a plain-text persistence format. The repository has an automated compile check, but it does not yet include automated behavioral tests.
