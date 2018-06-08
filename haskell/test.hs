main :: IO ()
main = print . sum . map read . words =<< getLine


