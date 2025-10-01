# Parallel File Encryptor

Parallel File Encryptor is a C++ application designed to efficiently encrypt and decrypt files by processing multiple cryptographic tasks in parallel. It leverages queue-based task management and modular code architecture for robust and scalable file operations.

## Features

- **Parallel Task Execution:** Uses a queue system for managing multiple encryption/decryption tasks.
- **Simple Encryption Algorithm:** Encrypts and decrypts files using a key stored in an environment file.
- **Modular Design:** Organizes code into clear modules for process management, file handling, and cryptographic operations.
- **Cross-Platform (Windows):** Designed to run on Windows systems.

## How it Works

1. **Task Submission:** Files to be encrypted or decrypted are wrapped as `Task` objects and submitted to a queue.
2. **Process Management:** The `ProcessManagement` class executes tasks from the queue, calling the main cryptographic routine for each.
3. **Cryptography:** The encryption and decryption use a simple byte-wise transformation keyed from a `.env` file.
4. **File Handling:** The `IO` and `ReadEnv` modules manage secure file I/O and retrieval of cryptographic keys.

## File Structure

```
Parallel-File-Encryptor/
├── main.cpp
├── src/
│   └── app/
│       ├── encryptDecrypt/
│       │   ├── Cryption.cpp
│       │   ├── Cryption.hpp
│       ├── processes/
│       │   ├── ProcessManagement.cpp
│       │   ├── ProcessManagement.hpp
│       │   ├── Task.cpp
│       │   ├── Task.hpp
│       ├── fileHandling/
│       │   ├── IO.cpp
│       │   ├── IO.hpp
│       │   ├── ReadEnv.cpp
```

## Getting Started

### Prerequisites

- C++17 compatible compiler (e.g., g++, MSVC)
- Windows OS (uses Windows headers)
- `.env` file in project root containing the encryption key (integer)

### Build Instructions

```bash
# Example using g++ (adapt as needed for your environment)
g++ -std=c++17 -o encryptor main.cpp \
    src/app/encryptDecrypt/Cryption.cpp \
    src/app/processes/ProcessManagement.cpp \
    src/app/fileHandling/IO.cpp \
    src/app/fileHandling/ReadEnv.cpp
```

### Usage

```bash
# Encrypt or decrypt a file
./encryptor <task_data>
# Example task_data: "test.txt,ENCRYPT" or "test.txt,DECRYPT"
```

- The program expects a single argument specifying the file path and action.
- The file is processed in-place (encrypted or decrypted).
- The cryptographic key is read from `.env` in the current directory.

## Example

Suppose your `.env` file contains:
```
123
```

To encrypt `example.txt`:
```bash
./encryptor "example.txt,ENCRYPT"
```

To decrypt:
```bash
./encryptor "example.txt,DECRYPT"
```

## Implementation Highlights

- **Cryption.cpp:** Handles the byte-wise encryption and decryption logic.
- **ProcessManagement:** Manages a queue of tasks for parallel execution.
- **Task:** Represents an individual file operation (encrypt or decrypt).
- **IO & ReadEnv:** Securely manage file streams and environment-based key retrieval.

## Limitations & Notes

- The encryption algorithm is basic and intended for educational/demo purposes. Do not use for production-grade security.
- Files are processed in-place; always back up important data before running.
- Currently tailored to Windows; modifications may be needed for other platforms.

## Contributing

Contributions and suggestions are welcome! Please open an issue or submit a pull request.

## Author

[shabinfrancis](https://github.com/shabinfrancis)
