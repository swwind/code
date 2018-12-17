module Codewars.Kata.Vowel where

getCount :: String -> Int
getCount ('a' : xs) = 1 + getCount xs
getCount ('e' : xs) = 1 + getCount xs
getCount ('i' : xs) = 1 + getCount xs
getCount ('o' : xs) = 1 + getCount xs
getCount ('u' : xs) = 1 + getCount xs
getCount (x : xs) = getCount xs
getCount [] = 0

-- getCount = length . filter (`elem` "aeiou")

main = print $ getCount "abracadabra"
