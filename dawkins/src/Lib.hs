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
someFunc = do
    rand <- (getStdRandom $ randomR (0,1) :: IO Double)
    print rand

