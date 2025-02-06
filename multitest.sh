read -p "enter the range (format. XX,XX): " range
read -p "amount: " amount
read -p "tests count: " tests_count
make fclean
make all
if [ -e multitest_out.txt ]
then
	rm multitest_out.txt
fi
touch multitest_out.txt
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
	true $((i=i+1))
done
