# Data Structures & Graph Algorithms Suite

An interactive, terminal-based data structures and algorithms suite written in **Modern C++**. Designed for computational demonstration and software engineering review, the application provides custom implementations of fundamental containers, self-balancing search trees, and complex graph solvers — all operating in-memory with zero external library dependencies.

---

## Table of Contents

- [Overview](#overview)
- [Architecture](#architecture)
- [Data Structures](#data-structures)
- [Core Modules](#core-modules)
  - [Singly Linked List](#singly-linked-list)
  - [FIFO Queue](#fifo-queue)
  - [LIFO Stack](#lifo-stack)
  - [Hash Table](#hash-table)
  - [Binary Search Tree](#binary-search-tree)
  - [AVL Tree](#avl-tree)
  - [Red-Black Tree](#red-black-tree)
  - [Graph Solver](#graph-solver)
- [Mathematical Expression Engine](#mathematical-expression-engine)
- [Graph Algorithms Engine](#graph-algorithms-engine)
- [Memory Management & Safety Strategy](#memory-management--safety-strategy)
- [Input Validation](#input-validation)
- [Project Structure](#project-structure)
- [Build & Run](#build--run)

---

## Overview

The system operates as an interactive console application driven by a nested command-line menu. On execution, it runs a central event loop routing commands to specialized modules. Every data structure, node modification, tree rebalancing, and graph traversal is handled through custom algorithms, demonstrating pointer mechanics and low-level memory efficiency.

**Key capabilities:**

| Feature | Description |
|---|---|
| Singly Linked List | Sequential nodes with head/tail editing, recursive printing, and set theory logic |
| LIFO & FIFO Containers | Pointer-based Stack and Queue structures with element/max tracking and merges |
| Shunting-Yard Parser | Mathematical infix-to-postfix conversion using operator precedence stacks |
| Collision-Chained Hash Table | Key-value string hashing with buckets resolved through manual chaining |
| Self-Balancing Trees | Logarithmic operations via AVL (height-balanced) and Red-Black (color-balanced) trees |
| Graph Solvers | Adjacency lists resolving Shortest Paths (Dijkstra) and Minimum Spanning Trees (Prim/Kruskal) |
| Console Stream Integrity | Heavy character inspection preventing infinite menu loops and type errors |

---

## Architecture

The application follows a modular C++ architecture with a strict separation between declarations and execution logic:

```
Main.cpp (Entry point & top-level router)
 │
 ├── Config.h            → Shared structures, constants, and validation prototypes
 ├── Menus.cpp/h         → Console display menus and input collectors
 ├── Validation.cpp      → Input stream verification utilities
 │
 ├── LinkedList.cpp/h    → Singly linked list operations
 ├── Stacks.cpp/h        → LIFO stack container operations
 ├── Queues.cpp/h        → FIFO queue container operations
 ├── HashTable.cpp/h     → Hashing mechanics and collision chains
 ├── InfixToPostfix.cpp/h→ Mathematical stack parser
 ├── Trees.cpp/h         → Standard Binary Search Tree (BST)
 ├── AVLTrees.cpp/h      → AVL self-balancing tree rotations
 ├── RedBlackTrees.cpp/h → Red-Black self-balancing tree color adjustments
 └── Graphs.cpp/h        → Graph adjacency list representation and path/spanning tree solvers
```

All data structures are isolated inside dedicated classes, communicating with main loops via reference variables or standard input/output streams.

---

## Data Structures

To guarantee maximum control over memory layout and algorithmic complexities, the codebase bypasses the standard container libraries (STL) in favor of custom-declared structures:

```cpp
// Config.h: Generic list node utilized by Stack, Queue, and LinkedList
class Node {
    public:
        int data;          // Integer payload
        Node* nextPtr;     // Pointer to the next node in the chain
};

// InfixToPostfix.h: Character node for mathematical parse stacks
class CharNode {
    public:
        char data;         // Character payload
        CharNode *nextPtr; // Pointer to the next character node
};

// HashTable.h: Directory bucket representing name/key mappings
class HashNode {
    public:
        char name[50];     // String key
        int number;        // Associated integer value
        HashNode* next;    // Collision chain next pointer
};

// AVLTrees.h: Height-balanced tree node
class AVLNode {
    public:
        int data;           // Integer key
        AVLNode *left;      // Left subtree pointer
        AVLNode *right;     // Right subtree pointer
        int height;         // Current height of the node
};

// RedBlackTrees.h: Color-balanced tree node with parent tracking
enum Color { RED, BLACK };
class RBTNode {
    public:
        int data;          // Integer key
        Color color;       // Structural node color (RED or BLACK)
        RBTNode *left;     // Left child pointer
        RBTNode *right;    // Right child pointer
        RBTNode *parent;   // Parent node pointer
};

// Graphs.h: Adjacency list edge connection node
class EdgeNode {
    public:
        int destination;   // Destination vertex index
        int weight;        // Edge weight value
        EdgeNode* nextPtr; // Next edge connected to the vertex
};
```

---

## Core Modules

### Singly Linked List

Provides 16 operations via the singly linked list menu:

- **Insertion**: Supports inserting elements at the front/end, or inserting before/after a node by reference value or positional index.
- **Deletions**: Supports deleting the first/last nodes, or deleting by reference or index.
- **Set Arithmetic**: Performs Union, Intersection, and Difference between two list instances.
- **List Swapping**: Moves the entire contents of one list to another container.

### FIFO Queue

Handles first-in, first-out sequencing:

- **Basic Operations**: Direct enqueue/dequeue of integers and front/rear lookups.
- **Analysis**: Counts the number of active queue elements and identifies the largest number present in the queue.
- **Consolidation**: Merges two queues or moves contents between queues.

### LIFO Stack

Handles last-in, first-out ordering:

- **Basic Operations**: Push and pop operations and top element peeking.
- **Analysis**: Returns the total node count and retrieves the maximum value stored in the stack.
- **Parsing Integration**: Connects with the Shunting-Yard engine to evaluate and convert string-based mathematical expressions.

### Hash Table

Implements a key-value directory mapping strings (names) to integers:

- **Hashing Scheme**: Maps keys using a custom polynomial roll string hash.
- **Collision Resolution**: Resolves collisions using separate chaining (linked list buckets).
- **Lookup**: Employs manual string comparison routines to retrieve values.

### Binary Search Tree

Hierarchical search tree with no balancing constraints:

- **Visual Rendering**: Sideways textual tree rendering and graphical terminal outputs.
- **Traversals**: Implements PreOrder, InOrder, PostOrder, and Level-Order (BFS) traversals.
- **Invariants**: Validates whether the tree matches Complete Binary Tree or Full Binary Tree criteria.
- **Deletions**: Allows node removal via Predecessor or Successor replacement strategies.

### AVL Tree

Self-balancing binary search tree based on strict height boundaries:

- **Balancing Invariant**: Assures that the height difference of any node's children is at most 1.
- **Rotations**: Auto-balances during insertion/deletion using Single and Double rotations.
- **Operations**: Interactive insertion, deletion, lookup, and structure visualization.

### Red-Black Tree

Self-balancing search tree using color properties:

- **Balancing Invariant**: Enforces color distribution, root/NIL node blackness, and black-height symmetry.
- **Operations**: Inserts and deletes nodes, fixing violations through tree transplants, rotations, and node recoloring.
- **Verification**: Includes an internal checker that validates all Red-Black tree properties.

### Graph Solver

Multi-node network solver using adjacency lists:

- **Topology Modification**: Supports vertex addition/deletion, edge creation/deletion (weighted, directed, or undirected), and adjacency checks.
- **Pathfinding & Spanning Trees**: Houses MST and Shortest Path engines.
- **Traversals**: Implements Depth-First Search (DFS) and Breadth-First Search (BFS).

---

## Mathematical Expression Engine

The system features an algebraic conversion parser executing **Dijkstra's Shunting-Yard Algorithm**:

### Operator Precedence Rules

The engine maps operators to numerical precedence levels during parsing:

| Operator | Precedence | Description | Associativity |
|---|---|---|---|
| `^` | 2 | Exponentiation | Right-to-Left |
| `*`, `/` | 1 | Multiplication / Division | Left-to-Right |
| `+`, `-` | 0 | Addition / Subtraction | Left-to-Right |

### Parsing Protocol

1. The expression is parsed character-by-character.
2. Alphanumeric operands are immediately appended to the output string.
3. Operators are pushed onto a character stack (`CharStack`) after popping off all operators with greater or equal precedence.
4. Left parentheses are pushed onto the stack; right parentheses trigger popping operators to the output until a matching left parenthesis is cleared.

---

## Graph Algorithms Engine

The graph module includes manual, array-based implementations of classic graph algorithms:

### Kruskal's MST Algorithm
- Builds a Minimum Spanning Tree for weighted undirected graphs.
- Sorts graph edges in ascending order of weight.
- Iteratively adds edges, checking that they do not form a cycle. Cycle validation is performed manually.

### Prim's MST Algorithm
- Builds a Minimum Spanning Tree from a starting vertex.
- Greedily selects the lowest-weight edge that connects a vertex in the MST to a vertex outside the MST.

### Dijkstra's Shortest Path Algorithm
- Calculates shortest distances between a source and a destination vertex.
- Employs tentative distances, relaxing edge weights dynamically on adjacent vertices.

---

## Memory Management & Safety Strategy

Because the application avoids standard containers, memory safety is enforced manually:

- **Deep Deallocations**: Destructors for Linked Lists, Stacks, Queues, Hash Tables, and Graphs recursively traverse their nodes, releasing memory with the `delete` operator to prevent leaks.
- **Tree Destruction**: Binary Trees, AVL Trees, and Red-Black Trees implement post-order traversal destructors to free nodes bottom-up.
- **NIL Sentinel Strategy**: The Red-Black Tree uses a dedicated, shared `NIL` sentinel node (configured as `BLACK`) to represent all leaf nodes, ensuring boundary checks do not trigger dereferencing errors.
- **Dynamic Array Resizing**: Adjacency lists and vertex arrays are allocated dynamically based on graph size requirements.

---

## Input Validation

The validation module ([`Validation.cpp`](file:///c:/Estudio/Cpp/Proyecto/Source%20Files/Validation.cpp)) shields the application against input-driven crashes:

| Function | Check Performed | Action on Failure |
|---|---|---|
| `validateMenuInput()` | Verifies menu option is integer in range `[1, Limit]` | Clears stream, flushes buffer, prints error, returns `false` |
| `validateInteger()` | Verifies integer input (no letters, spaces, decimals) | Clears stream, flushes buffer, prints error, returns `false` |

Every parser checks `std::cin.fail()` and queries trailing characters in the buffer using `getchar()`. This prevents trailing letters (e.g., `5abc`) or decimals (e.g., `4.5`) from corrupting subsequent reads.

---

## Project Structure

```
Proyecto/
├── Main Code/
│   └── Main.cpp                  # Entry point and menu routing loop
├── Headers/
│   ├── Config.h                  # Node structs, menu limit configurations
│   ├── Menus.h                   # Menu display declarations
│   ├── LinkedList.h              # Singly Linked List declarations
│   ├── Stacks.h                  # Stack structure declarations
│   ├── Queues.h                  # Queue structure declarations
│   ├── HashTable.h               # Hash Table declarations
│   ├── InfixToPostfix.h          # Shunting-yard parser declarations
│   ├── Trees.h                   # Binary Search Tree declarations
│   ├── AVLTrees.h                # AVL self-balancing tree declarations
│   ├── RedBlackTrees.h           # Red-Black self-balancing tree declarations
│   └── Graphs.h                  # Graph and graph solvers declarations
├── Source Files/
│   ├── Validation.cpp            # Input stream validations
│   ├── Menus.cpp                 # Display layouts and choices
│   ├── LinkedList.cpp            # Singly Linked List implementations
│   ├── Stacks.cpp                # Stack operations
│   ├── Queues.cpp                # Queue operations
│   ├── HashTable.cpp             # Hashing operations
│   ├── InfixToPostfix.cpp        # Shunting-yard implementations
│   ├── Trees.cpp                 # BST operations
│   ├── AVLTrees.cpp              # AVL balance and rotation operations
│   ├── RedBlackTrees.cpp         # Red-Black color and rotation operations
│   └── Graphs.cpp                # Graph and pathfinding implementations
└── README.md
```

---

## Build & Run

### Prerequisites

- A C++ compiler supporting the **ISO C++17** standard or later (e.g., GCC/MinGW, MSVC).

### Compilation

**Using GCC (MinGW on Windows / GCC on Linux or macOS):**

```bash
g++ -std=c++17 "Main Code/Main.cpp" "Source Files"/*.cpp -o DataStructuresApp
```

**Using MSVC (cl compiler from Developer Command Prompt):**

```cmd
cl /EHsc /std:c++17 "Main Code\Main.cpp" "Source Files\*.cpp" /Fe:DataStructuresApp.exe
```

### Execution

```bash
# Windows
DataStructuresApp.exe

# Linux / macOS
./DataStructuresApp
```

---

> **Note**: This project serves as a showcase of C++ systems programming, highlighting pointer-level memory mechanics, tree balancing algorithms, and graph traversal logic without reliance on external frameworks or the Standard Template Library.
