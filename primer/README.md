## Usage

touch two file in `/usr/bin/` for quickly compile and run code.

- build code
```bash
ahan@white:/study/primer$ cat /usr/bin/bprimer 

project_path=/study/primer
mkdir -p ${project_path}/build

filename=$1
build=$(echo $1 | sed 's=.cc==g')

g++ -o ../build/$build $filename
```

- run code
```bash
ahan@white:/study/primer$ cat /usr/bin/rprimer 
filename=$1
build=$(echo $1 | sed 's=.cc==g')

../build/$build
```

You need to enter the code directory of each chapter to execute the script.
```bash
# build code
bprimer exer1.12.cc
# run code
rprimer exer1.12.cc
```

## Dir

```
.
├── build           // Compiled binary directory
├── ch1             // Code directory for each chapter
├── ch2
├── chxxx
└── source-file     // Book source code directory
```
