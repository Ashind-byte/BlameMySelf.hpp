😅 **BlameMyself – Because Writing #includes is Just Too Much**

Ever sat down to write a C++ header and thought, “I wish someone else could just deal with all the #include nonsense?” Well, now you can! Meet BlameMyself – the ultimate tool for generating C++ header and source files with standard library includes, because obviously you are to blame for starting another C++ project in the first place.This is my mini hobby project so feel free to blame me :D.

This little utility lets you:

Load includes from a config file (because remembering whether it's <map> or <unordered_map> is a crime),

Ask you what includes you want (it listens better than your teammates),

And even generates both .hpp and .cpp files (you know, the ones you pretend you’ll finish later).

📦** What Does It Do?**

BlameMyself is a command-line tool that helps you quickly scaffold C++ header and source files with the necessary #include directives from a configuration file. You just tell it what you need (like vector, map, iostream, etc.), and it’ll generate a proper .hpp and optional .cpp file for you.

It’s like a templating engine, but with more sarcasm and less XML.

**🧪 Example**
Step 1: Create a config file
Include.conf with the following format(ignore the spaces in between lines) :

    vector=#include<vector>
    
    list=#include<list>
    
    map=#include<map>
    
    unordered_map=#include<unordered_map>
    
    iostream=#include<iostream>
    
    string=#include<string>
    
    set=#include<set>

**🏭Step 2: Build it**
    
    cd BlameMyself.hpp
    
    mkdir build
    
    cd build
    
    cmake ..
    
    make

This will compile the program and place the executable and Includes.conf inside the build/HeaderGen/ directory.

**Step 3: Run it 🏃‍♂️🏃‍♂️🏃‍♂️**

    change your directory to the HeaderGen folder

    ./HeaderGen <FileName> Includes.conf


⚠️ Platform Disclaimer (aka “It Works on My Machine™”)

This project was tested on Linux, where make, g++, and hopes-and-dreams usually work together in harmony.

As for Windows and macOS? Well...

🪟 Windows: It might build if you squint hard enough and CMake feels generous. You’ll probably need a C++17-compatible compiler like MSVC and might want to run it from a terminal like PowerShell or Git Bash so it doesn’t cry.

🍎 macOS: It should work if Xcode’s CLI tools are installed... but if it throws obscure errors, just know I, too, am confused.

If you get it working on either, congratulations — you're officially part of QA now! 🧪✨

Feel free to open a PR or issue titled: “Fix it, coward.”


