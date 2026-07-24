# DataAnalyzer-CLI

_A lightweight data analysis tool written in pure C — run entirely from your terminal._

<p align="center">
  <img src="https://img.shields.io/badge/language-C-00599C?style=flat-square" alt="Language: C">
  <img src="https://img.shields.io/badge/build-passing-22c55e?style=flat-square" alt="Build: Passing">
  <img src="https://img.shields.io/badge/license-MIT-8b5cf6?style=flat-square" alt="License: MIT">
  <img src="https://img.shields.io/badge/platform-Windows%20|%20Linux%20|%20macOS-06b6d4?style=flat-square" alt="Platforms">
</p>

---

## What is this?

**DataAnalyzer-CLI** is a command-line program that lets you enter a dataset and run various statistical operations on it — sum, average, min, max, range, median, mode, search, and sorting. It saves your data to a file so you can come back to it later.

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

```
--------------- Menu ---------------
1.  Sum
2.  Average
3.  Minimum
4.  Maximum
5.  Search
6.  Bubblesort (Ascending)
7.  Bubblesort (Descending)
8.  Range
9.  Median
10. Mode
11. Save dataset
12. Load dataset
15. Exit
```

---

## Example

```
Your dataset: [10 20 30 40 50]

Enter your choice: 1
Sum is 150.00

Enter your choice: 9
Median of given dataset is 30.00
```

---

## Project Structure

```
DataAnalyzer-CLI/
├── main.c           # The entire program
├── Database.txt     # Auto-generated data file
├── README.md
├── .gitignore
└── .gitattributes
```

The whole application lives in a single `main.c` file — no external dependencies, no configuration files, just one file to compile and run.

---

## Technical Details

- **Memory**: Dynamically allocated array using `malloc` / `realloc`
- **Persistence**: Saves/loads dataset to/from `Database.txt` in plain text
- **Algorithms**: Bubble Sort (O(n²)), Linear Search (O(n)), Binary Search (O(log n))
- **Functions**: `sum()`, `avg()`, `min()`, `max()`, `Range()`, `Median()`, `mode()`, `LinearSearch()`, `BinarySearch()`, `BubbleSortAscending()`, `BubbleSortDescending()`, `Savedata()`, `Loaddata()`

---

## License

MIT