import Data.Char

main :: IO ()
main = do
  nr <- getLine
  let [n, r] = map read $ words nr
  sequence_ $ take n $ repeat $ work r
  where
    work :: Int -> IO ()
    work r = do
      str <- getLine
      putStrLn (middle str) >> print (result str)
      where
        next :: Int -> Char -> Int
        next i c = (ord c - 65 + i) `mod` 26 + 65
        middle :: String -> String
        middle = map (chr . next r)
        result :: String -> Integer
        result = product . map (toInteger . next r)
