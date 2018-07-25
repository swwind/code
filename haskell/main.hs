main :: IO ()
main = print $ (!! 1000000000000) $ fib 1 1
  where fib a b = a : fib b (a + b)
