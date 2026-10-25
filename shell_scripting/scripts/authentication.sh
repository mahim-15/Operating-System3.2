
#!/bin/bash

read -p "Enter username: " username
read -s -p "Enter password: " password
echo

if grep -qxF "$username:$password" \
    "$HOME/operating-system/shell_scripting/practice/userdata.txt"; then
    echo "Login successful!"
else
    echo "Invalid username or password."
fi
