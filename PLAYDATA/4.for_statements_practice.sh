dir_name="mydir2"
file_name="for_practice.txt"

if [ -d $dir_name ]; then
cd $dir_name
else
mkdir $dir_name
cd $dir_name
fi

if [ -e $file_name ]; then
  if [ -s $file_name ]; then
    > $file_name
  fi
  for a in {1..100}; do
    echo "hello world$a">> for_practice.txt
  done
else
  touch for_practice.txt
  for a in {1..100}; do
    echo "hello world$a">> for_practice.txt
  done
fi