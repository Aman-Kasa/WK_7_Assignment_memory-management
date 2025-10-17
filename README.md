![Dynamic memory management](https://imgs.search.brave.com/QFedK6ro5OO-kMS_L1wptqi4G7-HYwSsWxEt-p65LCY/rs:fit:500:0:1:0/g:ce/aHR0cHM6Ly9kb3Ru/ZXR0cmlja3NjbG91/ZC5ibG9iLmNvcmUu/d2luZG93cy5uZXQv/YXJ0aWNsZS81NjIw/MjUwODAyMTM0NzQ5/LndlYnA)


# Dynamic Email Management System

A C program demonstrating advanced dynamic memory allocation techniques for managing student email addresses with efficient memory optimization.

## 🎯 Project Overview

This system manages a cohort of student email addresses using dynamic memory allocation, showcasing proper memory management practices including allocation, reallocation, and cleanup to prevent memory leaks.

## ✨ Features

- **Dynamic Memory Allocation**: Uses `malloc()` for flexible memory management
- **Memory Optimization**: Efficiently shrinks array from 10 to 6 students using `realloc()`
- **Safe Input Handling**: Robust email input with bounds checking
- **Memory Leak Prevention**: Complete cleanup of all allocated memory
- **Error Handling**: Comprehensive error checking for all memory operations

## 🚀 Quick Start

### Compilation
```bash
gcc -Wall -Wextra -std=c99 -o dynamic_memory_management dynamic_memory_management.c
```

### Execution
```bash
./dynamic_memory_management
```

### Sample Usage
```
Enter email 1: student1@university.edu
Enter email 2: student2@university.edu
...
Enter email 10: student10@university.edu

Email addresses:
1. student1@university.edu
2. student2@university.edu
...
10. student10@university.edu

After shrinking to 6 students:
1. student1@university.edu
2. student2@university.edu
...
6. student6@university.edu
```

## 🏗️ Technical Implementation

### Memory Management Strategy
- **Initial Allocation**: 10 email slots using `malloc()`
- **Individual Strings**: Each email allocated separately (50 chars max)
- **Memory Shrinking**: Safe `realloc()` to reduce to 6 slots
- **Complete Cleanup**: All memory properly freed

### Key Functions
| Function | Purpose |
|----------|---------|
| `read_emails()` | Safe email input with validation |
| `display_emails()` | Formatted email list output |
| `free_emails()` | Complete memory deallocation |

## 📋 Requirements Met

- ✅ Dynamic allocation for 10 student emails
- ✅ Maximum 49 characters per email (+1 for null terminator)
- ✅ User input validation and storage
- ✅ Function-based architecture
- ✅ Memory shrinking to 6 students using `realloc()`
- ✅ Zero memory leaks with proper cleanup

## 🔧 Technical Specifications

- **Language**: C (C99 standard)
- **Memory Functions**: `malloc()`, `realloc()`, `free()`
- **Input Method**: `fgets()` for safe string input
- **Error Handling**: Comprehensive allocation failure checks

## 📊 Memory Usage

```
Initial State:  10 emails × 50 bytes = 500 bytes + pointer array
Optimized:      6 emails × 50 bytes = 300 bytes + pointer array
Memory Saved:   40% reduction after optimization
```

## 🎓 Learning Outcomes

This project demonstrates mastery of:
- Dynamic memory allocation and deallocation
- Pointer manipulation and array of pointers
- Memory optimization techniques
- Safe programming practices in C
- Error handling and resource management

## 👨‍💻 Author

**AMAN-KASA**  
GitHub: [https://github.com/Aman-Kasa](https://github.com/Aman-Kasa)

## 🏫 Academic Information

**Course**: Week 7 Assignment - Memory Management  
**Coach**: Thadee  
**Institution**: ALU (African Leadership University)

## 📄 License

This project is part of academic coursework and is intended for educational purposes.

---

*Built with precision, optimized for performance, designed for learning.*
