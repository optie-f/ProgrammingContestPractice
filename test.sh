# from https://qiita.com/AokabiC/items/af685bfd205dda44ec45
problemname=$1
oj dl "https://atcoder.jp/contests/${problemname:0:6}/tasks/${problemname:0:8}"
g++ -Wall -std=c++14 ./$1
oj test
rm -f a.out
rm -rf test 