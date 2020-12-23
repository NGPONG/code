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
    public class ComputerFactory : IProductFactory
    {
        public IProduct CreateProduct()
        {
            return new Computer();
        }
    }
}
