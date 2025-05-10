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

mkdir build
cd build
cmake ..
cmake --build .

This will compile the program and place the executable and Includes.conf inside the build/HeaderGen/ directory.

**Step 3: Run it 🏃‍♂️🏃‍♂️🏃‍♂️**

./HeaderGen/HeaderGen <FileName> Includes.conf


