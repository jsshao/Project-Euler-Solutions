/* 
 * The most interesting part about this problem is to determine whether a number is triangular or not.
 * As we know, if x is triangular, then x = n*(n+1)/2 for some integer n.
 * Similarly, 2x = n(n+1)
 *            2x = (n+1/2)^2 - 1/4
 *            8x = (2n + 1)^2 - 1
 *  sqrt(8x + 1) = 2n + 1
 *             n = (sqrt(8x + 1) - 1) / 2
 *
 * Therefore, to test if number x is triangular, n = (sqrt(8x+1) - 1) / 2 MUST be an integer
 * 
 * Actually, all we need to test is if sqrt(8x+1) is an integer. This is because we know
 * that 8x + 1 is an odd number, so sqrt(8x+1) will also be odd. Consequently, sqrt(8x+1) - 1
 * will be even which allows it to be divisible by 2. So if sqrt(8x+1) is an integer, then n is also
 * an integer and x is triangular.       
 */

object Problem42 {
    /* Returns whether or not a number is a perfect square */
    def isPerfectSquare(x: Int): Boolean = {
        val rt = Math.round(Math.sqrt(x))
        rt*rt == x
    }

    def main(args: Array[String]) {
        
        /* Read text file */
        val file = scala.io.Source.fromFile("words.txt").mkString

        /* Split the text into an array of words delimited by the comma */
        var words = file.split(',')

        /* Remove the quotation marks */
        words = words.map(word => word.substring(1, word.length()-1))
        
        /* Calculate the alphabetical sum of the word */
        val values = words.map(word => {
            var temp = 0
            for (letter <- word.toCharArray) {
                temp = temp + letter - 'A' + 1
            }
            temp
        })

        /* Count how many words were triangular */
        println(values.filter(x => isPerfectSquare(8*x + 1)).size)
    }	
}
