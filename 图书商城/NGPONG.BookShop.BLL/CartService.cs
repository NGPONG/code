using NGPONG.BookShop.DAL;
using System;
using System.Collections.Generic;
using System.Data;
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

        public DataTable SelectCartByUserId(string UserId)
        {
            return new CartDAL().SelectCartByUserId(UserId);
        }

        public void DeleteCart(string UserId, string BookId)
        {
            new CartDAL().DeleteCart(UserId, BookId);
        }

        public void UpdateCart(string UserId, string BookId, int qty)
        {
            new CartDAL().UpdateCart(UserId, BookId, qty);
        }
    }
}
