module Zeros where

zeros :: Int -> Int
zeros n = sum $ takeWhile (> 0) $ div5 (n `div` 5)
  where
    div5 n = n : div5 (n `div` 5)

main :: IO ()
main = print $ zeros 1000000000


