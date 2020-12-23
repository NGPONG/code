using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 简单工厂.Factory;
using 简单工厂.Interface;

namespace 工厂方法
{
    class Program
    {
        static void Main(string[] args)
        {
            // 构建工厂
            IProductFactory productFactory = new ComputerFactory();
            // 获取产品
            IProduct product = productFactory.CreateProduct();

            product.SaleProduct();
        }
    }
}
