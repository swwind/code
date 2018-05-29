-- 438505383468410633

import Data.Bits
import Data.Array

main :: IO ()
main = print sg
  where
    n = 10000
    sg = take n $ fib 0 1
         where fib a b = a : fib b (a + b)
