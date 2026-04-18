# Maze Game (C)

A simple terminal-based maze game written in C where the player navigates through a maze, collects points, and races against a 60-second timer.

##  Overview

This project loads a maze from a text file and allows the player to move through it using arrow keys. The player (represented by `A`) collects randomly placed point values while avoiding walls (`*`). Each collected point increases the score, and a new point is spawned elsewhere in the maze.

The game ends after 60 seconds.

---

## Features

* Random starting position each run
* Real-time movement using arrow keys
* Random point generation (values 1–9)
* Score tracking system
* 60-second countdown timer
* Maze loaded from external file (`ant_maze.txt`)
* Console-based rendering

---

## File Structure

```
.
├── main.c          # Main game logic
├── ant_maze.txt    # Maze layout file
└── README.md       # Project documentation
```

---

### Maze Representation

* The maze is stored as a 2D character array:

  ```c
  char Maze[MAXR][MAXC];
  ```
* `*` → Wall
* `' '` → Empty space
* `A` → Player
* `1–9` → Collectible points

---

### Core Functions

#### `print_maze()`

Prints the current state of the maze to the console.

#### `randomlocation(int *x, int *y)`

Generates a valid random position in the maze (must be an empty space).

#### `point_value(int *val)`

Generates a random point value between 1 and 9.

---

### Game Loop

* Player input is captured using `_getch()`
* Arrow keys control movement:

  * Up: `72`
  * Down: `80`
  * Right: `77`
  * Left: `75`
* Movement is only allowed if:

  * The target cell is not a wall (`*`)
  * The move stays within bounds

---

### Scoring System

* When the player moves onto a numbered tile:

  * The value is added to the total score
  * A new point spawns at a random location

---

### Timer

* Starts after the first key press
* Game ends after **60 seconds**:

  ```
  TIME UP!!!
  ```

---

##  How to Run

### Requirements

* C compiler (GCC recommended)
* Windows environment (uses `conio.h` for `_getch()`)

### Compile

```bash
gcc main.c -o maze
```

### Run

```bash
./maze
```

---

##  Notes / Limitations

* Uses `conio.h`, so it is **Windows-specific**
* Maze size is fixed using macros:

  ```c
  #define MAXR 11
  #define MAXC 10
  ```
* Random generation may retry until a valid space is found

---

## Possible Improvements

* Cross-platform input handling (replace `conio.h`)
* Dynamic maze sizing
* Better UI (colors, smoother rendering)
* Add win/lose conditions instead of just a timer
* Prevent potential out-of-bounds access
* Store high scores

---

## Author

**Ameem Khan**
Electrical Engineering Student @ Stony Brook University
