#include <iostream>
#include <string>
#include <set>

#include "kwmsgshare.pb.h"

std::string foo() 
{
  std::string str = "hello,world!";
  return str;
}

void foo_2(std::string& str) {
  
}

int main(void) {
  // KWMsg::ProductInfo product;
  // product.set_product_id("product_id_1");
  // product.set_shop_id("shop_id_1");
  // product.set_shop_goods_id("shop_goods_id_1");

  const std::string& str = foo();
  std::cout << str << std::endl;

  return EXIT_SUCCESS;
}
