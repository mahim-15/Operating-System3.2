
#!/bin/bash

read -p "Enter your age: " age
read -p "Do you have an ID? (yes/no): " id

if [ "$age" -ge 18 ] && [ "$id" = "yes" ]; then
    echo "Entry allowed."
else
    echo "Entry denied."
fi

