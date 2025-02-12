read -p "enter the range (format. XX,XX): " range
read -p "amount: " amount
if [ input.txt ]
then
	rm input.txt
fi
touch input.txt
shuf -i "$range" -n $amount >> input.txt
sed -i ':a;N;$!ba;s/\n/ /g' input.txt
