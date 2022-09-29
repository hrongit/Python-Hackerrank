#QUES LINK
#https://www.hackerrank.com/contests/int213-contest16/challenges/functional-programming-warmups-in-recursion---fibonacci-numbers

#Submit in Scala

object Solution {

  def fibonacci(x: Int): Int = x match {
    case 1 => 0
    case 2 => 1
    case _ => fibonacci(x - 1) + fibonacci(x - 2)
  }

  def main(args: Array[String]): Unit = {
    /* This will handle the input and output */
    println(fibonacci(readInt()))
  }

  def readInt(): Int = scala.io.StdIn.readInt()
}