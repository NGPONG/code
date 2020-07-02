using NGPONG.BookShop.Common.Helper;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.DAL
{
    public class OrderDAL
    {
        public DataTable AddOrderBill(string address, string userId)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@address",address),
                new SqlParameter("@userId",userId),
                new SqlParameter("@Module","SO")
            };

            return SqlHelper.GetDataTablProc("p_AddOrderBillData", parms);
        }
    }
}
