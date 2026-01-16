_This project has been created as part of the 42 curriculum by Anrogard, Kacherch._

# push_swap
## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program uses two stacks (stack A and stack B) and must sort the numbers in stack A in ascending order.

The project consists of two programs:
- **push_swap**: Takes a list of integers as arguments and outputs the most efficient sequence of operations to sort them
- **checker**: Verifies that a given sequence of operations correctly sorts the stack

This project explores algorithm optimization, complexity analysis, and the implementation of efficient sorting strategies under specific constraints.

## Instructions

### Compilation

```bash
make
```

This will compile both `push_swap` and `checker` programs.

Additional compilation options:
```bash
make clean      # Remove object files
make fclean     # Remove object files and executables
make re         # Recompile everything
```

### Usage

**push_swap:**
```bash
./push_swap <list of integers>
```

Example:
```bash
./push_swap 3 2 5 1 4
```

The program will output the sequence of operations needed to sort the stack.

**checker:**
```bash
./checker <list of integers>
```

The program reads operations from standard input and outputs `OK` if the stack is sorted, or `KO` otherwise.

Example:
```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

### Available Operations

- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: sa and sb simultaneously
- `pa`: push the top element of stack B onto stack A
- `pb`: push the top element of stack A onto stack B
- `ra`: rotate stack A (shift all elements up by one)
- `rb`: rotate stack B
- `rr`: ra and rb simultaneously
- `rra`: reverse rotate stack A (shift all elements down by one)
- `rrb`: reverse rotate stack B
- `rrr`: rra and rrb simultaneously

## Algorithm Explanation

### Strategy Overview

Our implementation uses a **disorder-adaptive strategy** that selects the optimal algorithm based on how disordered the input is, rather than simply its size. We calculate a disorder coefficient and dynamically choose between three approaches: **selection sort**, **chunk-based sorting**, and **LSD binary radix sort**.

### Disorder Coefficient

Before sorting, we analyze the input to calculate its disorder level:
- Measures how far the current arrangement is from sorted order
- Normalized value between 0 (perfectly sorted) and 1 (maximally disordered)
- Determines which algorithm will perform most efficiently

### Algorithm Selection Based on Disorder

**1. Selection Sort (disorder < 0.2)**

For nearly sorted inputs, we use selection sort:
- Finds the optimal element to push to stack B
- Minimizes rotations by selecting elements that require the fewest moves
- Used within chunks as well for fine-grained optimization

**Why selection for low disorder?**
- Nearly sorted inputs have most elements already in correct relative positions
- Selection sort minimizes unnecessary moves
- Overhead of complex algorithms outweighs benefits for low disorder

**2. Chunk-Based Sorting (0.2 ≤ disorder < 0.5)**

For moderately disordered inputs, we partition into chunks:

1. **Partitioning Phase**: Divide numbers into √n chunks.
2. **Selection Within Chunks**: Use selection sort to optimally choose which element to push from each chunk
3. **Push Phase**: Push elements to stack B while maintaining chunk integrity

**Why chunks for moderate disorder?**
- Reduces problem complexity by dividing into manageable segments
- Selection sort within chunks finds optimal moves locally
- Natural load balancing between stacks
- Better than full selection (too slow).

**3. LSD Binary Radix Sort (disorder ≥ 0.5)**

For highly disordered inputs, radix sort is most efficient:

1. **Bit-by-bit Processing**: Examine integers bit by bit, starting from the least significant bit (LSB)
2. **Binary Partitioning**: For each bit position, partition numbers into two groups (0-bit and 1-bit)
3. **Stack Operations**: Use push operations to separate groups, then reassemble in sorted order

**Why Binary LSD Radix for high disorder?**
- **Predictable Complexity**: O(n × k) where k is the number of bits (typically 32)
- **No Comparisons Needed**: Works on binary representation directly
- **Disorder-Independent**: Performance doesn't degrade with shuffled inputs
- **Optimal for Random Data**: When disorder is high, comparing elements is expensive

**Why LSD over MSD?**
- LSD processes bits from right to left, building up sorted order incrementally
- More compatible with stack operations (elements processed sequentially)
- Simpler implementation with available push_swap operations

### Selection Sort Integration

Selection sort is used in two contexts:
1. **Primary algorithm** when disorder < 0.2
2. **Within chunks** to optimally choose which element to push next

This greedy approach ensures locally optimal choices at each step.

### Trade-offs and Design Decisions

**Disorder-Based vs Size-Based:**
- Traditional approaches select algorithms based purely on input size
- Our disorder-based approach adapts to data characteristics
- A 1000-element nearly-sorted array uses selection, not radix
- A 50-element random array might use radix instead of chunks
- Result: Better average performance across diverse inputs

**Chunk Size Calculation:**
- √n Chunk (asked by the subject).

**Selection Within Chunks:**
- Avoids the O(n²) worst-case of pure selection on large inputs

**Why This Hybrid Approach:**
- No single algorithm is optimal for all inputs
- Disorder coefficient provides objective selection criteria
- Selection excels at fine-tuning nearly-sorted data
- Chunks handle medium complexity efficiently
- Radix guarantees performance on worst-case random data

## Resources

### Documentation & References

**Sorting Algorithms:**
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Selection Sort - GeeksforGeeks](https://www.geeksforgeeks.org/selection-sort/)
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)

**Algorithm Analysis:**
- [Time Complexity Analysis - GeeksforGeeks](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/)

### AI Usage

**AI was used EXCLUSIVELY for README creation:**

1. **README Structure and Formatting:**
   - Used Claude to generate this README template following 42 guidelines
   - Ensured all required sections were properly included
   - Formatted markdown for clarity and readability

**Source of Algorithms:**
All algorithms were researched and studied from **GeeksforGeeks** articles.

## Project Development

### Collaborative Work Distribution

#### 🤝 Both Contributors
- **Parsing**: Input validation, argument processing, and error handling
- **Operations**: Core stack operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.)
- **Insertion Sort**: Explored for optimization but ultimately not implemented due to poor performance characteristics with large datasets

#### 👨‍💻 Anrogard (Antoine Rogard)
- **Checker**: Verification program to validate sorting sequences
- **Selection Sort**: Cost-calculation algorithm for optimal element selection
- **Chunk Sort**: Partitioning strategy and chunk-based sorting implementation

#### 👨‍💻 Kacherch (Kheldin Acherchour)
- **Radix Sort**: LSD binary radix sort implementation
- **Makefile**: Compilation rules, dependencies, and build automation

### Development Philosophy

> **We worked together for almost all the parts to be sure that we learned every concept related to the project and be able to redo it on our own.**

While specific components were assigned to each team member, we maintained constant collaboration throughout development. This approach ensured:
- Deep understanding of all algorithms and techniques
- Ability to debug and explain any part of the codebase
- Knowledge transfer between team members
- Individual capability to reproduce the entire project independently

## Testing

### Manual Testing

```bash
# Test with small inputs
./push_swap 2 1 3
./push_swap 5 4 3 2 1

# Test with provided arguments
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

# Count operations
./push_swap 2 1 3 | wc -l
```

### Automated Testing

```bash
# Generate and test random inputs (10 numbers in range 0-9999)
shuf -i 0-9999 -n 10 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)

# Test with 100 numbers
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)

# Test with 500 numbers
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker $(cat args.txt)

# Count operations for performance testing
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | wc -l
```

### Performance Benchmarks

| Disorder Level | Input Size | Algorithm Used | Avg Operations | Status |
|----------------|------------|----------------|----------------|--------|
| Low (< 0.2) | 100 | Selection | Too much | ✓ |
| Medium (0.2-0.5) | 100 | Chunk | ~1000 | ✓ |
| High (≥ 0.5) | 100 | Radix | =1084 | ✓ |
| High (≥ 0.5) | 500 | Radix | =6784 | ✓ |

**Note:** Actual operation counts vary based on specific input distribution and disorder coefficient.

---

**Project Status:** [Completed]  
**Grade:** [125/100]  
**Date:** [01/26]