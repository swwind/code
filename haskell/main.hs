module Data where

import Data.List.Split

work num = do
  let set = splitOn " " getLine
  let x   = read set !! 1
  let y   = read set !! 2
  if x >= 2400 && y > x
    then putStrLn "YES"
    else work (num - 1)

main :: IO ()
main = do
  n <- getLine
  work read n
