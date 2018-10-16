module Anagram where

import Data.Array

toLetterMap :: String -> Array Char Int
toLetterMap = accumArray (+) 1 ('a', 'z') . map (\x -> (x, 1))

anagrams :: String -> [String] -> [String]
anagrams w ws = filter ((== wmap) . toLetterMap) ws
  where
    wmap = toLetterMap w

main :: IO ()
main = do
  print $ anagrams "abba" ["aabb", "abcd", "bbaa", "dada"]
  print $ anagrams "laser" ["lazing", "lazy",  "lacer"]

-- anagrams = filter . (on (==) sort)
