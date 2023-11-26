[![Hosted with GH Pages](https://img.shields.io/badge/Hosted_with-GitHub_Pages-blue?logo=github&logoColor=white)](https://pages.github.com/ "Go to GitHub Pages homepage")
[![OS - Linux](https://img.shields.io/badge/OS-Linux-blue?logo=linux&logoColor=white)](https://www.linux.org/ "Go to Linux homepage")
[![OS - Windows](https://img.shields.io/badge/OS-Windows-blue?logo=windows&logoColor=white)](https://www.microsoft.com/ "Go to Microsoft homepage")
<a href="#license"><img src="https://img.shields.io/badge/License-MIT-blue" alt="License"></a>

## Modern vs Old C++ Functions Performance Comparison

This program compares the performance of modern, old C++ and C functions for a specific use case. The program measures the time taken by each function to perform the same task, and outputs the results to the console.

## Getting Started

To use this program, you will need to have a C++ compiler installed on your system. You can download and install a C++ compiler such as GCC or Clang from the official websites.

Once you have a C++ compiler installed, you can download the source code for this program from the GitHub repository. You can then compile the source code using your C++ compiler.

## Usage

To use this program, simply run the files with extension .cpp. The results will be printed out to the console.

```
g++ filename.cpp

// In Linux systems:
./a.out
```

If you would like to contribute to this program, you can fork the GitHub repository and submit a pull request with your changes.

## Environment

- Environment: Ubuntu 22.04.3 LTS
- Compiler(s):
  -- gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
- CPU: AMD Ryzen 3 3200U

## Results Analyzing

### Count Up Loop vs Count Down Loop Performance comparison

To see the performance difference between count up to SIZE and count down to zero loops
lease run the compiler without any optimization flags! -O0
`gcc -O0 gcc_loop_countUp_vs_countDown.c -o gcc_loop_countUp_vs_countDown`
Otherwise, you will see the same performance for both loops or even count up loop will be faster.

Due to my tests:
If there is no compiler optimization works, count down loop is faster than count up loop.
I have experienced at most `8%` performance difference in gcc.
I have experienced at most `5%` performance difference in g++.

## License

This program is licensed under the MIT License. See the LICENSE file for more information.

## Acknowledgments

This program was inspired by the need to compare the performance of modern and old C++ functions for a specific use case.
