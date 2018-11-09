import Data.Bits

infix 6 <?>
(<?>) :: a -> a -> Bool -> a
a <?> b = w a b
  where
    w a b c
      | c         = a
      | otherwise = b

main :: IO ()
main = do
  firstLine <- getLine
  datas     <- getLine
  let [n, m] = (map read $ words firstLine) :: [Int]
  putStrLn $ encode $ work n m $ decode datas
  where
    decode a = map (== 'b') a
    encode a = map ('b' <?> 'd') a
    work n m a =
      foldl w a [0 .. 31]
      where
        w a i
          | testBit m i = [zXor i (mod (st + i) n) | i <- [0 .. n - 1]]
          | otherwise   = a
          where
            st = mod (negate $ bit i) n
            zXor i j =
              xor (a !! i) (a !! j)
