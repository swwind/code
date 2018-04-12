factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

fuckyou :: Int -> String
fuckyou x = case x of 0 -> "Hello world"
                      1 -> "No"
                      _ -> "Love"

main :: IO()
main = putStrLn (fuckyou 0)