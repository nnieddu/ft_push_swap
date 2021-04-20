# for i in `seq 100`; do ./random.sh && echo; done 
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap $ARG | ./checker $ARG #wc -l >> moyenne