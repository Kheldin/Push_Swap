# push_swap

> Sort a stack of integers using two stacks and a restricted set of operations with the fewest moves possible. A deep dive into algorithmic complexity, adaptive sorting strategies, and performance optimization in C.

---

## Overview

`push_swap` is a sorting algorithm project built around a constrained environment: two stacks (`a` and `b`), 11 allowed operations, and the goal of producing the shortest possible sequence of moves to sort stack `a` in ascending order.

The project includes two programs: `push_swap`, which generates the operation sequence, and `checker` (bonus), which validates that a sequence correctly sorts the stack.

**Grade: 125/100** — by Kheldin Acherchour & Antoine Rogard

---

## Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap the top two elements of stack a / b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top element of b onto a / a onto b |
| `ra` / `rb` | Rotate stack a / b upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack a / b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Compilation

```bash
make          # Build push_swap
make bonus    # Build push_swap + checker
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Full rebuild
```

---

## Usage

```bash
# Sort a list of integers
./push_swap 3 2 5 1 4

# Count operations
./push_swap 3 2 5 1 4 | wc -l

# Verify correctness with checker
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4

# Test with random input
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | ./checker $(cat args.txt)
./push_swap $(cat args.txt) | wc -l

# Benchmark mode
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt)
```

---

## Algorithm & Design

### Disorder Metric

Before sorting, the program computes a **disorder coefficient**, a value between `0` (perfectly sorted) and `1` (maximally disordered) based on the ratio of inverted pairs in the stack. This metric drives the algorithm selection.

```
disorder = inverted_pairs / total_pairs
```

### Adaptive Strategy Selection

Rather than picking an algorithm based on input size alone, `push_swap` selects the most appropriate strategy based on how disordered the data actually is:

**Low disorder (`< 0.2`) → Selection Sort — O(n²)**
For nearly sorted inputs, most elements are already close to their correct position. Selection sort iterates to find the cheapest element to move, minimizing unnecessary rotations. The overhead of heavier algorithms would outweigh any benefit here.

**Medium disorder (`0.2 ≤ x < 0.5`) → Chunk-Based Sort — O(n√n)**
The input is divided into √n chunks. Elements are pushed to stack `b` chunk by chunk, with selection sort used within each chunk to choose the locally optimal move. This balances the stacks efficiently and avoids the O(n²) cost of full selection on larger inputs.

**High disorder (`≥ 0.5`) → LSD Binary Radix Sort — O(n log n)**
For highly shuffled inputs, radix sort processes integers bit by bit from the least significant bit (LSB) to the most significant. At each bit position, elements are partitioned into two groups using push operations, then reassembled. Performance is predictable and does not degrade with disorder making it ideal for worst-case random data.

LSD was chosen over MSD for its sequential, stack-friendly processing and simpler implementation within the push_swap operation model.

### Why This Hybrid Approach?

No single algorithm is universally optimal. A 1000-element nearly-sorted array benefits from selection sort, while a 50-element random array may be better handled by radix. The disorder coefficient provides an objective, data-driven selection criterion that consistently outperforms size-only heuristics.

---

## Performance|

Achieved results with our implementation:

| Input | Algorithm | Operations |
|-------|-----------|-----------|
| 100 (high disorder) | Radix | 1084 |
| 500 (high disorder) | Radix | 6784 |

---

## Project Structure

```
push_swap/
├── algorithms/       # Selection, chunk, and radix sort implementations
├── bench/            # Benchmark mode output handling
├── bonus/            # Checker program
├── includes/         # Header files
├── libft/            # Custom libft
├── operations/       # Stack operations (sa, pb, ra, rra...)
├── parser/           # Argument parsing and input validation
├── utils/            # Stack management, disorder computation
├── main.c            # Entry point — strategy dispatcher
├── checker_bonus.c   # Checker entry point
└── Makefile
```

---

## Contributors

| Login | Contributions |
|-------|--------------|
| **Kacherch** (Kheldin Acherchour) | Radix sort, Makefile |
| **Anrogard** (Antoine Rogard) | selection sort, chunk sort |
| **Both** | Parsing, stack operations, algorithm design, testing, checker |

> We maintained constant collaboration throughout — both members can explain and defend every part of the codebase independently.

---

## Resources

- [Radix Sort — GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Selection Sort — GeeksforGeeks](https://www.geeksforgeeks.org/selection-sort/)
- [Big-O Complexity — GeeksforGeeks](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/)

---

*This project was created as part of the 42 curriculum by Kacherch, Anrogard.*
