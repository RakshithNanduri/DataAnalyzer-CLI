# DataAnalyzer-CLI

A menu-driven C program for working with integer datasets from the terminal. It can calculate basic statistics, search and sort values, save data to a text file, load it again, and resize the active dataset with dynamic memory.

<p align="left">
  <a href="https://github.com/RakshithNanduri/DataAnalyzer-CLI/actions/workflows/build.yml"><img src="https://github.com/RakshithNanduri/DataAnalyzer-CLI/actions/workflows/build.yml/badge.svg" alt="Build status"></a>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Interface-CLI-111827?style=flat-square" alt="CLI">
  <img src="https://img.shields.io/badge/Memory-malloc%20%2F%20realloc-475569?style=flat-square" alt="Dynamic memory">
</p>

[Portfolio case study](https://rakshith-nanduri-portfolio.vercel.app/work/data-analyzer)

## Why I built it

I wanted one C project where the array and algorithm topics I had been practising had to work together instead of living in separate exercise files.

DataAnalyzer-CLI became that project: one active dataset, a menu of operations, file persistence, and manual memory management.

## What it can do

| Area | Operations |
|---|---|
| Statistics | Sum, average, minimum, maximum, range, median, mode |
| Search | Linear Search, Binary Search |
| Sorting | Bubble Sort ascending and descending |
| Memory | `malloc`, `realloc`, `free` |
| Persistence | Save to and load from `Database.txt` |
| Checks | Invalid size, allocation/reallocation failure, missing file |

## Program flow

```text
Enter or load a dataset
        |
        v
Dynamically allocated integer storage
        |
        +--> Statistics
        +--> Linear Search
        +--> Bubble Sort
        +--> Binary Search on sorted data
        +--> Save / load
        |
        v
Release memory on exit
```

The active dataset is allocated at runtime instead of using a fixed-size array. When a stored dataset has a different size, the program resizes the allocation before loading its values.

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

The program stays in one C source file on purpose. At this stage I wanted to focus on the algorithms, files, and memory rather than turn it into a multi-file architecture exercise.

## Build and run

### Requirements

- GCC, Clang, MSVC, or another C compiler
- A terminal or command prompt

### Clone

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

MSVC:

```powershell
cl main.c /Fe:dataanalyzer.exe
```

## Menu operations

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

Binary Search is only used after the data has been put into ascending order.

## Example

```text
Dataset: 10 20 30 40 50

Choose: Sum
Result: 150

Choose: Median
Result: 30
```

The exact prompts depend on the current menu output, but the program stays terminal-based throughout.

## A few implementation details

### Dynamic memory

The user chooses the dataset size at runtime, so the program allocates memory with `malloc`.

When loading saved data, `realloc` is used through a temporary pointer so the old allocation is not immediately lost if resizing fails.

### Statistics

The program calculates sum, average, minimum, maximum, range, median, and mode. Median uses ordered data; mode is found by counting repeated values.

### Searching

Linear Search checks values in sequence.

Binary Search works on sorted data and repeatedly narrows the remaining search range until the value is found or there is nowhere left to search.

### Sorting

Bubble Sort is implemented in both ascending and descending order. It is intentionally the only sorting algorithm in this version.

### File persistence

`Database.txt` stores a dataset so it can be restored later. The loader reads the stored size, resizes the active memory, and then loads the values.

## Build check

GitHub Actions compiles `main.c` on pushes and pull requests. It catches build problems, but the repository does not currently run automated interactive or numerical behavior tests.

## What I learned

This project helped several C ideas click together for me:

- keeping array indexes separate from the values stored at those indexes;
- writing search and sorting functions;
- understanding why Binary Search needs sorted data;
- allocating memory at runtime;
- resizing memory without immediately throwing away the original pointer;
- freeing memory before the program exits;
- combining algorithms with file save/load behavior.

## Limits of this version

- One C source file
- Integer datasets only
- Bubble Sort is the only sorting algorithm
- Plain-text persistence
- Basic `scanf`-based input
- No automated behavior test suite
- No benchmarking or algorithm comparison

The project is feature-frozen at this learning goal. I would rather keep a small project I understand than keep adding features only to make the repository look larger.

## Build context

I completed DataAnalyzer-CLI with AI-assisted guidance and debugging. Later blank-file practice showed that some algorithm details and loop boundaries still need repetition, so I treat this as guided implementation experience rather than complete DSA mastery.

---

**Rakshith Nanduri** · Computer Science student  
[GitHub](https://github.com/RakshithNanduri) · [Portfolio](https://rakshith-nanduri-portfolio.vercel.app)
