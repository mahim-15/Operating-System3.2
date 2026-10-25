

#!/bin/bash

read -p "Enter a number (1-3): " choice

case "$choice" in
    1)
        echo "You selected One."
        ;;
    2)
        echo "You selected Two."
        ;;
    3)
        echo "You selected Three."
        ;;
    *)
        echo "Invalid choice."
        ;;
esac
