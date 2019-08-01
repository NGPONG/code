using NGPONG.BookShop.DAL;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class OrderService
    {
        public DataTable AddOrderBill(string address, string userId)
        {
            return new OrderDAL().AddOrderBill(address, userId);
        }
    }
}
