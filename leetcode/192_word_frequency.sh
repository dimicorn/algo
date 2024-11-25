# Read from the file words.txt and output the word frequency list to stdout.
file="words.txt"
declare -A words
result=1
search() {
    array=$1
    key=$2
    for x in "${!array[@]}"; do
        if [[ x == key ]]; then
            result=1
        fi
    done
    result=0
}

while read -r line; do
    for word in $line; do
        search words word
        if [[ result -eq 1 ]]; then
            words[$word]=1
        else
            words[$word]=$((words[$word]+1))
        fi
    done
done <$file 

for key in "${!words[@]}"; do
    echo -e "$key ${words[$key]}"
done |
sort -rn -k2 
