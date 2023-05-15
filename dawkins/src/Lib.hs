module Lib
    ( someFunc
    ) where

import Data.Bits
import System.Random

evaluate :: Word -> Int
evaluate x = popCount x

color :: Word -> (Word, Int)
color x = (x, evaluate x)

eval :: (Word, Int) -> Int
eval (x, e) = e



someFunc :: IO ()
someFunc = print $ take 10 (randomRs (0, 10) newStdGen)

