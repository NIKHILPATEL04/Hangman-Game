# Runs the program
./hangman "zyxwvutsrqponmlkjihgfedcba" output.txt 

# Ensures exit code is Zero
if [ $? -ne 0 ]; then
    echo "invalid exit code" $?
    rm output.txt
fi

# Ensures differences *are* found
diff output.txt win.txt
if [ $? -eq 0 ]; then
    echo "the output passes"
    rm output.txt
else 
    echo "the output fails"
    rm output.txt
fi


# Runs the program
./hangman "don't go in empty-handed" output.txt

# Ensures exit code is Zero
if [ $? -ne 0 ]; then
    echo "invalid exit code" $?
    rm output.txt
fi

# Ensures differences *are* found
diff output.txt lose.txt
if [ $? -eq 0 ]; then
    echo "the output passes"
    rm output.txt
else
    echo "the output fails"
    rm output.txt
fi

