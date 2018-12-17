import Data.List

main :: IO ()
main = do
  n <- getLine
  a <- getLine
  print $ w $ sort $ map read $ words a
  where
    w :: [Int] -> Int
    w a = a !! ((length a - 1) `quot` 2)