using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统
{ 
    public class Commodity 
    {
        public int Price
        {
            get;
            set;
        }

        public string Name
        {
            get;
            set;
        }
        public string Id
        {
            get;
            set;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="price">商品价格</param>
        /// <param name="name">商品名称</param>
        /// <param name="id">商品编码</param>
        public Commodity(int price,string name,string id) 
        {            
            this.Price = price;
            this.Name = name;
            this.Id = id;
        }
    }
}
