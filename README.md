# CLI Code Review Agent – CS180 Final Project

A simple command-line static analysis tool that detects common code quality issues in C++ source files. Designed to support code maintainability, readability, and basic software engineering principles.

## Features

This tool analyzes a `.cpp` file and reports:

- Long Functions – Flags any function that exceeds 20 lines
- Deep Nesting – Flags when nesting level exceeds 3 (e.g., too many nested if/for/while blocks)
- Magic Numbers – Detects numeric literals used directly instead of named constants
- Unclear Variable Names – Flags generic variable names like `x`, `tmp`, or `val`
- Missing Documentation Comments – Flags functions that are not preceded by a descriptive comment

## How to Build and Run

### 1. Clone the Repository


```bash
git clone https://github.com/Hishaamx2/CLI-Code-Review-Agent.git
cd cli-code-review-agent
```
## 2. Build the Project
```bash
g++ src/*.cpp src/detectors/*.cpp -o review_agent
```

## 3. Run the Analyzer in Cmd
```bash
./review_agent sample_code/example.cpp
```

## Sample Output
```bash
[Line 3] Function exceeds 20 lines (23 lines) | Severity: Moderate
[Line 7] Magic number detected (e.g., numeric literal without explanation) | Severity: Low
[Line 12] Unclear variable name detected: 'tmp' | Severity: Moderate
[Line 20] Function missing documentation comment | Severity: Moderate
```
## Output Format
```bash
[Line <line_number>] <Issue Description> | Severity: <Low/Moderate/High>
```

## CLI Usage and Parameters (API Documentation)

### Command Format
```bash
./review_agent <path_to_cpp_file>
```

### Parameters
```bash
| Name                 | Type     | Required | Description                            |
| -------------------- | -------- | -------- | -------------------------------------- |
| `<path_to_cpp_file>` | `string` | Yes      | Path to the C++ source file to analyze |
```

### Exit Codes
```bash
| Code | Meaning                             |
|------|-------------------------------------|
| 0    | Analysis completed successfully     |
| 1    | Missing file argument               |
```
## Project Structure
```bash
├── .vscode/                  # VSCode settings (optional)
├── sample_code/              # Example test files
│   └── example.cpp
├── src/                      # Source code for the analyzer
│   ├── main.cpp              # CLI entry point
│   ├── FileParser.cpp/.h     # Parses the C++ source files
│   ├── Issue.h               # Structure for code quality issues
│   ├── ReportGenerator.cpp/.h # Formats and outputs the results
│   ├── StaticAnalyzer.cpp/.h # Central coordination of detectors
│   └── detectors/            # All static analysis detectors
│       ├── BadNameDetector.cpp/.h
│       ├── DeepNestingDetector.cpp/.h
│       ├── LongFunctionDetector.cpp/.h
│       ├── MagicNumberDetector.cpp/.h
│       ├── MissingCommentDetector.cpp/.h
├── test/                     # (Optional) Unit or test code
├── review_agent              # Compiled binary after build
├── .gitignore
└── README.md
```

## Detector Descriptions
```bash
Detector	            Purpose	Example Suggestion
LongFunctionDetector	Flags functions over 20 lines	Break large functions into helpers
DeepNestingDetector	    Flags nesting deeper than 3 levels	Refactor logic to reduce complexity
MagicNumberDetector	    Flags hardcoded numeric values	Replace with named constants
BadNameDetector	        Flags generic variable names	Use descriptive, meaningful names
MissingCommentDetector	Flags functions lacking header comments	Add a one-line summary above functions
```
## Author

Hishaam Abdul-Muhaimin
CS180 – Summer 2025 Final Project