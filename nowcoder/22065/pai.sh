set -e

g++ mkdata.cpp -o mkdata

ROUND=1

while true; do
./mkdata > .in
./std < .in > .ans
./mie < .in > .out
diff .ans .out
echo Round $ROUND return $? passing
ROUND=$[ROUND + 1]
done
