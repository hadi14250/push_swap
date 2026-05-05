<div align="center">
  <a href="https://github.com/hadi14250">
    <img src="github_gifs/stack.gif" alt="stack gif" width="150" height="150">
  </a>

  <h1 align="center">Push Swap</h1>

  <p align="center">
    <i>Code Your Own Stack Sorting Algorithm</i>
  </p>

  <br>

  <a href="https://github.com/hadi14250">
    <img src="github_gifs/sort.gif" alt="sort gif" width="600" height="400">
  </a>
</div>

<br>

## About

Push Swap is a sorting challenge built around two stacks. Stack `A` is loaded with a list of unique integers in random order, while stack `B` starts empty. Using only a small, fixed set of stack operations, the program must produce a sequence of moves that leaves `A` sorted in ascending order. The output is a list of operation names that can be replayed by a separate checker program to confirm the sort is valid.

The real challenge is not just sorting — it's sorting in **as few moves as possible**.

<br>

## How It Works

The program reads integers from the command line, validates them, and loads them onto stack `A`. From there, it picks a sorting strategy based on the input size:

- **Tiny inputs (≤ 5 numbers)** — hand-tuned move sequences that hit the minimum operation count.
- **Larger inputs** — a chunk-based approach that splits values into ranges, pushes them to stack `B` in a controlled order, then rotates them back into `A` so each insertion costs as few moves as possible.

The chosen approach in this repository is internally referred to as the **"Sand Clock"** method — values flow between the two stacks in a pattern that keeps the average operation count well below the bonus threshold for the assignment.

<br>

## Features

- Two-stack sorting with a strict, limited instruction set
- Separate strategies for small and large inputs
- Averages **under 5,500 operations** on the standard 100-number benchmark
- Custom checker (`checker_Mac`) included to validate output
- Optional Python visualizer (`python_visualizer.py`) to watch the stacks animate as moves are applied
- Bonus checker implementation in `push_swap_bonus/`

<br>

## Stack Operations

| Op    | Description                                              |
| ----- | -------------------------------------------------------- |
| `sa`  | Swap the first two elements of stack A                   |
| `sb`  | Swap the first two elements of stack B                   |
| `ss`  | `sa` and `sb` at the same time                           |
| `pa`  | Push the top of stack B onto stack A                     |
| `pb`  | Push the top of stack A onto stack B                     |
| `ra`  | Rotate stack A up (first element becomes the last)       |
| `rb`  | Rotate stack B up                                        |
| `rr`  | `ra` and `rb` at the same time                           |
| `rra` | Reverse-rotate stack A (last element becomes the first)  |
| `rrb` | Reverse-rotate stack B                                   |
| `rrr` | `rra` and `rrb` at the same time                         |

<br>

## Build

```bash
make            # builds the push_swap binary
make bonus      # builds the bonus checker (in push_swap_bonus/)
make clean      # removes object files
make fclean     # removes object files and binaries
make re         # full rebuild
```

<br>

## Usage

```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Pipe the moves into the provided checker to validate
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG

# Count how many operations a given input takes
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

A successful sort prints `OK` from the checker. Invalid input (duplicates, non-numeric tokens, values outside `int` range) exits with `Error` on stderr.

<br>

## Visualizer

A small Python visualizer is included for debugging and demoing the algorithm:

```bash
python3 python_visualizer.py
```

It animates the two stacks as the operations from `push_swap` are applied, which is helpful for spotting wasted moves.

<br>

## Repository Layout

| Path                                                            | Purpose                                              |
| --------------------------------------------------------------- | ---------------------------------------------------- |
| `push_swap.c`, `push_swap.h`                                    | Entry point and shared declarations                  |
| `a_operations.c`, `b_operations.c`, `ops.c`                     | The stack operations                                 |
| `parse_operations*.c`, `assign.c`, `add_new.c`                  | Input parsing and stack setup                        |
| `sort_normally.c`, `sort_4_chunks.c`, `sorts/`                  | Sorting strategies for different input sizes         |
| `chunk_extras.c`, `extras.c`, `seperate.c`, `max_and_tops.c`, `long_limits.c` | Supporting helpers                     |
| `checkers.c`, `checker_Mac`                                     | Checker logic and prebuilt macOS checker binary      |
| `push_swap_bonus/`                                              | Bonus checker project                                |
| `python_visualizer.py`                                          | Optional visualizer                                  |
| `github_gifs/`                                                  | README assets                                        |

<br>

<div align="center">
  <a href="https://github.com/hadi14250">
    <img src="github_gifs/stack.gif" alt="stack gif" width="80" height="80">
  </a>
</div>
