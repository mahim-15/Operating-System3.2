
#!/bin/bash

echo "Using break:"
for i in 1 2 3 4 5
do
    if [ "$i" -eq 3 ]; then
        break
    fi
    echo "$i"
done

echo "Using continue:"
for i in 1 2 3 4 5
do
    if [ "$i" -eq 3 ]; then
        continue
    fi
    echo "$i"
done

