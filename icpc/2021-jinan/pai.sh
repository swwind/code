set -e

while true; do

SIZE_N=1000
echo $SIZE_N > .in
cat /dev/urandom | tr -cd a-t | head -c $SIZE_N >> .in

./std < .in > .ans && ./D < .in > .out && diff .ans .out
echo Pass `cat /dev/urandom | tr -cd 0-9 | head -c 5`

done
