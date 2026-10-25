
#!/bin/bash

TODO_FILE="$HOME/operating-system/shell_scripting/practice/todo.txt"

# Create the todo file if it does not exist
touch "$TODO_FILE"

case "$1" in
    add)
        if [ -z "$2" ]; then
            echo "Usage: ./todo.sh add \"task name\""
        else
            echo "[ ] $2" >> "$TODO_FILE"
            echo "Task added: $2"
        fi
        ;;

    list)
        if [ ! -s "$TODO_FILE" ]; then
            echo "No tasks found."
        else
            cat -n "$TODO_FILE"
        fi
        ;;

    done)
        if ! [[ "$2" =~ ^[0-9]+$ ]] || [ "$2" -lt 1 ]; then
            echo "Usage: ./todo.sh done task_number"
        elif [ "$2" -gt "$(wc -l < "$TODO_FILE")" ]; then
            echo "Task number does not exist."
        else
            sed -i "${2}s/^\[ \]/[x]/" "$TODO_FILE"
            echo "Task $2 marked as done."
        fi
        ;;

    search)
        if [ -z "$2" ]; then
            echo "Usage: ./todo.sh search \"keyword\""
        else
            grep -inF -- "$2" "$TODO_FILE" || echo "No matching tasks found."
        fi
        ;;

    clear)
        > "$TODO_FILE"
        echo "All tasks cleared."
        ;;

    *)
        echo "Todo List Manager"
        echo "Usage:"
        echo "  ./todo.sh add \"task name\""
        echo "  ./todo.sh list"
        echo "  ./todo.sh done task_number"
        echo "  ./todo.sh search \"keyword\""
        echo "  ./todo.sh clear"
        ;;
esac
