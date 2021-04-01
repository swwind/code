g++ A.cpp -o A
g++ B.cpp -o B
g++ mkdata.cpp -o mkdata

while true; do

./mkdata > .in
# cat .in

./A < .in > a.out
./B < .in > b.out

diff a.out b.out

if [ $? -gt 0 ]; then
  echo Wrong Answer
  exit 1
fi

echo Accepted $(date)

done