file_name="first.txt"
if [ -f "$file_name" ]; then
echo "$file_name exists"
else
echo "$file_name does not exist."
fi  