module Lib
    ( someFunc
    ) where

import Data.Bits

evaluate :: Word -> Int
evaluate x = popCount x

color :: Word -> (Word, Int)
color x = (x, evaluate x)

eval :: (Word, Int) -> Int
eval (x, e) = e



someFunc :: IO ()
someFunc = print $ uniformR (1, 6)

