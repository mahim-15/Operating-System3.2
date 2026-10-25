
#!/bin/bash

add() {
    echo $(($1 + $2))
}

result=$(add 10 20)

echo "Sum: $result"
