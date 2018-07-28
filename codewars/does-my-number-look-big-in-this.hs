module Narcissistic where

import Data.Char

charToInt :: Char -> Int
charToInt ch = ord ch - 48

narcissistic :: Integral n => n -> Bool
narcissistic n = (== toInteger n) $ toInteger $ sum $ map calc $ show $ toInteger n
  where
    len = length $ show $ toInteger n
    calc :: Char -> Int
    calc = (^ len) . charToInt

main :: IO ()
main = print $ narcissistic 370
