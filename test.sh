## for i in `seq 100`; do ./random.sh && echo; done 
## paplay done.wavs


# ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
# echo $ARG >> moyenne
#  ./push_swap $ARG | wc -l
#  ./push_swap $ARG | ./checker

for y in `seq 5000`; do
# for i in `seq 501`; do
# echo "i = $i"
# echo "y = $y"
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
# echo $ARG >> moyenne
# ./push_swap $ARG | wc -l >> moyenne
./push_swap $ARG | ./checker $ARG >> moyenne
# echo >> moyenne
# done
done
paplay done.wav
