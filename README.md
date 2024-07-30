# Practice CPP

Welcome to the Practice CPP repository!

## Project Overview

The **Practice CPP** project is designed to help you practice and improve your C++ programming skills using C++20. The project includes a variety of examples and exercises to build a strong foundation in modern C++.

## Folder Structure

- **TheBasics**: Contains basic C++ programming examples and exercises using C++20.
- **DesignPattern**: Contains seven structural design patterns from the original design patterns book—adapter, bridge, composite, decorator, facade, flyweight, and proxy—and shows you how to implement each one in modern C++..

## Build Instructions

To build the project, you can use Visual Studio Code with MinGW and the provided `settings.json` configuration. Follow these steps:

1. **Install CMake**: Ensure that CMake is installed on your system.

2. **Install MinGW**: Install MinGW if it's not already installed.

3. **Check CMake Version**: Verify that the CMake version installed on your system is compatible with the project's `CMakeLists.txt`. If necessary, update the CMake configuration to match your version.

4. **Open in Visual Studio Code**:
   - Open the project root directory in Visual Studio Code.
   - Ensure that the `.vscode` folder and `settings.json` are correctly configured to use MinGW Makefile.

5. **Build the Project**:
   - Open the Command Palette (Ctrl+Shift+P) and select "CMake: Build".
   - Alternatively, you can use the built-in terminal to navigate to the build directory and run:
     ```bash
     mkdir -p build
     cd build
     cmake ..
     mingw32-make
     ```

6. **Execute the File**:
   - Once the build is complete, you can run the executable file directly from the terminal or use the VS Code debug features.

## Future Plans

The project will be updated with additional content for self-improvement and more advanced topics in the future. Stay tuned for updates!

## Contributing

If you'd like to contribute to the project, please feel free to submit a pull request or open an issue.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
