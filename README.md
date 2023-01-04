# Welcome to Algorithm training room

This git repository is for Algorithm trainee especially who are solving problems with vim(or nvim) editor and cpp languages.

## Step 1. Setting (no matters if you are using Linux or Mac os)

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
After following all of the directions, the program will make proper dirtory, template cpp file within it and open the problem url. 
Enjoy your problem set.



#### Macos
---
no ploblem
#### Linux
---
For Linux user, to use `open` command(in `start_problem.sh`) you will need to install xdg-utils
you can intall with 
```
sudo apt-get install xdg-utils
```
If you are using the linux through WSL2, you might run below code to open browser. below code makes openig browser to be executed in the Windows OS

```
export BROWSER="powershell.exe /C start"
```
if you want to maintain this configuration, copy and paste `export BROWSER="powershell.exe /C start"` in ~/.bashrc file and run `source ~/.bash`
editing PATH in `.bashrc (or .zshrc)` and source `.bashrc(or .zshrc)` are optional. 

### Step 3. Test
once you start a problem solving, Makefile will be created in your problem directory.
you can compile and test your code with just one line `make t=<testnumber>`
just prepare the test txt file in `./test` directory
this example is how you can test your code:
ex)
```
make t=1
```
this make command means you are going to compile your solution source code and test with 1.txt.
