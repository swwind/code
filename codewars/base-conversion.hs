module BaseConversion where

import Data.List

newtype Alphabet = Alphabet { getDigits :: [Char] } deriving (Show)

convert :: Alphabet -> Alphabet -> String -> String
convert (Alphabet a) (Alphabet b) = encode b . decode a
  where
    decode :: [Char] -> String -> Integer
    decode _ [] = 0
    decode a s = foldl go 0 s
      where
        go :: Integer -> Char -> Integer
        go x c = case elemIndex c a of
          Nothing -> error "something wrong..."
          Just i -> bs * x + toInteger i
        bs = toInteger $ length a
    encode :: [Char] -> Integer -> String
    encode a 0 = [head a]
    encode a c = go c
      where
        go :: Integer -> String
        go 0 = []
        go c = go (c `div` bs) ++ [a !! (fromInteger (c `rem` bs))]
        bs = toInteger $ length a



bin, oct, dec, hex, alphaLower, alphaUpper, alpha, alphaNumeric :: Alphabet
bin = Alphabet $ "01"
oct = Alphabet $ ['0'..'7']
dec = Alphabet $ ['0'..'9']
hex = Alphabet $ ['0'..'9'] ++ ['a'..'f']
alphaLower    = Alphabet $ ['a'..'z']
alphaUpper    = Alphabet $ ['A'..'Z']
alpha         = Alphabet $ ['a'..'z'] ++ ['A'..'Z']
alphaNumeric  = Alphabet $ ['0'..'9'] ++ ['a'..'z'] ++ ['A'..'Z']

main :: IO ()
main = do
  print $ convert dec bin "15"
  print $ convert dec oct "15"
  print $ convert bin dec "1010"
  print $ convert bin hex "1010"
  print $ convert dec alpha      "0"
  print $ convert dec alphaLower "27"
  print $ convert alphaLower hex "hello"
