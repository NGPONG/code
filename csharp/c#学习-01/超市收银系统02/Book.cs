using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
    public class Book:Cargo
    {
        public Book(string name, string id, double price)
            : base(name, id, price) 
        {
        
        }
    }
}
