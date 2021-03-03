/* 
 * CS:APP Data Lab 
 * 
 * NGPONG
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /** 
   * 依据练习题 2.13 可获取公式: 
   *  1. x ^ y = (x & ~y) | (~x & y)
   *
   * 故，该题实际是求得 | 与 ~ & 的转换式
   * 依据试验可得公式: 
   *  2. x | y = ~(~x & ~y)
   *
   * 代入第一个公式可得:
   *  3. x ^ y = ~(~(x & ~y) & ~(~x & y))
  */
  return ~(~(x & ~y) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /**
   * Tmin = -2^w-1
  */
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /**
   * 核心等式为: (x + 1) + x，将它代入 TMax 可得:
   *  1. 1111 1111 1111 1111 1111 1111 1111 1111
   * 当我们对这条结果进行取反后可得: 
   *  2. 0000 0000 0000 0000 0000 0000 0000 0000
   * 即，TMax 的情况下能够保有这一条特性，即经过: 
   *  3. ~((x + 1) + x)
   * 可以得到一个 0，那么再对这个 0 取反返回则能够获得题目要求的返回结果。
   *
   *
   * 但是，需要考虑一个问题，当 x 等于 -1 时，那么等式 3 的结果是相同的，
   * 所以我们需要解决一个问题: 如何排除 x = -1 的情况。
   *
   *
   * 对比 -1 和 TMax
   *  4.   -1: 1111 1111 1111 1111 1111 1111 1111 1111
   *  5. TMax: 0111 1111 1111 1111 1111 1111 1111 1111
   * 会发现，当对 -1 取反的时候可以获得 0，利用这一条特性，获得等式: 
   *  6. !(~x)
   * 前缀表达式加上表达式 6，即，当等于 -1 的时候，哪怕前缀表达式((x + 1) + x)的结果相同，
   * 也能够因为该加法的情况而忽略掉 -1，因为: 
   *  7. !(~ -1) = 1
   *  8. !(~ TMax) = 0
  */
  return !(~((x + 1) + x) + !(~x));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /**
   * NOTE: 
   *  - where bits are numbered from 0 (least significant) to 31 (most significant)，这段话可以无视，可能大致意思是限制数 x 为 int 类型
   *  - 只要一个数的所有奇数位为 1 即可，也就是说，即便偶数位为 1 也无所谓
   * 
   * 1. 构造 mask，其为 0xAAAAAAAA，在二进制表示中，它的 int 类型下所有奇数位为 1 的数
   * 2. 使 x 和 mask 做逻辑与，目的是为了忽略掉偶数位，保留其奇数位
   * 3. 第二步的结果与 mask 做一次位或非，如果其结果和 mask 一致，则得到 0，取反后得到正确的结果
  */
  int tmp = (0xAA << 8) + 0xAA;
  int mask = (tmp << 16) + tmp;

  return !((x & mask) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /**
   * [按位取反] 可拆解为表达式:
   *  1. ~x = x * -1 - 1
   * 那么本题要求返回任意数 x 的
   *  2. x * -1
   * 即: 
   *  3. ~x + 1 = x * -1 - 1 + 1 = x * -1
   *
   * NOTE: 这里要考虑下 TMin 的情况，~TMin = TMax，所以再使
   * 之 +1 则会发生正整数溢出，即 TMin * -1 = TMin, w <= 32
  */
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /**
   * 观察 0x30 ~ 0x39: 
   *  0x30: 0000 0000 0000 0000 0000 0000 0011 0000
   *  0x31: 0000 0000 0000 0000 0000 0000 0011 0001
   *  0x32: 0000 0000 0000 0000 0000 0000 0011 0010
   *  0x33: 0000 0000 0000 0000 0000 0000 0011 0011
   *  0x34: 0000 0000 0000 0000 0000 0000 0011 0100
   *  0x35: 0000 0000 0000 0000 0000 0000 0011 0101
   *  0x36: 0000 0000 0000 0000 0000 0000 0011 0110
   *  0x37: 0000 0000 0000 0000 0000 0000 0011 0111
   *  0x38: 0000 0000 0000 0000 0000 0000 0011 1000
   *  0x39: 0000 0000 0000 0000 0000 0000 0011 1001
   * 发现总共可以分为三种情况: 
   *  1. 4~7bit 总是 0010，它对应了表达式: 
   *    * !(3 ^ (x >> 4)): 当数 x 的 4~7bit 为 0010 时，返回 true
   *  2. 0x30~0x37 的 4bit 恒为 0，前 3bit 涵盖了所有情况，那么利用掩码的实现就可以过滤数 x 是否属于 0x30~0x37 的而范围，即表达式: 
   *    * !(x ^ (x & 0x37)): 当数 x 属于 0x30~0x37 范围时，返回 true，任何不属于该范围的数返回 false
   *  3. 0x38~0x39 的两种情况根据第二点同样可以使用表达式: 
   *    * !(x ^ (x & 0x39)): 当数 x 属于 0x38~0x39 范围时，返回 true，任何不属于该范围的数返回 false
   *
   *  由于一个数是不可能同时满足 2,3 的情况，故针对这一场景我们需要使用 位或 来链接两种情况的可能，即仅当任意一种情况发生时，我们需要返回 true: 
   *    * (!(x ^ (x & 0x37))) | (!(x ^ (x & 0x39))): 当数 x 属于 0x30~0x39 范围时，返回 true
   *
   *  其中，第 1 的情况判断 4~7bit 恒为 0010 的目的看似多余，其实他是为了过滤掉特殊的情况，如 0, TMax, TMin
   *  并且，情况 1 和情况 23 必须同时为 true 才能够返回正确的结果，故这里使用了 位与 进行了连接，保证两种情况(情况1 和 情况23)同时为 true 时才返回正确结果，即: 
   *    * !(3 ^ (x >> 4)) & ((!(x ^ (x & 0x37))) | (!(x ^ (x & 0x39))))
   *
   * */

  return (!(3 ^ (x >> 4))) & ((!(x ^ (x & 0x37))) | (!(x ^ (x & 0x39))));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /**
   * 首先查看表达式:
   *  - (cond & y) | (~cond & z)
   * 在这里，cond 仅有两种情况: 
   *  - -1: true
   *  -  0: false
   * 因为当 cond = -1 时也代表着 true，那么当它与任意数进行逻辑与的时候也会获得被操作数的结果，反之，使用它作位反，则能够获得 0，那么 0 与任意数做逻辑与则会获得 0，也对应着 false 条件
   *
   * 故，需要考虑，如何将原有的 x:
   *  - 非0: true
   *  -   0: false
   * 转换为上述的 true/false 结果
   *
   * 这里仅考虑 true 的条件，我们让它左移 31(0x1F) 位是为了达到 int 的符号位，再右移 31 位，由于做的是算数右移，故就能够获取到 -1 的结果
  */
  int cond = (((!!x) << 0x1F) >> 0x1F);
  return (cond & y) | (~cond & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /**
   * 求得 x == y 可以利用一下表达式实现:
   *   !(x ^ y)
   *
   * 这里需要重点关注 x < y 的情况，我们可以把这种情况细分为以下两种解决场景:
   *   1. 当 x 和 y 的 sign-bit 相同时，可以依据表达式: [x - y < 0] 获得 x < y 的结果，它对应
   *   了表达式: 
   *     !(sign_x ^ sign_y) & !(((x + (~y + 1)) >> 31) ^ (~0))
   *     ------------------   --------------------------------
   *              |                            |
   *              |                            |
   *              ↓                            ↓
   *     判断 x, y sign-bit               x + -y 的计算表达式
   *     不相同的 mask，它
   *     和逻辑与相连
   *
   *   2. 因为情景1可能发生算数溢出的情况，当发生算数溢出时，x - y 就难以得到正确的结果，经过
   *   观察可知，发生算数溢出的场景都为 x 和 y 的 sign-bit 不相同的情景，故利用这一条件，我们
   *   只需要判断如果 x 的 sign-bit 为 1，y 的sign-bit 为 0 时，就证明了 x < y，它对应了表达式: 
   *     !((sign_x ^ 1) | (sign_y ^ 0))
   *
   * 因为这两种场景仅取一种即可，故使用位或相连
  */

  int sign_x = !!(x >> 31);
  int sign_y = !!(y >> 31);

  return ((!(sign_x ^ sign_y) & !(((x + (~y + 1)) >> 31) ^ (~0))) | (!((sign_x ^ 1) | (sign_y ^ 0)))) | !(x ^ y);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /**
   * 依据题解，当返回 0 时分为两种情况:
   *   1. 负数
   *     - 判断符号位是否为 1: (x >> 31) & 1
   *   2. 正数
   *     - 任意整数 + TMax 会导致溢出: ((x + TMax) >> 31 & 1)
   *
   * 当情景 1 和 情景 2 做逻辑或，这有当二者条件都不满足时(返回0)才得到0，否则为1，再对
   * 结果进行取反即可: 
   *   3. (is_negative | is_positive) ^ 1
  */
  int is_negative = (x >> 31) & 1;

  int TMax = (1 << 31) + (~0);
  int is_positive = ((x + TMax) >> 31 & 1);
  
  return (is_negative | is_positive) ^ 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /** Solution
   * 我们可以观察 [负数] 和 [正数] 其二进制位的表示情况，不妨得出结论: 
   *   - 负数: 寻找最高 bit 为 [0] 的过程
   *   - 正数: 寻找最高 bit 为 [1] 的过程
   * 所以，为了保证负数结果的计算方便，我们需要完成以下表达式: 
   *   - x < 0 ? ~x : x
   * 这样，针对 [负数] 的算数我们也同样可以使用寻找最高 bit 为 [1] 来实现，这对赢了表达式
   *   - sign = (x >> 31) & 1;
   *   - cond = (sign << 0x1F) >> 0x1F;
   *   - x = (cond & ~x) | (~cond & x);
   * 
   * 
   * 再思考，我们到底如何求一个数到底需要几个有效 bit？
   * 在这里运用了二分法的思想，即: 
   *   1. 先右移一个数的一半 bit (初始为 32 bit，即这里第一步需要右移 16 位)
   *     - 如果移位的取反结果为 [1]: 证明所 [移出去的 16 bit] 都是有效位，那么我们就可以在此次移动算出前 16 bit 都属
   *     于有效位，并且，由于我们是能够确定 [移出去的 16 bit] 属于 [完全 16 bit 的有效位]，故为了防止下一次移位计算了
   *     重复的数，我们要对原数真正右移 16 位
   *     - 如果移位的取反结果为 [0]: 证明 [后 16 bit(不是移出去的 16 bit)] 都不属于有效位，那么我们就需要继续缩减移位
   *     的范围，并且由于 [移出去的 16 bit] 我们无法判断是否是 [完全 16 bit 的有效位]，故我们不能改变原数的结果
   *
   *   2. 继续缩小移位的范围，第二次为移动 8 位，继续依照第一步的步骤进行判断
   *
   *   3. .....
   *
   * 那么在最终我们就可以计算出一共有多少个有效位，当然，最终的结果我们还要 [加上一个符号位]
  */

  int b_16, b_8, b_4, b_2, b_1, b_0;
  int sign, cond;
  /**
   * x < 0 ? ~x : x 
   * see: 
   *   conditional - same as x ? y : z 
  */
  sign = (x >> 31) & 1;
  cond = (sign << 0x1F) >> 0x1F;
  x = (cond & ~x) | (~cond & x);

  b_16 = (!!(x >> 16)) << 4;
  x >>= b_16;
  b_8 = (!!(x >> 8)) << 3;
  x >>= b_8;
  b_4 = (!!(x >> 4)) << 2;
  x >>= b_4;
  b_2 = (!!(x >> 2)) << 1;
  x >>= b_2;
  b_1 = (!!(x >> 1)) << 0;
  x >>= b_1;
  b_0 = x;

  return b_0 + b_1 + b_2 + b_4 + b_8 + b_16 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /**
   * 返回浮点参数 f 等同于表达式 2*f 的位级表示.
   * 所有参数和返回值都依照 unsigned int 来传输，但是它们需要被解释为单精度浮点数的位级表示.
   * 当参数为 NaN 时，返回原参数值.
   *
   * 可以用逻辑运算符和循环，可以使用 signed int/unsigned int
  */

  

  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
