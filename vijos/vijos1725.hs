import Data.Array
import Data.List

type Matrix = Array (Int, Int)

infix 2 -->
(-->) :: a -> b -> (a, b)
(-->) = (,)

makeMatrix :: (Int, Int) -> [[Int]] -> Matrix Int
makeMatrix (minIx, maxIx) a = listArray ((minIx, minIx), (maxIx, maxIx)) $ concat a

main :: IO ()
main = do
  -- dat <- getLine
  -- let [m, a, c, x, n, g] = (map read $ words dat) :: [Int]
  print $ makeMatrix (0, 1) [[0, 2], [1, 3]]
