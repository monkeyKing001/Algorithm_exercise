# Welcome to Algorithm training room

![Room of Spirit and Time](https://www.google.com/url?sa=i&url=https%3A%2F%2Fnamu.wiki%2Fw%2F%25EC%25A0%2595%25EC%258B%25A0%25EA%25B3%25BC%2520%25EC%258B%259C%25EA%25B0%2584%25EC%259D%2598%2520%25EB%25B0%25A9&psig=AOvVaw3yZKeDhF9STcVaWCGdlBtL&ust=1734007460560000&source=images&cd=vfe&opi=89978449&ved=0CBQQjRxqFwoTCIDLgqffn4oDFQAAAAAdAAAAABAE)

Welcome to the Room of Spirit and Time! In this place, you can efficiently train yourself in problem-solving. We have automated many tiresome and trivial tasks you might face while solving algorithm problems, such as creating a main function, including libraries, compiling, testing, etc. This repository is especially helpful if you work with C++ (or Java) and use Vim (or Neovim) as your editor.

## Dependencies
#### Macos
---

```
brew install wget
```

#### Linux
---
```
sudo apt-get install -y wget, xdg-utils
```

#### Linux on WSL
---
```
sudo apt-get install -y wget, xdg-utils
export BROWSER="powershell.exe /C start"
```

## Step 1. Setting (Linux and Macos)
Run the following commands in your terminal:
```bash
git clone https://github.com/monkeyKing001/Algorithm_exercise.git
cd Algorithm_exercise
source setting.sh
```
* `setting.sh` will 
1) Export and source alias `gogo`.
2) Download cpp, java, Makefile README.md templates.
3) edit `autocmd` in .vimrc file

## Step 2. Running - 1
```bash
$> gogo
```
Run the training program by typing gogo in any directory you’re working in. This command will move you to the Algorithm_exercise directory and start the training program. After running the command, you will see instructions in the terminal.

## Step 2. Running - 2
When prompted, enter your username and project name as directed. If you’re a new user, the program will create a new directory for you. After completing the prompts, the program will:

Create the appropriate directory structure.
Generate template files for C++, Java, and Makefiles.
Open the problem's URL in your browser.
Enjoy solving your algorithm problems!

## Step 3. Run and Test
#### Makefile rules
---

Once you start a problem, a Makefile will be created in your problem directory. The Makefile includes rules for compiling, running, testing, and cleaning up binary files. You can execute these tasks with simple commands.

#### For C++ warriors
---
1. `make` : Compile the source file (e.g., <problem>.cpp) and create the binary a.out.
2. `make run` : Run the compiled binary (./a.out).
3. `make test t=<test_num>` : Run the binary with a test input file.

Place the test input file (e.g., 1.txt) in the ./test directory before running this command.

Example:
```
make test t=1
```
this make command means you are going to compile your solution source code and test with 1.txt.

#### For Java warriors
---
1. `make java` : make the bin file `Main.class`
2. `make javarun` : run bin file `java Main`
3. `make javatest t=<test_num>` : run bin file with test txt input file.

Just prepare the test txt file in `./test` directory before run the test.

Example:
```
make javatest t=1
```
this make command means you are going to compile your solution java source code and test with 1.txt.
