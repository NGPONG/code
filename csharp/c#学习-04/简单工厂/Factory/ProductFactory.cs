using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using 简单工厂.Interface;
using 简单工厂.Pro;

namespace 简单工厂.Factory
{
    public static class ProductFactory
    {
        /// <summary>
        /// 工厂静态实例，负责产出产品并交到客户手上
        /// </summary>
        /// <param name="productName"></param>
        /// <returns></returns>
        public static IProduct GetProductObj(string productName)
        {
            IProduct product;
            switch (productName)
            {
                case "Computer":
                    product = new Computer();
                    break;
                // case…
                default:
                    product = null;
                    break;
            }
            return product;
        }
    }
}
