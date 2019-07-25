using NGPONG.BookShop.DAL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class CartService
    {
        public void AddCart(dynamic cartExpando)
        {
            new CartDAL().AddCart(cartExpando);
        }
    }
}
