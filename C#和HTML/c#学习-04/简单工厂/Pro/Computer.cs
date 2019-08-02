using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 简单工厂.Interface;

namespace 简单工厂.Pro
{
    /// <summary>
    /// 工厂产品的实例成员
    /// </summary>
    public class Computer : IProduct
    {
        private string _productName;
        public string ProductName
        {
            get { return _productName; }
            set { this._productName = value; }
        }

        public void SaleProduct()
        {
            // do....
        }
    }
}
