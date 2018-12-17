module Codewars.Kata.Dubstep where

import Data.List

songDecoder :: String -> String
songDecoder = unwords . words . replace
  where
    replace :: String -> String
    replace ('W' : 'U' : 'B' : xs) = ' ' : replace xs
    replace (ch : xs) = ch : replace xs
    replace [] = []

main :: IO ()
main = print $ songDecoder "NEVERWUBWUBGONNAWUBGIVEWUBWUBYOUWUBWUBUPWUBWUBNEVERWUBWUBWUBWUBGONNAWUBWUBLETWUBWUBYOUWUBWUBDOWN"

