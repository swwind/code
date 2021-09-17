g++ mkdata.cpp -o mkdata

COUNT=1
while true; do
  echo "making data"
  ./mkdata > .in
  echo "running b.out"
  ./b.out < .in > .ans
  echo "running a.out"
  ./a.out < .in > .out
  echo "finished"
  diff .ans .out
  if [[ $? > 0 ]]; then
    echo "what the fuck"
    exit 1
  fi
  COUNT=$(($COUNT+1))
  echo "pass $COUNT"
done
