import java.lang.StringBuilder

// kotlin tips b/c I'm bad

/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/** valid ways to sort
 * 1
 * val a = nextLongs().sorted() // a is mutable list
 * 2
 * val a = arrayListOf<Long>()
 * a.addAll(nextLongs())
 * a.sort()
 */

/** declare 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
intArrayOf(8, 9, 1, 13),
intArrayOf(3, 12, 7, 5),
intArrayOf(0, 2, 4, 11),
intArrayOf(6, 10, 15, 14)
)
 */

/** printing variables:
 * println("${l+1} and $r")
 * evidently print has high constant factor
 * print stringbuilder instead?
 */

// ArrayList to Array: toArray

// IntArray with size:
// val arr = IntArray(1 shl 20, { 1 })

// lower bound: use binary search
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/binary-search.html

// if/switch
// https://kotlinlang.org/docs/reference/control-flow.html

// swap:
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/also.html
// a = b.also { b = a }

/** comparing pairs
 * val ed = ArrayList<Pair<Int,Pair<Int,Int>>>()
ed.sortBy {it.first}
 *  class CustomComparator : Comparator<Pair<Int,Pair<Int,Int>>> {
override fun compare(o1: Pair<Int,Pair<Int,Int>>, o2: Pair<Int,Pair<Int,Int>>): Int {
return o1.first.compareTo(o2.first)
}
}
val v = ed.sortedWith(CustomComparator())
 */

// (tree/hash)(map/set)
// ??

val MX = 1000005
val MOD = 998244353
val SZ = 1 shl 19
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

//var vect  = IntArray(5) declares array

//var a = readInts() declares arraylist

//val names = listOf("Anne", "Peter", "Jeff")
//for (name in names) {
//    println(name)
//}

//for (x in 0 until 10) println(x) Prints 0 through 9

//for (x in 0 until 10 step 2) println(x) Prints 0, 2, 4, 6, 8

//var (x, y) = readInts()
//a[i] = x
//b[i] = y

fun main(args: Array<String>) {
    val T = readInt()
    val out = StringBuilder()
    for (testcases in 1..T) {
        val n = readInt()
        var a = readInts()
        var p = IntArray(n)
        for (i in 0 until n)
            p[i]=a[i]*1000+i+1
        p.sort()
        var x : Int = 0
        var y : Int = n-1
        var cur : Int = 0
        /**for (i in 0 until n) {
            print(p[i])
            print(" ")
        }
        println()**/
        while (x<=y) {
            //println("${cur} ${p[x]} ${p[y]}")
            if (p[x]/1000<=cur) {
                out.append(p[x]%1000)
                out.append(" ")
                cur=1
                ++x
            }
            else {
                out.append(p[y]%1000)
                out.append(" ")
                ++cur
                --y
            }
        }
        out.appendln()
    }
    print(out)
}

//yes I stole Benq's template, Benq orz