## Usage

touch two file in `/usr/bin/` for quickly compile and run code.

- build code
```bash
ahan@white:/code/primer$ cat /usr/bin/bprimer 

project_path=/code/primer
mkdir -p ${project_path}/build

filename=$1
build=$(echo $1 | sed 's=.cc==g')

g++ -o ../build/$build $filename
```

- run code
```bash
ahan@white:/code/primer$ cat /usr/bin/rprimer 
filename=$1
build=$(echo $1 | sed 's=.cc==g')

../build/$build
```

## Dir

.
├── build           // Compiled binary directory
├── ch1             // Code directory for each chapter
├── ch2
├── chxxx
└── source-file     // Book source code directory
