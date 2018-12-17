module CamelCase where

import Data.Char
import Data.Array
import Data.List

splitWords :: String -> [String]
splitWords = words . map replace
  where
    replace c
      | isAlpha c = c
      | otherwise = ' '

toCamelCase :: String -> String
toCamelCase str = judgeFirst . foldl (++) [] . map toCamel $ realWords
  where
    realWords = splitWords str
    firstLatter = str !! 0

    toCamel :: String -> String
    toCamel = firstUpper . map toLower

    firstUpper :: String -> String
    firstUpper (ch : str) = toUpper ch : str

    judgeFirst :: String -> String
    judgeFirst [] = []
    judgeFirst (ch : str)
      | isLower firstLatter = toLower ch : str
      | otherwise           = toUpper ch : str

main :: IO ()
main = print $ toCamelCase "_ob_cz_vsgd"
