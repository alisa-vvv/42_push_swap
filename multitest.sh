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
mkdir -p KO_tests
i=0
over_threshold=0
ko=0
while [ $i -lt $tests_count ]
do
	if [ -e input.txt ]
	then
		rm input.txt
	fi
	touch input.txt
	shuf -i "$range" -n $amount >> input.txt
	sed -i ':a;N;$!ba;s/\n/ /g' input.txt
	./push_swap `cat input.txt` | tee ops | wc -l >> multitest_out.txt
	if [ "$(tail -n 1 multitest_out.txt)" -gt $max ]
	then
		mkdir -p failed_tests/$(tail -n 1 multitest_out.txt)
		cp input.txt failed_tests/$(tail -n 1 multitest_out.txt)/${i}
		true $((over_threshold=over_threshold+1))
	fi
	cat ops | ./checker_linux `cat input.txt` > OK_KO
	if [ "`cat OK_KO`" = "KO" ]
	then
		mkdir -p mkdir -p KO_tests/$(i)
		cp OK_KO KO_tests/$(i)
		true $((ko=ko+1))
	fi
	true $((i=i+1))
done
echo "Total tests run: $tests_count"
echo "Over the threshold: $over_threshold cases"
echo "KO'd: $ko cases"
