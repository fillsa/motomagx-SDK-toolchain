#bin/sh

FILES1=`ls | grep "на"`

echo "123"
echo $FILES1

for n in `ls | grep "на" | awk '{print $3}'`
do
echo "'Ссылка на $n'" "$n"
mv "Ссылка на $n" "$n"
done
