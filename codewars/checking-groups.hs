module Codewars.Kata.Groups where

groupCheck :: String -> Bool
groupCheck '{' ('}':s) = groupCheck s
groupCheck '[' (']':s) = groupCheck s
groupCheck '(' (')':s) = groupCheck s
groupCheck s = null s

main :: IO ()
main = do print $ groupCheck "({})"
          print $ groupCheck "[[]()]"
          print $ groupCheck "[{()}]"
          print $ groupCheck "{(})"
          print $ groupCheck "([]"
          print $ groupCheck "[])"
