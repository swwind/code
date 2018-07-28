module Fibonacci where

fibonacci :: Int -> Integer
fibonacci n = fib 0 1 !! n
  where
    fib a b = a : fib b (a + b)

add :: Int -> Int -> Integer
add a b = fibonacci a + fibonacci b

main :: IO ()
main = print $ add 1 1
