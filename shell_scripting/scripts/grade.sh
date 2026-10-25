
#!/bin/bash

read -p "Enter your marks: " marks

if [ "$marks" -ge 80 ]; then
    echo "Grade: A+"
elif [ "$marks" -ge 70 ]; then
    echo "Grade: A"
elif [ "$marks" -ge 60 ]; then
    echo "Grade: A-"
else
    echo "Grade: Below A-"
fi
