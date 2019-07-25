using NGPONG.BookShop.Common.Helper;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.DAL
{
    public class CartDAL
    {
        public void AddCart(dynamic cartExpando)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@UserId",cartExpando.UserId),
                new SqlParameter("@BookId",cartExpando.BookId),
                new SqlParameter("@Count",cartExpando.Count)
            };

            StringBuilder sql = new StringBuilder();
            sql.AppendLine("if exists(select 1 from Cart where UserId = @UserId and BookId = @BookId)");
            sql.AppendLine("    update cart set count = count + convert(int,@Count) where UserId = @UserId and BookId = @BookId");
            sql.AppendLine("else");
            sql.AppendLine("    insert into cart(UserId,BookId,Count,CreateDate) values(@UserId,@BookId,@Count,GETDATE())");

            SqlHelper.ExecuteNonQuery(sql.ToString(), parms);
        }
    }
}
