read -p "enter the range (format. XX,XX): " range
read -p "amount: " amount
if [ input.txt ]
then
	rm input.txt
fi
touch input.txt
shuf -i "$range" -n $amount >> input.txt
#i=0
#while [ $i -lt $amount ]
#do
#    shuf -i "$range" -n 1 >> input.txt
#	true $((i=i+1))
#done
sed -i ':a;N;$!ba;s/\n/ /g' input.txt
