
fake :: String -> String
fake str = str ++ str

main :: IO()
main = print (map fake ["misaka", "mikoto"])



