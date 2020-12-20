package main

import (
  "fmt"
  "os"
  "strings"
  "bufio"
)

func _05() {
  count_arr := make(map[string]int);
  files := os.Args[1:] /* maybe input some filename in process args */

  if len(files) > 0 {
    for _, file := range files {
      f, err := os.Open(file)

      fmt.Println(file)
      if err != nil {
        fmt.Printf("open file [%s] error\n", file)
        continue
      }
      count_lines(f, count_arr)
      f.Close()
    }
  } else {
    count_lines(os.Stdin, count_arr)
  }

  for key, val := range count_arr {
    if val > 1 {
      fmt.Printf("[%s]: %d\n", key, val)
    }
  }
}
func count_lines(f *os.File, count_arr map[string]int) {
  input := bufio.NewScanner(f)
  for input.Scan() {
    count_arr[input.Text()] += 1
  }
}

/**
 * @brief 
 *  1. make 的用法，用来构造一个 map
 *  2. map 键值对集合的使用方式
 *  3. range for 循环的使用
 *  4. bufio 的使用
*/
func _04() {
  count_arr := make(map[string]int);
  input := bufio.NewScanner(os.Stdin);

  for input.Scan() {
    count_arr[input.Text()] += 1;
  }

  for key, val := range count_arr {
    if val > 1 {
      fmt.Printf("[%s]: %d\n", key, val)
    }
  }
}

/**
 * @brief 
 *  1. string.join 的使用
*/
func _03() {
  msg := "hello,world"

  fmt.Println(msg);
  fmt.Println(strings.Join(os.Args[1:], ","));
}

/**
 * @brief 
 *  1. 短变量声明的使用
 *  2. 空标识符的使用
*/
func _02() {
  /* 短变量声明适用于函数体内的变量声明，并不适合包级别的变量 */
  s, msg := "", "hello,world"

  /* _ 空标识符，用于接受无用的 range */
  for _, arg := range os.Args[1:] {
    s += "," + arg;
  }

  fmt.Println(msg);
  fmt.Println(s);
}

/**
 * @brief 
 *  1. 显式变量的初始化
*/
func _01() {
  /* 显式变量类型的初始化，能够告知初始化变量的重要性 */
  var s, msg string;
  msg = "hello,world";

  for i := 1; i < len(os.Args); i++ {
    s += "," + os.Args[i]
  }

  fmt.Println(msg);
  fmt.Println(s);
}

func main() {
  _05();
}
