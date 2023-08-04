# Welcome to Algorithm training room

Welcome. This is *Room of Spirit and Time*. In this place, you can train yourself for problem solving efficiently. we have automated for some tiresome and trivial tasks you would face during solving algorithm problems. (ex. making main func, including libraries, compiling and testing... etc.).
this repository would help if you are working out with cpp(or java) and vim(or neovim) editor.

## Step 1. Setting (Linux and Macos)
run below codes in your terminal console.
```
git clone https://github.com/monkeyKing001/Algorithm_exercise.git
cd Algorithm_exercise
source setting.sh
```
* `setting.sh` will 
1) Export and source alias `gogo`.
2) Download cpp, java, Makefile templates.
3) edit `autocmd` in .vimrc file

## Step 2. Running - 1
You can run the training program with a simple commad line in terminal `gogo`. 
with this command in any directory you are working in, you can move to this Algorithm_exercise directory and start the training program.
right after you run the command, you will see the program's intsructions.

## Step 2. Running - 2
Input your user name and your project name as the directions require. if you are a new user, it will make a new directory for you.
After following all of the directions, the program will make proper directory, template cpp, java, Makefile file within it and open the problem url.
Enjoy your problem set.

#### Macos
---
no ploblem

#### Linux
---
For Linux user, to use `open` command(in `start_problem.sh`) you need to install xdg-utils.
you can intall with
```
sudo apt-get install xdg-utils
```
If you are using Linux through WSL2, you have to run below code to open the browser. Below code makes openig browser to be executed in the Windows OS.

```
export BROWSER="powershell.exe /C start"
```
If you want to maintain this configuration continuously, copy and paste `export BROWSER="powershell.exe /C start"` in ~/.bashrc file and run `source ~/.bashrc`

## Step 3. Run and Test
#### Make rules
---
Once you start a problem, Makefile will be created in your problem directory.
Makefile has rules for compiling, running, testing, removeing bin files.
You can compile and test your code with just one line.
Belows are make rule examples

#### For C++ warriors
---
1. `make` : make the bin file `a.out` with <problem>.cpp
2. `make run` : run bin file `./a.out`
3. `make test t=<test_num>` : run bin file with test txt input file.
Just prepare the test txt file in `./test` directory before run the test.
this is example how you can test your code:
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
this is example how you can test your code:
```
make javatest t=1
```
this make command means you are going to compile your solution java source code and test with 1.txt.
