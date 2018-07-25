main :: IO ()
main = print $ (!! 100000) $ fib 1 1
  where fib a b = a : fib b (a + b)
