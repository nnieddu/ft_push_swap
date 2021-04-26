# for i in `seq 100`; do ./random.sh && echo; done 
# paplay done.wav
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
# echo $ARG >> moyenne
# ./push_swap $ARG  | ./checker $ARG >> moyenne
 ./push_swap $ARG | wc -l >> moyenne
#  ./push_swap $ARG 
# echo $ARG && ./push_swap $ARG # | ./checker $ARG`
