# 📜 Get Next Line — Progressive micro-exercises to master **static variables**, **heap memory management**, and **string slicing**.

Progressive Learning & Implementation Log

This directory documents my step-by-step journey to understand, design, and implement `get_next_line` for the 42 School curriculum.

Instead of jumping straight to the final function, I built 

## 🧠 Core Mechanics & Mental Model

Reading a file descriptor line-by-line with an arbitrary `BUFFER_SIZE` requires managing state across function calls.

# 📜 Get Next Line — Learning & Trials

This folder contains my step-by-step development process, memory exercises, and architectural breakdowns for **`get_next_line`**.

---

## 🧠 Conceptual Mental Model

Reading a file line-by-line with a fixed `BUFFER_SIZE` requires a 3-step lifecycle:

1. **Read & Accumulate:** Read `BUFFER_SIZE` bytes into a temporary buffer and append it to a `static` variable (`leftovers`) until a newline (`\n`) or EOF (End of File) is reached.
2. **Extract Line:** Cut the substring from the start of `leftovers` up to and including the first `\n`.
3. **Clean Leftovers:** Retain only the remaining characters after the `\n` in the `static` variable for the next function call, freeing the old allocation.

---

## 🎨 Excalidraw Memory Diagram

![GNL Memory Architecture]

> *The diagram above illustrates how `leftovers` persists in memory across multiple function calls while `buffer` is created and freed per iteration.*

---

## 📁 Exercises & Trial Breakdown

| File | Description | Key Concept Learned |
| :--- | :--- | :--- |
| `01_find_newline.c` | Locate the index of `\n` in a string | Index math vs char pointers |
| `02_append_word.c` | String joining with static memory | `malloc`, `free`, avoiding leaks |
| `get_next_line_draft.c` | Full implementation with step comments | Uniting the full 3-step loop |

---

## ⚡ Edge Cases & Common Pitfalls Documented
* **Segmentation Fault on initial call:** Occurs if `ft_strchr` is executed on a `NULL` static pointer before initial assignment.
* **Buffer Overflow:** Forgetting to allocate `BUFFER_SIZE + 1` to accommodate the null terminator `\0`.
* **Memory Leak on Read Error:** Failing to `free(buffer)` and `free(leftovers)` when `read()` returns `-1`.


## 🎨 Visual Architecture & Memory Flow (Excalidraw Schematics)

### 1. Understanding File Descriptors & System Calls
### 2. GNL Step-by-Step Lifecycle
#### Phase 3: Cleanup & EOF (End of File)

![1.](<Screenshot from 2026-07-31 13-21-24.png>)
![2](<Screenshot from 2026-07-31 13-21-54.png>)
![3](<Screenshot from 2026-07-31 13-22-39.png>)
![4](<Screenshot from 2026-07-31 13-22-52.png>)
![5](<Screenshot from 2026-07-31 13-23-07.png>)
![6](</home/acamelo/Pictures/Screenshots/Screenshot from 2026-07-31 13-23-26.png>)
![7](<Screenshot from 2026-07-31 13-23-45.png>)
![8](<Screenshot from 2026-07-31 13-24-04.png>)
