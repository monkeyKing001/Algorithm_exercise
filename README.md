# Welcome to Algorithm training room

Welcome. This is *Room of Spirit and Time*. In this place, you can train yourself for problem solving efficiently. we have automated for the tiresome and trivial tasks you would have faced when you are solving algorithm problems. (ex. maiking main func, including libraries ..., compiling and testing).
this repository would help if you are solving problems with cpp and vim(or neovim) editor.
## Step 1. Setting (Linux and Macos)

run below codes in your terminal console.

```
git clone https://github.com/monkeyKing001/Algorithm_exercise.git
cd Algorithm_exercise
source setting.sh
```

## Step 2. Running - 1
You can run the training program with a simple commad line `gogo`. 
It starts the training program wherever you are working in.


## Step 2. Running - 2
Input your user name and your project name as the directions require.
After following all of the directions, the program will make proper directory and template cpp file within it and open the problem url. 
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

## Step 3. Ran and Test
#### make rules
---
Once you start a problem, Makefile will be created in your problem directory.
You can compile and test your code with just one line.
Belows are make rule examples
1. `make` : make the bin file `a.out` with <problem>.cpp
2. `make run` : run bin file `./a.out`
3. `make test t=<test_num>` : run bin file with test txt input file.
Just prepare the test txt file in `./test` directory before run the test.
this is example how you can test your code:
```
make test t=1
```
this make command means you are going to compile your solution source code and test with 1.txt.
