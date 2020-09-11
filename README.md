# LeetCode Solutions

[**LeetCode Journey**](https://george16886.gitlab.io/categories/LeetCode/) @[**george16886's blog**](https://george16886.gitlab.io)

* [x] *Programming language*: **C++**
* [x] *Environment*: **Ubuntu 16.04**, **Win10 x64**
* [x] *Tool*: **Visual Studio Code** 

---

## Coding with Visual Studio Code @Win10 x64

### Using GCC with MinGW

1. Install [Visual Studio Code](https://code.visualstudio.com/download).
2. Install the [C/C++ extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).
   - In Visual Studio Code, search for 'c++' in the Extensions view (Ctrl+Shift+X).
3. Install [Mingw-w64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download).
   - For Architecture select **x86_64**
4. Add the path to your Mingw-w64 bin folder to the Windows PATH environment variable.
   - 本機右鍵 -> 內容 -> 進階 -> 環境變數
   - 選 Path -> 編輯 -> 新增（若安裝 Mingw-w64 時沒有更新路徑直接複製下面一行即可）
   - *C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin*
5. In Visual Studio Code, press **F5** to run
   - C++ (GDB/LLDB)
   - g++.exe - 建置及偵錯使用中的檔案
