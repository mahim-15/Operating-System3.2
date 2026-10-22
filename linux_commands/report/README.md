# Basic Linux Commands Lab

## Objective
To practice basic Linux commands and understand their options.

## 1. cat
- `cat hello.txt` — displays file contents.
- `cat -n hello.txt` — numbers all output lines.
- `cat -A hello.txt` — displays line endings and non-printing characters.
- `cat -b hello.txt` — numbers non-empty lines.
- `cat -s hello.txt` — squeezes repeated blank lines.

## 2. ls
- `ls` — lists files and directories.
- `ls -l` — shows a long listing.
- `ls -a` — includes hidden files.
- `ls -R` — lists directories recursively.
- `ls -t` — sorts by modification time.

## 3. cp
- `cp hello.txt copied.txt` — copies a file.
- `cp -i hello.txt copied.txt` — prompts before overwriting.
- `cp -n hello.txt copied.txt` — avoids overwriting an existing file.
- `cp -v hello.txt backup.txt` — prints the copy operation.
- `cp -r parent backup_dir` — copies a directory recursively.

## 4. touch
- `touch empty.txt` — creates an empty file if absent.
- `touch -c missing.txt` — does not create a missing file.
- `touch -a hello.txt` — updates access time.
- `touch -m hello.txt` — updates modification time.
- `touch -t 202610221500 timestamp.txt` — sets a specified timestamp.

## 5. rm
- `rm copied.txt` — removes a file.
- `rm -i copied.txt` — asks before removing.
- `rm -f copied.txt` — forces removal without prompting.
- `rm -r testdir` — removes a directory and its contents.
- `rm -v copied.txt` — reports each removal.

## 6. mkdir
- `mkdir testdir` — creates a directory.
- `mkdir -p parent/child` — creates parent directories as needed.
- `mkdir -v newdir` — reports directory creation.
- `mkdir -m 755 accessdir` — sets permissions during creation.
- `mkdir -p nested/one/two` — creates nested directories.

## 7. pwd
- `pwd` — prints the current working directory.
- `pwd -L` — prints the logical path.
- `pwd -P` — prints the physical path.
- `cd ..; pwd` — prints the parent directory path.
- `cd ~/operating-system; pwd` — prints the repository path.

## 8. grep
- `grep "Linux" notes.txt` — searches for matching lines.
- `grep -n "Linux" notes.txt` — includes line numbers.
- `grep -i "linux" notes.txt` — ignores case.
- `grep -w "Linux" notes.txt` — matches the whole word.
- `grep -c "Linux" notes.txt` — counts matching lines.

## Screenshots
Terminal screenshots will be saved in the `screenshots/` directory.

