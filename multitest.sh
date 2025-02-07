read -p "enter the range (format. XX,XX): " range
read -p "enter amount of elements: " amount
read -p "enter tests count: " tests_count
read -p "enter fail threshhold: " max
make fclean
make all
if [ -e multitest_out.txt ]
then
	rm multitest_out.txt
fi
touch multitest_out.txt
mkdir -p failed_tests
i=0
while [ $i -lt $tests_count ]
do
	if [ -e input.txt ]
	then
		rm input.txt
	fi
	touch input.txt
	shuf -i "$range" -n $amount >> input.txt
	sed -i ':a;N;$!ba;s/\n/ /g' input.txt
	make run | wc -l >> multitest_out.txt
	if [ "$(tail -n 1 multitest_out.txt)" -gt $max ]
	then
		mkdir -p failed_tests/$(tail -n 1 multitest_out.txt)
		cp input.txt failed_tests/$(tail -n 1 multitest_out.txt)/${i}
	fi
	true $((i=i+1))
done
