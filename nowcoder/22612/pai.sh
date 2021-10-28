set -e
g++ mkdata.cpp -o mkdata

while true; do
  ./mkdata > .in
  ./std < .in > .ans
  ./a.out < .in > .out
  diff .out .ans
  echo passing
done
