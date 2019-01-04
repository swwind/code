main :: IO ()
main = do
  s <- getLine
  a <- getLine
  b <- getLine
  print $ (read a) * (read b)