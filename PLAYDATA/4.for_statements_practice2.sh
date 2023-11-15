dir_name="mydir3"

echo "practice3 start"

if [ -d $dir_name ]; then
cd $dir_name
else
mkdir $dir_name
cd $dir_name
fi

for i in {1..100}
do
touch file$i.txt
  for j in {1..100}
  do
  echo "hello world from file$j" >> file$i.txt
  done
done