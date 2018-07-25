frac :: Integer -> Integer
frac 0 = 1
frac n = n * frac (n - 1)

main :: IO ()
main = print $ frac 10000