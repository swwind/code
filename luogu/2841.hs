import Data.List
import Data.Array
import Debug.Trace

readInt :: IO Int
readInt = readLn

generateArray :: Int -> String
generateArray b = go [(1, "1")]
  where
    go :: [(Int, String)] -> String
    go as | trace (show $ length as) False = undefined
    go ((0, a) : as) = a
    go as = go $ unique' $ sort
      $  [((fst a * 10)     `mod` b, snd a ++ "0") | a <- as]
      ++ [((fst a * 10 + 1) `mod` b, snd a ++ "1") | a <- as]

    filter' :: (a -> a -> Bool) -> [a] -> [a]
    filter' _ [] = []
    filter' f as = head as : [ as !! i | i <- [1 .. length as - 1], f (as !! i) (as !! (i - 1)) ]

    unique' :: [(Int, String)] -> [(Int, String)]
    unique' [] = []
    unique' as = filter' check as
      where
        check a b = (fst a) /= (fst b)

calc :: Int -> String -> String
calc b ab = show ((read ab) `div` (toInteger b)) ++ " " ++ ab

main :: IO ()
main = do
  b <- readInt
  putStrLn $ calc b $ generateArray b
