# Library Book Management System (C Language)

A simple and efficient **Book Management System written in C**.  
This program allows you to **add, view, and search books** using a clean console interface.

---

##  Features
- Add new books (ID, Title, Author)
- View all saved books
- Search book by ID
- Cross-platform clear screen (Windows + Linux)
- Uses simple **file handling** (`books.txt`)
- Smooth offline compilation in CodeBlocks / Dev-C++

---

##  Important Notes
- This program **may not run properly on online compilers**  
  because online compilers block:
  - `system("cls")` / `system("clear")`
  - local file handling  
- It runs perfectly on **offline compilers** like:
  - CodeBlocks  
  - Dev-C++  
  - VS Code (with GCC)  
  - Turbo C alternatives  

---

##  File Structure
```
library.c
books.txt   (auto generated)
README.md
.github/workflows/c_build.yml
```

---

##  GitHub Actions Included
This repository includes an automated YAML workflow that:
- Compiles the C program using GCC  
- Runs a basic execution test  

---

##  Developer
**Developed by: _Md Nazmul Hasan_**

