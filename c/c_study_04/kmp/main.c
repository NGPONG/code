#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* @brief 构造前缀表 */
void prefix_table(char *str, int *prefix, int n) {
  prefix[0] = 0; /* 下标为0的prefix始终为0 */

  int len = 0;
  int i = 1;
  while (i < n) {
    /**
     * len 作为上一个字符的最大公共前后缀长度，它的值
     * 在字符串 str 串中所指向的值，其实就是作为，如果
     * 下一个字符是该值的话，那么就意味着下一个字符继续
     * 连接着上一个字符所形成的公共前后缀，那么所对应的
     * len 就继续 +1
    */
    if (str[i] == str[len]) {
      ++len;
      prefix[i] = len;
      ++i;
    } else { /* 否则的话，那么就让当前 len 指向已构造前缀表的上一个为止，直至减到 0 为止 */
             /* 事实上，这段代码主要是为了解决串中最后一位无法使用通常手段(进入else条件的话
              * 就意味着当前下标的 prefix 直接为 0 即可)来完成所加的，而所构造的前缀表最终
              * 还要右移一位，并且第 0 为赋值为 -1 以保证在 kvm 算法中能够更方便的计算 */
      if (len > 0) {
        len = prefix[len - 1];
      } else {
        prefix[i] = len;
        i++;
      }
    }
  }

  for (size_t i = n - 1; i > 0; --i) {
    prefix[i] = prefix[i - 1];
  }
  prefix[0] = -1;
}

void kmp(char *str_src, char *partten, int *prefix, int n) {
  
}

int main(int argc, char *argv[]) {
  char *str = "ABABCABAA";
  int str_len = strlen(str);

  int prefix[str_len];
  memset(prefix, 0x0, sizeof(prefix));

  prefix_table(str, prefix, str_len);

    

  for (size_t i = 0; i < sizeof(prefix) / sizeof(int); ++i) {
    printf("%d\n", prefix[i]);
  }

  return EXIT_SUCCESS;
}
