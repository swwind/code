module Zeros where
import Data.Bits

zeros :: Int -> Int
zeros n = sum $ takeWhile (> 0) $ div5 (n `div` 5)
  where
    div5 n = n : div5 (n `div` 5)

main :: IO ()
main = print $ sum [1 - (zeros i .&. 1) | i <- [0 .. 546456]]


