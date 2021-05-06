## for i in `seq 100`; do ./random.sh && echo; done 
## paplay done.wavs

for y in `seq 1000`; do
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
echo $ARG >> moyenne
./push_swap $ARG | wc -l >> moyenne
./push_swap $ARG | ./checker $ARG >> moyenne
echo >> moyenne
done

# for y in `seq 5000`; do
# # for i in `seq 501`; do
# # echo "i = $i"
# # echo "y = $y"
# ARG=`ruby -e "puts (0..49).to_a.shuffle.join(' ')"`
# echo $ARG  >> moyenne
# ./push_swap $ARG  | wc -l >> moyenne
# ./push_swap $ARG | ./checker $ARG >> moyenne
# # echo >> moyenne
# # done
# done
# paplay done.wav


# // int i;
# // for(i=0;i<a.size;i++)
# // {
# // 	dprintf(2, "%d ", a.stack[i]);
# // 	// if (a.stack[i] > a.stack[i + 1])
# // 		// dprintf(2, "\n\n [%d] | [%d] \n\n", a.stack[i], a.stack[i + 1]);
# // }
# // if (ft_is_sorted_num(&a, a.size) == 1)
# // 	ft_putstr_fd("KO\n", 2);
# // else
# // 	ft_putstr_fd("OK\n", 2);	

# https://raw.githubusercontent.com/rizky/42-corrections/master/push_swap.pdf