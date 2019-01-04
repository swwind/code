readInt :: IO Integer
readInt = readLn

main :: IO ()
main = do
  a <- readInt
  b <- readInt
  print $ a `div` b
