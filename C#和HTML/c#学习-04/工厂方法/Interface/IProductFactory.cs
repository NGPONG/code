using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using 简单工厂.Interface;

namespace 简单工厂.Interface
{
    public interface IProductFactory
    {
        IProduct CreateProduct();
    }
}
