import Data.Char
import Data.List
import Data.Array

numbers :: String -> [Int]
numbers = map read . words

gets :: (Int, Int) -> IO [String]
gets (n, m) = mapM _getLine [0 .. n - 1]
  where
    _getLine :: Int -> IO String
    _getLine a = getLine

filterStar :: [String] -> [String]
filterStar = map (map replace)
  where
    replace '*' = '*'
    replace  _  = '.'

count :: Char -> [Char] -> Int
count a b = sum $ map check b
  where
    check x
      | x == a    = 1
      | otherwise = 0

toChar :: Int -> Char
toChar 0 = '.'
toChar a = chr (ord '0' + a)

calculate :: (Int, Int) -> [String] -> [String]
calculate (n, m) a =
  map update [0 .. n - 1]
  where
    update i = map (w i) [0 .. m - 1]
    w i j
      | index (i, j) == '*' = '*'
      | otherwise = toChar $ count '*' (map index [(i + x, j + y) | x <- [-1 .. 1], y <- [-1 .. 1]])
    index (u, v)
      | u == -1 || u == n = ' '
      | v == -1 || v == m = ' '
      | otherwise = a !! u !! v

infix 4 <?>
(<?>) :: a -> a -> Bool -> a
a <?> b = \i -> if i then a
                     else b

main :: IO ()
main = do
  firstLine <- getLine
  let [n, m] = numbers firstLine
  res <- gets (n, m)
  putStrLn $ ("YES" <?> "NO") $ (== res) $ calculate (n, m) $ filterStar res
