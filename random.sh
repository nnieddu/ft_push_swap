# for i in `seq 100`; do ./random.sh && echo; done 
# ./checker $ARG
# paplay done.wav
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap $ARG | wc -l >> moyenne