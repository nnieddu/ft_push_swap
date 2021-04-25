# for i in `seq 100`; do ./random.sh && echo; done 
# paplay done.wav
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
#  ./push_swap $ARG | ./checker $ARG
 ./push_swap $ARG | wc -l >> moyenne
# echo $ARG && ./push_swap $ARG # | ./checker $ARG`