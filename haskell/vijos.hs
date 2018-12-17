module Main where

import Data.Char

main = print . count . show . calc . words =<< getLine
  where
    calc :: [String] -> Integer
    calc [a, b] = (read a) ^ (read b)

    count :: String -> Int
    count = sum . map orz

    orz :: Char -> Int
    orz ch = ord ch - 48
