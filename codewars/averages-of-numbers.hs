module Kata where

averages :: Maybe [Double] -> [Double]
averages Nothing = []
averages (Just xs) = [w i (i + 1) | i <- [0 .. length xs - 2]]
  where
    w x y = ((xs !! x) + (xs !! y)) * 0.5

main :: IO ()
main = print $ averages (Just [2.2, 6.1])