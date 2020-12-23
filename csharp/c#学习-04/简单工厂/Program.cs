using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 简单工厂.Factory;
using 简单工厂.Interface;

namespace 简单工厂
{
    /// <summary>
    /// 客户
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            // 客户通过工厂向工厂提取产品
            IProduct product = ProductFactory.GetProductObj("Computer");

            product.SaleProduct();
        }
    }
}
