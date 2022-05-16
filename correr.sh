for ((n = 1; n <= 50; n++))
do
	clear
	cc -Wall -Wextra -Werror main.c && ./a.out
	echo "loop numero $n/50"
	sleep 1
done
	
