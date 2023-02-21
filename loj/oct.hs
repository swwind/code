import Data.Array
import Data.List

data Regex
    = C_0 | C_1 | C_2 | C_3 | C_4 | C_5 | C_6 | C_7 | C_8 | C_9
    | Or [Regex]
    | Concat [Regex]
    | Star Regex

epsilon, none :: Regex
epsilon = Concat []
none = Or []

mkOr :: [Regex] -> Regex
mkOr as = case as >>= expandOr of
    [a] -> a
    rs -> Or rs
    where
        expandOr (Or as) = as
        expandOr a = [a]

mkStar :: Regex -> Regex
mkStar (Or []) = epsilon
mkStar (Concat []) = epsilon
mkStar a = Star a

mkConcat :: [Regex] -> Regex
mkConcat as = case as >>= expandConcat of
    as | any isNone as -> Or []
    [a] -> a
    as -> Concat as
    where
        expandConcat (Concat as) = as
        expandConcat a = [a]

        isNone (Or []) = True
        isNone _ = False


instance Show Regex where
    show regex = go regex
        where
            go C_0 = "0"
            go C_1 = "1"
            go C_2 = "2"
            go C_3 = "3"
            go C_4 = "4"
            go C_5 = "5"
            go C_6 = "6"
            go C_7 = "7"
            go C_8 = "8"
            go C_9 = "9"
            go (Or []) = error "Something went wrong"
            go (Or as) = "(" ++ intercalate "|" (go <$> as) ++ ")"
            go (Concat as) = concat $ go <$> as
            go (Star m) = optParens m ++ "*"

            optParens :: Regex -> String
            optParens C_0 = "0"
            optParens C_1 = "1"
            optParens C_2 = "2"
            optParens C_3 = "3"
            optParens C_4 = "4"
            optParens C_5 = "5"
            optParens C_6 = "6"
            optParens C_7 = "7"
            optParens C_8 = "8"
            optParens C_9 = "9"
            optParens a@Or{} = go a
            optParens a = "(" ++ go a ++ ")"

type Matrix = Array (Int, Int)

infix 2 -->
(-->) :: a -> b -> (a, b)
(-->) = (,)

floyd :: Matrix Regex -> Matrix Regex
floyd mat = foldl' update mat ixs
    where
        bnds@((minIx, _), (maxIx, _)) = bounds mat
        pairs = indices mat
        ixs = [minIx .. maxIx]

        update m k = listArray bnds $ (\(i, j) -> build m i j k) <$> pairs

        build m i j k = mkOr [i ~> j, mkConcat [i ~> k, mkStar (k ~> k), k ~> j]]
            where u ~> v = m ! (u, v)

makeMatrix :: (Int, Int) -> [((Int, Int), Regex)] -> Matrix Regex
makeMatrix (minIx, maxIx) ts = mkOr <$> accumArray (flip (:)) [] ((minIx, minIx), (maxIx, maxIx)) ts

divisibleDfa :: Int -> [((Int, Int), Regex)]
divisibleDfa m = [0 .. m - 1] >>= (\i ->
    [ (i --> (i * 10) `mod` m, C_0)
    , (i --> (i * 10 + 1) `mod` m, C_1)
    , (i --> (i * 10 + 2) `mod` m, C_2)
    , (i --> (i * 10 + 3) `mod` m, C_3)
    , (i --> (i * 10 + 4) `mod` m, C_4)
    , (i --> (i * 10 + 5) `mod` m, C_5)
    , (i --> (i * 10 + 6) `mod` m, C_6)
    , (i --> (i * 10 + 7) `mod` m, C_7)
    , (i --> (i * 10 + 8) `mod` m, C_8)
    , (i --> (i * 10 + 9) `mod` m, C_9)])

divisibleRegex :: Int -> Regex
divisibleRegex n = (! (0, 0)) . floyd . makeMatrix (0, n - 1) $ divisibleDfa n

main = do
    n <- read <$> getLine
    print (divisibleRegex n)
