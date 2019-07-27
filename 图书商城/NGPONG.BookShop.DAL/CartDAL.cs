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

        public void UpdateCart(string userId, string bookId, int qty)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@UserId",userId),
                new SqlParameter("@BookId",bookId),
                new SqlParameter("@qty",qty)
            };

            SqlHelper.ExecuteNonQuery("update cart set count = @qty where UserId = @UserId and BookId = @BookId", parms);
        }

        public void DeleteCart(string UserId, string BookId)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@UserId",UserId),
                new SqlParameter("@BookId",BookId)
            };

            SqlHelper.ExecuteNonQuery("delete from cart where userid = @UserId and bookid = @BookId", parms);
        }

        public DataTable SelectCartByUserId(string UserId)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@UserId",UserId)
            };

            return SqlHelper.GetDataTable("select b.ISBN,b.Title,b.Title,b.Id,a.Count,b.UnitPrice from Cart a left join Books b on a.BookId = b.Id where a.UserId = @UserId", parms);
        }
    }
}
