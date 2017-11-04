import Data.List (permutations)
main :: IO ()
main = putStrLn $
       concatMap (concatMap show . (\([o1, o2, o3, o4], [i1, i2, i3]) ->
         [6, 5, 3, o1, 3, i1, o2, i1, i2, o3, i2, i3, o4, i3, 5])) $
       filter (\([o1, o2, o3, o4], [i1, i2, i3]) ->
                o1 + 3 + i1 == 14 && o2 + i1 + i2 == 14 &&
                o3 + i2 + i3 == 14 && o4 + i3 + 5 == 14)
              [(o, i) | o <- permutations [7, 8, 9, 10],
                        i <- permutations [1, 2, 4]]