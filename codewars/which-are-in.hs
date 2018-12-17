module Codewars.Kata.Which where

import Data.List

-- Sorry for the name of the function.
inArray :: [String] -> [String] -> [String]
inArray a1 a2 = nub . sort $ filter valid a1
  where
    valid :: String -> Bool
    valid a = any (isInfixOf a) a2

main :: IO ()
main = print $ inArray ["tarp", "mice", "bull"] ["lively", "alive", "harp", "sharp", "armstrong"]

