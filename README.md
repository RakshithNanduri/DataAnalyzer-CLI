# DataAnalyzer-CLI

A command-line data analysis program written in C. It provides basic statistics, searching, sorting, text-file persistence, and runtime-sized dataset storage using `malloc`, `realloc`, and `free`.

<p align="left">
  <a href="https://github.com/RakshithNanduri/DataAnalyzer-CLI/actions/workflows/build.yml"><img src="https://github.com/RakshithNanduri/DataAnalyzer-CLI/actions/workflows/build.yml/badge.svg" alt="Build status"></a>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Interface-CLI-111827?style=flat-square" alt="CLI">
  <img src="https://img.shields.io/badge/Storage-Dynamic%20Memory-475569?style=flat-square" alt="Dynamic memory">
</p>

## Overview

DataAnalyzer-CLI is a learning-focused C application for working with integer datasets from the terminal. A user can enter data, calculate descriptive statistics, search for values, sort the dataset, save it to a text file, and load it again later.

I built the project to move beyond small standalone C exercises and practise several responsibilities inside one program: array processing, algorithms, functions, file handling, and manual memory management.

## Capabilities

| Area | Operations |
|---|---|
| Statistics | Sum, average, minimum, maximum, range, median, mode |
| Search | Linear Search, Binary Search |
| Sorting | Bubble Sort in ascending and descending order |
| Memory | Runtime allocation with `malloc`, resizing with `realloc`, cleanup with `free` |
| Persistence | Save dataset to `Database.txt`, load it back into memory |
| Safety checks | Invalid size, allocation failure, reallocation failure, missing file |

## How the program works

```text
Create or load dataset
        |
        v
Runtime-sized integer storage
        |
        +--> Statistics
        +--> Linear Search
        +--> Bubble Sort
        +--> Binary Search after sorting
        +--> Save to file
        |
        v
Free allocated memory on exit
```

The program keeps the current dataset in dynamically allocated memory. Loading a stored dataset can change its required size, so the allocation is resized before the values are read into memory.

## Project structure

```text
DataAnalyzer-CLI/
├── .github/
│   └── workflows/
│       └── build.yml
├── main.c
├── Database.txt
├── README.md
├── .gitignore
└── .gitattributes
```

The current application intentionally remains in one C source file. This keeps the project focused on algorithms, file handling, and memory management rather than introducing a multi-file architecture before it is needed.

## Build and run

### Requirements

- A C compiler such as GCC, Clang, or MSVC
- A terminal or command prompt

### Clone the repository

```bash
git clone https://github.com/RakshithNanduri/DataAnalyzer-CLI.git
cd DataAnalyzer-CLI
```

### Compile with GCC

```bash
gcc main.c -o dataanalyzer
```

### Run

Linux or macOS:

```bash
./dataanalyzer
```

Windows:

```powershell
.\dataanalyzer.exe
```

MSVC can also compile the program with:

```powershell
cl main.c /Fe:dataanalyzer.exe
```

## Available operations

The numbered menu provides operations for:

```text
Sum
Average
Minimum
Maximum
Linear Search
Bubble Sort ascending
Bubble Sort descending
Range
Median
Mode
Save dataset
Load dataset
Binary Search
Exit
```

Binary Search is used on sorted data. The current implementation sorts the active dataset into ascending order before carrying out that search.

## Example session

```text
Dataset: 10 20 30 40 50

Choose: Sum
Result: 150

Choose: Median
Result: 30
```

The exact terminal wording depends on the current program output, but the workflow is menu-driven throughout.

## Implementation details

### Dynamic dataset storage

The dataset size is chosen at runtime. Memory is allocated with `malloc` instead of using a fixed-capacity global array.

When a saved dataset is loaded, `realloc` is called through a temporary pointer. The original allocation is retained if resizing fails.

### Statistics

The program calculates:

- sum and average;
- minimum and maximum;
- range as maximum minus minimum;
- median after ordering the data;
- mode through occurrence counting.

### Searching

Linear Search scans values in sequence and returns the matching index when a target is found.

Binary Search works on ascending data and repeatedly reduces the remaining search interval until the target is found or no search range remains.

### Sorting

Bubble Sort is implemented in both ascending and descending order. It is intentionally the only sorting algorithm in the current version.

### File persistence

`Database.txt` stores the dataset so it can be restored in a later program run. The loader reads the stored size, resizes the active allocation, and then reads the stored values.

## Automated build check

GitHub Actions compiles `main.c` on pushes and pull requests. This catches build regressions, but the repository does not currently include automated behavioral tests for the interactive menu or numerical results.

## What I learned

This project gave me practical experience with:

- separating values from their array indexes;
- writing search and sorting functions;
- understanding why Binary Search requires sorted data;
- allocating memory at runtime;
- resizing memory without losing the original pointer on failure;
- releasing memory before program exit;
- combining algorithms with file persistence in one C program.

The project was completed with AI-assisted guidance and debugging. Later blank-file practice showed that some algorithm details, especially multi-step state tracking and exact loop boundaries, still need repetition. The repository therefore documents guided implementation experience rather than complete DSA mastery.

## Current limitations

- Single-file C implementation
- Integer datasets only
- Bubble Sort is the only sorting algorithm
- Plain-text persistence
- Basic `scanf`-based interactive input
- No automated behavioral test suite
- No performance benchmarking or algorithm comparison

The project is feature-frozen at its current learning goal. Future changes should address a reproduced bug or a specific learning objective rather than add features only to make the repository appear larger.

## Author

**Rakshith Nanduri**  
Computer Science student building foundations in C, Python, algorithms, and software engineering.

- GitHub: https://github.com/RakshithNanduri
- Portfolio: https://rakshith-nanduri-portfolio.vercel.app
